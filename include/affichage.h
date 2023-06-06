#ifndef __AFFICHAGE__
#define __AFFICHAGE__

#include <stdio.h>
#include <ncurses.h>

#include "game.h"

/**
 * @brief   Affiche dans le terminal les positions des dames sur le plateau.
 * 
 * @param pos (Position),
 */
void afficher_position(Position pos);

/**
 * @brief Afffiche une dame à la case de coordonnées x et y.
 * Select prend l'information de si la case est 'attaqué' par une dame.
 * 
 * @param x (int) Coordonnée en x de la case
 * @param y (int) Coordonnée en y de la case
 * @param select (int) 1 si la case est attaqué si non 0
 * @param c (char)
 */
void affiche_case(int x, int y, int select, char c);

/**
 * @brief Affiche le plateau de jeu. En prennant en compte l'emplacement des dames
 * et des cases attaquées.
 * 
 * @param pos (Position)
 * @param atq (Position)
 */
void afficher_plateau(Position pos, Position atq);

/**
 * @brief Prend en paramètre les coordonnées d'une clic
 * et return la position d'une case si le clic est sur plateau.
 * 
 * @param clic_x (int)
 * @param clic_y (int)
 * @return la case que les coordonnées vise et 
 *  -1 si la case n'est pas sur le plateau 
 */
int clic_vers_case(int clic_x, int clic_y);



#endif