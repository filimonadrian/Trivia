#include "header.h"

void printTitle ( WINDOW *win) {
    // printare titlu citit din fisier
    FILE *in;
    int i = 1;
    char buffer[40];
    in = fopen("asciiArt", "r");
    while ( fgets(buffer,40,in) != NULL ){
      mvwprintw(win,i,80,buffer);
      i++;
    }
    fclose(in);
    wrefresh(win);
}

//actualizeaza tutorialul
void updateTutorial (WINDOW *win){
    mvwprintw ( win, 2, 25, "Apasa U pentru a pune alt raspuns");
    mvwprintw ( win, 4, 25, "Apasa Q pentru a reveni la meniu");
    mvwprintw ( win, 6, 25, "Apasa R pentru a reseta highscore-ul");
    mvwprintw ( win, 8, 25, "Apasa S pentru a trece peste intrebare");
    mvwprintw ( win, 10, 25, "Apasa F pentru 50/50");
    mvwprintw ( win, 12, 25, "Apasa A pentru raspunsul A");
    mvwprintw ( win, 14, 25, "Idem pentru orice varianta de raspuns");
    wrefresh ( win );

}
//actualizeaza help-ul
void updateHelp (WINDOW *win){

    mvwprintw ( win, 2, 8, "Raspunde cu litere mici sau mari");
    mvwprintw ( win, 4, 8, "Nu apasa ENTER daca nu ai pus raspunsul");
    mvwprintw ( win, 6, 8, "Daca ai introdus o tasta din greseala");
    mvwprintw ( win, 8, 8, "Apasa tasta U sau u");
    mvwprintw ( win, 10, 8, "Introdu tasta pe care o doresti");
    mvwprintw ( win, 12, 8, "Poti repeta operatiunea de mai multe ori");
    wrefresh ( win );
}

//actualizare panou de control
void updateCpanel ( WINDOW *win, int score, int question, int wquestion, int cquestion, int highscore) {
    // actualizare panou de control
    time_t timer;
    char buffer[26];
    struct tm *tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "%d:%m:%Y  %H:%M:%S", tm_info);
    mvwprintw(win, 2, 10, "Highscore - %3d", highscore);
    mvwprintw ( win, 4, 10, "Score - %3d", score);
    mvwprintw ( win, 6, 10, "Intrebarea numarul - %2d", question);
    mvwprintw ( win, 8, 10, "Intrebari corecte - %2d", cquestion);
    mvwprintw ( win, 10, 10, "Intrebari gresite - %2d", wquestion);
    mvwprintw ( win ,12, 10, " Ora curenta : %s", buffer);
    wrefresh ( win );
}
//schimba optiunea din meniu
void changeOption ( int *row, int column, int *selection, int next, char menu_options[][50]) {
 // vechea optiune revine la font obisnuit; noua optiune va fi scrisa cu highlight
    mvaddstr( (*row) , column, menu_options[*selection-1]);
    (*row) += 2 * (next - *selection);
    *selection = next;
    attron(A_STANDOUT);
    mvaddstr( (*row), column, menu_options[*selection - 1]);
    attroff(A_STANDOUT);
}
