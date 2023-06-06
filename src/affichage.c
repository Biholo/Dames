#include "../include/affichage.h"

/*Affiche les positions dans le terminal*/
void afficher_position(Position pos){
    for(int i = 7; i >= 0; i--){
        for(int j = 0; j < 8; j++){
            //Si le bit est à 1 on affiche un +
            if(pos & (1ULL << ((i*8) + j)))
                printf("+ ");
            //Si le bit est à 0 on affiche un .
            else
                printf(". ");
        }
        printf("\n");
    }
}

/*Affiche un case du plateau*/
void affiche_case(int x, int y, int select, char c) {
    int color;
    if(select){
        //Si la case est attaquée color = select = 1 = Rouge;
        color = select;
    } else {
        /*On alterne les couleurs des cases pour constituer le damier.*/
        if((x + y) % 2 == 1)
            color = 3;
        else
            color = 2;
    }
    /*On attribut la bonne couleur à la case*/
    attron(COLOR_PAIR(color));
    for(int i = y * 3; i < 3 + y * 3; i++){
        for(int j = 0 + x * 5; j < 5 + x * 5; j++){
            if( i == 1 + y * 3 && j == 2 + x * 5) 
                mvprintw(i, j, "%c", c);
            else
                mvprintw(i, j, " ");
        }
    }
    attroff(COLOR_PAIR(color));
}

/*Affiche le plateau entièrement*/
void afficher_plateau(Position pos, Position atq){
    int est_atq = 0;
    for(int i = 7; i >= 0; i--){
        for(int j = 0; j < 8; j++){
            /*Verification si la case est une case 'attaquée'.*/
            if(atq & (1ULL<<((i*8)+j)))
                est_atq = 1;
            else
                est_atq = 0;
            //Affichage de la case avec une dame
            if(pos & (1ULL<<((i*8)+j)))
                affiche_case(j, 7 - i, est_atq, 'D');
            //affichage d'une case sans dame
            else
                affiche_case(j, 7 - i, est_atq, ' ');
        }
    }
    
    /*On masque le message d'erreur*/
    mvprintw(25, 0, "                                           ");
    refresh();
}

/*Retourne les coordonnées d'une case celon le clic*/
int clic_vers_case(int clic_x, int clic_y){
    //Return -1 si le clic n'est pas dans le plateau.
    if(clic_x >= 40 || clic_y >= 24)
        return -1;

    /*On calcul la case celon les coordonnées*/
    int x = clic_x / 5;
    int y = clic_y / 3;
    int nb = (56 - (y * 8)) + x;
    
    return nb;
}
