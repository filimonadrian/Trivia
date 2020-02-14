#include "header.h"

int getHighscore() {
    // obtine scorul maxim salvat in fisierul Highscore
    FILE *src;
    int x;
    src = fopen ("Highscore", "r");
    fscanf (src, "%d", &x );
    fclose(src);
    return x;

}

void updateHighscore( int highscore ) {
    // scrie scorul maxim in fisier
    FILE *src;
    src = fopen ("Highscore","w");
    fprintf(src,"%d", highscore);
    fclose(src);
}

int playGame(int *question, int *score, int *wquestion, int *cquestion){

  FILE *src;
  char c;
  char buffer[BUFMAX];
  int highscore = 0;
  highscore = getHighscore();
  int rand = 1; // pentru a vedea daca este pe randul cu raspunsul
  int column = 4; //folosita la afisarae intrebarilor
  char p; //folosita pentru a sterge imputul initial
  int skip = 0; //asigura faptul ca userul da o singura data SKIP
  int fifty = 0; //asigura faptul ca userul a dat o singura data 50/50
  int x = 5;  //pentru afisare -- la 50/50
  int test = 0; // pentru 50,50 se aduna cu 65 si verifica raspunsul corect


  /*
  int n_crt, n;
  n_crt = 0;
  n = INCR;
  buffer = (char *) malloc (n * sizeof( char )); //alocare initiala
*/


  	WINDOW * qwin, *c_panel, *title, *tutorial, *help;

//ferestrele din joc
    tutorial = newwin(18,85,10,60);
      box(tutorial, 35, 35);
      refresh();
      wrefresh(tutorial);
      updateTutorial(tutorial);

    help = newwin(18,50,10,5);
      box(help, 35, 35);
      refresh();
      wrefresh(help);
      updateHelp(help);

    title = newwin(10,0,0,0);
      printTitle(title);
      refresh();
      wrefresh(title);

    c_panel = newwin(18,50,10,150);
      box(c_panel, 35, 35);
      refresh();
      wrefresh(c_panel);
      updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore);

    qwin = newwin(20,205,30,0);
      box(qwin, 32, 35);
      refresh();
      wrefresh(qwin);

  //fisierul din care se citeste
  src = fopen("intrebari", "r");

  if (!src){
      fprintf(stderr, "Nu am putut deschide fisierul sursa!");
      return 0;
      }

	while (fgets(buffer, BUFMAX, src) != NULL){

        if (rand % 6 != 0){
            mvwprintw(qwin,column, 30 ,buffer);
            wrefresh(qwin);
            column++;
        }

          if (rand % 6 == 0)
          {

            INCORECT:

            c = getch();
            if ( c >= 97 && c <= 122 )
                  c -= 32;

            mvwprintw(qwin,10, 70,"Optiunea aleasa este: %c \n ",c);
            wrefresh(qwin);


            switch (c) {
              //se proceseaza inputul utilizatorului
              case 'A':
                  //updateQuestion(qwin, c_panel, buffer, score, question,c);

                  p = getch();
                  if ( p >= 97 && p <= 122 )
                        p -= 32;
                  if ( p == 'U'){
                    mvwprintw(qwin,10, 70,"Raspunsul dumneavoastra este: \n ");
                    wrefresh(qwin);
                    goto INCORECT;
                    break;
                  }

                  if (buffer[0] == c){
                      mvwprintw(qwin,11, 70,"Ai raspuns corect!");
                      *question = *question + 1;
                      *score += 10;
                      (*cquestion) ++;
                      //mvwprintw(qwin,12, 70,"%d %d", *question,*score);
                      updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
                      wrefresh(qwin);

                    } else{
                          mvwprintw(qwin,11, 70,"Raspuns gresit!");
                          mvwprintw(qwin,12, 70,"Raspunsul corect este: %c",buffer[0]);

                          *question = *question + 1;
                          *score -= 10;
                          (*wquestion) ++;
                          //mvwprintw(qwin,13, 70,"%d %d", *question, *score);
                          updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
                          wrefresh(qwin);
                        }

                  mvwprintw(qwin,14, 70,"Pentru a continua apasa ENTER");
                  wrefresh(qwin);
                  getch();
                  wclear(qwin);
                  box(qwin,32,35);
                  wrefresh(qwin);

              break;

              case 'B':
                  p = getch();
                  if ( p >= 97 && p <= 122 )
                        p -= 32;
                  if ( p == 'U'){
                    mvwprintw(qwin,10, 70,"Raspunsul dumneavoastra este: \n ");
                    wrefresh(qwin);
                    goto INCORECT;
                    break;
                  }
                  if (buffer[0] == c){
                      mvwprintw(qwin,11, 70,"Ai raspuns corect!");
                      *question = *question + 1;
                      *score += 10;
                      (*cquestion) ++;
                      //mvwprintw(qwin,12, 70,"%d %d", *question,*score);
                    updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
                      wrefresh(qwin);

                    } else{
                          mvwprintw(qwin,11, 70,"Raspuns gresit!");
                          mvwprintw(qwin,12, 70,"Raspunsul corect este: %c",buffer[0]);

                          *question = *question + 1;
                          *score -= 10;
                          (*wquestion) ++;
                          //mvwprintw(qwin,13, 70,"%d %d", *question, *score);
                          updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
                          wrefresh(qwin);
                        }

                  mvwprintw(qwin,14, 70,"Pentru a continua apasa ENTER");
                  wrefresh(qwin);
                  getch();
                  wclear(qwin);
                  box(qwin,32,35);
                  wrefresh(qwin);

              break;

              case 'C':
                  p = getch();
                  if ( p >= 97 && p <= 122 )
                        p -= 32;
                  if ( p == 'U'){
                    mvwprintw(qwin,10, 70,"Raspunsul dumneavoastra este: \n ");
                    wrefresh(qwin);
                    goto INCORECT;
                    break;
                  }
                    if (buffer[0] == c){
                        mvwprintw(qwin,11, 70,"Ai raspuns corect!");
                        *question = *question + 1;
                        *score += 10;
                        (*cquestion) ++;
                        //mvwprintw(qwin,12, 70,"%d %d", *question,*score);
                        updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
                        wrefresh(qwin);

                      } else{
                            mvwprintw(qwin,11, 70,"Raspuns gresit!");
                            mvwprintw(qwin,12, 70,"Raspunsul corect este: %c",buffer[0]);

                            *question = *question + 1;
                            *score -= 10;
                            (*wquestion) ++;
                            //mvwprintw(qwin,13, 70,"%d %d", *question, *score);
                            updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
                            wrefresh(qwin);
                          }

                        mvwprintw(qwin,14, 70,"Pentru a continua apasa ENTER");
                        wrefresh(qwin);
                        getch();
                        wclear(qwin);
                        box(qwin,32,35);
                        wrefresh(qwin);

              break;

              case 'D':
                  p = getch();
                  if ( p >= 97 && p <= 122 )
                        p -= 32;
                  if ( p == 'U'){
                    mvwprintw(qwin,10, 70,"Raspunsul dumneavoastra este: \n ");
                    wrefresh(qwin);
                    goto INCORECT;
                    break;
                  }
                  if (buffer[0] == c){
                      mvwprintw(qwin,11, 70,"Ai raspuns corect!");
                      *question = *question + 1;
                      *score += 10;
                      (*cquestion) ++;
                      //mvwprintw(qwin,12, 70,"%d %d", *question,*score);
                      updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
                      wrefresh(qwin);

                    } else{
                          mvwprintw(qwin,11, 70,"Raspuns gresit!");
                          mvwprintw(qwin,12, 70,"Raspunsul corect este: %c",buffer[0]);

                          *question = *question + 1;
                          *score -= 10;
                          (*wquestion) ++;
                          //mvwprintw(qwin,13, 70,"%d %d", *question, *score);
                        updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
                          wrefresh(qwin);
                        }

                  mvwprintw(qwin,14, 70,"Pentru a continua apasa ENTER");
                  wrefresh(qwin);
                  getch();
                  wclear(qwin);
                  box(qwin,32,35);
                  wrefresh(qwin);

              break;

              case 'S':
              //daca se apasa S se da SKIP
                  if ( skip == 0){
                      skip = 1;
                      goto SKIP;
                      break;
                    }else{
                      goto INCORECT;
                      break;
                    }

              case 'U':
              // U = UNDO
                mvwprintw(qwin,10, 70,"Optiunea aleasa este: \n ");
                wrefresh(qwin);
                goto INCORECT;
                break;

              case 'Q':
                return rand;

              case 'R':
              updateHighscore(0);
              highscore = 0;
              goto INCORECT;
              break;
              updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
              case 'F':
                  if(fifty < 2){
                    test = 0;
                      while ( fifty < 2 ){
                          if ( test + 65 == buffer[0] )
                              test++;
                              else
                              {
                                fifty++;
                                mvwprintw(qwin,x + test, 30 ,"--");
                                wrefresh(qwin);
                                test++;
                              }

                      }
                        goto INCORECT;
                }else{
                  goto INCORECT;
                }

                  break;

              default:
              goto INCORECT;

            }
              SKIP:
                  column = 4;
                }
                rand ++;
                if(*score > highscore){
                  highscore = *score;
                  updateHighscore(highscore);
                  updateCpanel( c_panel, *score, *question, *wquestion, *cquestion, highscore );
                }

				}

        //concluziile de la sfarsitul jocului
        erase();
        wclear(qwin);
        mvwprintw(qwin, 4 ,60,"Ai rezolvat %d intrebari!", *question);
        mvwprintw(qwin, 5 ,60,"Ai obtinut %d puncte!", *score);
        mvwprintw(qwin, 6 ,60,"Ai facut %d intrebari corecte!", *cquestion);
        mvwprintw(qwin, 7 ,60,"Ai facut %d intrebari gresite!", *wquestion);

        wrefresh(qwin);
        wgetch(c_panel);

  fclose (src);
  return rand;
}
