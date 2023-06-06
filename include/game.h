#ifndef __GAME__
#define __GAME__


/*Structure permettant de matérialiser un plateau à partir de bit*/
typedef unsigned long long Position;

/*Variable global des cases attaqué*/
extern Position tab_cases_attaquees[64];

/*Cases présente sur le plateau.*/
typedef enum {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
}Case;

/**
 * @brief Vérifie si une case est déjà occupé par une dame.
 * 
 * @param pos (Position),
 * @param c (Case)
 * @return 1 si occupé et 0 si non occupé.
 */
int est_case_occupee(Position pos, Case c);

/**
 * @brief Permet de placer ou de retirer une dame de Position. Si une dame est déjà
 * présente sur la case indiqué en paramètre, on l'a retire. Dans le cas contraire on en place une.
 * 
 * @param pos (Position *),
 * @param c (Case)
 * @return return 0 si une dame a été ajouté et 1 si une dame a été supprimé.
 */
int placer_dame_position(Position * pos, Case c);

/**
 * @brief Ajoute dans une position les points attaqué par la dame à l'emplacement 
 * de Case c, sur la diagonale gauche. (Bas droit vers haut gauche).
 * 
 * @param pos (Position),
 * @param c (Case)
 */
void attaquer_diagonal_gauche(Position *pos, Case c);

/**
 * @brief Ajoute dans une position les points attaqué par la dame à l'emplacement 
 * de Case c, sur la diagonale droite. (Bas gauche vers haut droit).
 * 
 * @param pos (Position),
 * @param c (Case)
 */
void attaquer_diagonal_droit(Position *pos, Case c);

/**
 * @brief Ajoute dans une position les points attaqué par la dame à l'emplacement 
 * de Case c, dans toutes les directions possibles.
 * 
 * @param pos (Position),
 * @param c (Case)
 */
void calculer_cases_attaquees(Position *pos, Case c);

/**
 * @brief Parcours le tableau de position (qui est une varibale gobal),
 * et ajoute dans une variable Position tout les points attaqué par une dame. 
 * 
 * @return La variable position contenant toues les cases attaqué par des dames.
 */
Position cases_attaques();

/**
 * @brief Vérifie qu'aucune dame ne s'attaque mutuellement.
 * 
 * @param pos (Position)
 * @return 1 si aucune dame ne s'attaque et 0 dans le cas contraire.
 */
int est_sans_attaque_mutuelle(Position pos);

/**
 * @brief Parcours position à fin de compter le nombre de dame placé.
 * 
 * @param pos (Position)
 * @return le nombre de dame placé.
 */
int nombre_dame_posee(Position pos);

#endif