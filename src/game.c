#include "../include/game.h"

Position tab_cases_attaquees[64];

/*Verifie si une case est occupé.*/
int est_case_occupee(Position pos, Case c) {
    /*return 1 si la case est occupé*/
    if(pos & (1ULL << c))
        return 1;
    /*0 si non occupé*/
    return 0;
}

/*Place ou retire une dame*/
int placer_dame_position(Position * pos, Case c) {
    /*si une dame est déjà présente on la retire*/
    if(est_case_occupee(*pos, c)){
        *pos = (~(1ULL << c) & *pos);
        return 1;/*il est occupé par une dame, on return 1*/
    }

    *pos = ((1ULL << c) | *pos);
    return 0;/*il n'est pas occupé par une dame, on return 0*/
}

/*Calcul les cases attaqué par la dame de position c.*/
void attaquer_diagonal_gauche(Position *pos, Case c) {
    /*Cases de la diagonale qui sont suppérieur à c.*/
    for(int i = 0; i < 8; i++) {
        if(c + i * 7 != c)
            placer_dame_position(pos, c + i * 7);

        /*Lorsque on sort du plateau on quitte la boucle*/
        if(!((c + i * 7) % 8) || (c + i * 7) >= 56)
            break;
    }
    /*Cases de la diagonale qui sont inférieur à c.*/
    for(int i = 0; i < 8; i++) {
        if(c - i * 7 != c)
            placer_dame_position(pos, c - i * 7);

        /*Lorsque on sort du plateau on quitte la boucle*/
        if(!((c - i * 7 + 1) % 8) || (c - i * 7) < 8)
            break;
    }
}


void attaquer_diagonal_droit(Position *pos, Case c) {
    /*Cases de la diagonale qui sont suppérieur à c.*/
    for(int i = 0; i < 8; i++) {
        if(c + i * 9 != c)
            placer_dame_position(pos, c + i * 9);

        /*Lorsque on sort du plateau on quitte la boucle*/
        if(!((c + i * 9 + 1) % 8) || (c + i * 9)  >= 56) {
            break;
        }
    }
    /*Cases de la diagonale qui sont inférieur à c.*/
    for(int i = 0; i < 8; i++) {
        if(c - i * 9 != c)
            placer_dame_position(pos, c - i * 9);

        /*Lorsque on sort du plateau on quitte la boucle*/
        if(!((c - i * 9) % 8) || (c - i * 9) <= 8)
            break;
    }
}

void calculer_cases_attaquees(Position *pos, Case c){
    int temp = c / 8;/*pour obtenir le premiere case de la ligne de ce case*/

    for(int i = 0; i < 8; i++){
        /*Colonne */
        /* Cases au dessus de c.*/
        if((c + i * 8 < 64 && c < c + i *8)){/*pour ganrantir le case n'est pas dehor le plateau*/
            placer_dame_position(pos, c + i * 8);
        }
        /* Cases en dessous de c.*/
        if(c - i * 8 >= 0 && c > c - i *8){
            placer_dame_position(pos, c - i * 8);
        }
        /*Ligne */
        if(c!= temp * 8 + i)
            placer_dame_position(pos, temp * 8 + i);
    }
    /* Diagonales */
    attaquer_diagonal_gauche(pos, c);
    attaquer_diagonal_droit(pos, c);
}

/*Cacul dans une variable position les cases attaqué à partir
 de la variable global tab_cases_attaques*/
Position cases_attaques(){
    Position attaques = 0;
    for(int i = 0; i < 64; i++){
        attaques = attaques | tab_cases_attaquees[i];
    }
    return attaques;
}
/*verifie que aucune dame ne s'attaques mutuellement.*/
int est_sans_attaque_mutuelle(Position pos) {
    /*attaques contient les cases attaqué par toutes les dames.*/
    Position attaques = cases_attaques();
    if((attaques & pos) == 0)
        return 1;
    return 0;
}

/*Calcul le nombre de dame posée.*/
int nombre_dame_posee(Position pos){
    int cpmt = 0;
    for(int i = 0; i < 64; i++){
        if(pos & (1ULL<<i))
            cpmt++;
    }
    
    /*Return le nombre de dame.*/
    return cpmt;
}