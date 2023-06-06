#include "../include/game.h"
#include "../include/affichage.h"

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>



int main(void){
    MEVENT ev;
    Position pos = 0;
    Position attaque = 0;
    int touche;
    int clic_case;

    initscr();
    /*Initialisation des couleur.*/
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);

    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, FALSE);
    curs_set(FALSE);
    noecho();
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    afficher_plateau(pos, attaque);
    /*tant que 8 dames n'ont pas été posé on continue*/
    while (nombre_dame_posee(pos) != 8) {
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
            /*On récupère le clic et on le convertit en une case*/
            clic_case = clic_vers_case(ev.x, ev.y);
            
            /*On vérifie que le clic soit sur le plateau.*/
            if(clic_case != -1){
                /*On place la dame et on calcul les positions qu'elle attaque*/
                placer_dame_position(&pos, clic_case);   
                calculer_cases_attaquees(&tab_cases_attaquees[clic_case], clic_case);
                attaque = cases_attaques();
                //Puis on affiche le plateau
                afficher_plateau(pos, attaque);
            }
            /*Si le clic n'est pas dans le plateau on affiche une erreur.*/
            else{
                mvprintw(25, 0, "Veuillez sélectionner une case du plateau!");
            }
        }
    }
    clear();
    /*Affichage de fin.*/
    if(est_sans_attaque_mutuelle(pos))
        mvprintw(11, 15, "Victoire !");
    else
        mvprintw(12, 15, "Défaite.");
    refresh();
    getch();
    endwin();
    return 0;
}
