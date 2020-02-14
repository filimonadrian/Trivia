#include "header.h"

/*
void putInMyFile(int argc, char *argv[]){
  FILE *src,*dest;
  int i;

  char buffer[BUFMAX];

  dest = fopen("iau_intrebari", "w+");

  if (!dest){
      fprintf(stderr, "Eroare! Nu am putut deschide fisierul destinatie!\n");
      return;
  }

  for (i = 1; i < argc; ++i)
  {
      src = fopen(argv[i], "r");
          if (!src){
              fprintf(stderr, "Nu am putut deschide fisierul sursa (%d)!\n", i);
              return;
              }

  						while (fgets(buffer, BUFMAX, src) != NULL){
                      fputs(buffer,dest);
  									}
      fclose(src);

  }
  fclose(dest);

}
*/


void drawMenu(char menu_options[][50]) {
    //desenare meniu
    int current_row, current_column;
    int i=0;
    clear();
    printTitle(stdscr);
    current_row = 18; current_column = 18;
    for (i = 1; i <= 2; i++)	{
        mvaddstr (current_row, current_column, menu_options[i] );
        current_row += 2;
    }
    attron(A_STANDOUT);
    mvaddstr ( 16 , current_column, menu_options[0] );
    attroff(A_STANDOUT);
    //scrie optiunile disponibile, prima va fi cea selectata
    refresh();
}

void navigateMenu ( char menu_options[][50] ){ //,int argc, char *argv[]
    //navigare prin meniul principal
    // primeste ca parametru numele optiunilor
    //numarul si numele fisierelor

    int selection = 1, row = 16, column = 18;
    int game_started = 0;
    int score = 0, question = 1;
    int wquestion = 0; //intrebare gresita
    int cquestion = 0; //intrebare corecta


    wchar_t C;
    C = getch();


    while ( C != 'q' ) {
        switch ( C ) {
            case (KEY_UP) :
                //tasta UP_ARROW apasata in meniu, duce selectia curenta cu o pozitie in sus
                if ( selection == 1 ) {
                    changeOption( &row, column, &selection, 3, menu_options);
                }
                else {
                    if ( selection == 3 && game_started == 0 )
                        changeOption(&row, column, &selection, 1, menu_options);
                    else
                        changeOption(&row, column, &selection, selection-1, menu_options);
                }
                break;
            case ( KEY_DOWN ) :
                //tasta UP_ARROW apasata in meniu, duce selectia curenta cu o pozitie in jos
                if ( selection == 3 ) {
                    changeOption( &row, column, &selection, 1, menu_options);
                }
                else {
                    if (game_started == 0 )
                        //daca niciun joc nu este in desfasurare, optiunea "resume" este indisponibila
                        changeOption( &row, column, &selection, 3, menu_options);
                    else
                        changeOption( &row, column, &selection, selection + 1, menu_options);
                }
                break;
            case 10 :
                clear();
                //se apasa tasta ENTER
                switch ( selection ) {
                    case 1 :
                        //se porneste un joc nou, toate variabilele se reinitializeaza
                        game_started = 1;
                        score = 0;
                        question = 0;
                        wquestion = 0;
                        cquestion = 0;
                        clear();
                        refresh();

                        game_started = playGame( &question, &score, &wquestion, &cquestion );
                        drawMenu ( menu_options );
                        selection = 1;
                        row  = 16;
                        break;
                    case 2 :
                        // se continua jocul din ultimul punct
                        clear();
                        refresh();
                        game_started = playGame( &question, &score, &wquestion, &cquestion );
                        
                        drawMenu(menu_options);
                        selection = 1;
                        row = 16;
                        break;
                    case 3 :
                        return;
                }
            default : break;
        }
        refresh();
        C = getch();
    }
}

int main ( int argc, char * argv[] ){


  //putInMyFile( argc, *argv[] );

 FILE *src,*dest;
  int i;

  char buffer[BUFMAX];

  dest = fopen("intrebari", "w+");

  if ( argc == 0 ){
    fprintf(stderr, "Eroare! Nu s-au dat argumente!\n");
    return 1;
  }

  if (!dest){
      fprintf(stderr, "Eroare! Nu am putut deschide fisierul destinatie!\n");
      return 1;
  }

  for (i = 1; i < argc; ++i)
  {
      src = fopen(argv[i], "r");
          if (!src){
              fprintf(stderr, "Nu am putut deschide fisierul sursa (%d)!\n", i);
              return 1;
              }

  						while (fgets(buffer, BUFMAX, src) != NULL){
                      fputs(buffer,dest);
  									}
      fclose(src);

  }
  fclose(dest);

  char menu_options[4][50];
  strcpy (menu_options[0] , "New Game");
  strcpy (menu_options[1] , "Resume");
  strcpy (menu_options[2] , "Exit" );
  WINDOW * screen ;
	screen = initscr();
  cbreak();
  noecho();
  keypad(screen , TRUE);
  curs_set(0);
  clear();
  drawMenu( menu_options );
  navigateMenu ( menu_options );
  curs_set(1);
  endwin();

return 1;
}
