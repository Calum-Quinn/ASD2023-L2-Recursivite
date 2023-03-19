/* -----------------------------------------------------------------------------------
Nom du fichier : controle.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 09.03.2023
Description    : Programme qui contrôle si deux cartes correspondent
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L2_RECURSIVITE_CONTROLE_H
#define ASD2022_L2_RECURSIVITE_CONTROLE_H

#include "Carte.h"

enum AControler {RIEN,GAUCHE,HAUT,GAUCHEHAUT};

const unsigned  DESSUS = 0,
                ADROITE = 1,
                DESSOUS = 2,
                AGAUCHE = 3;

/**
     * @name            : controle
     *
     * @but             : Contrôler si une carte peut aller à un endroit désigné
     *
     * @param plateau   : Vecteur servant de zone de test pour les différentes permutations
     * @param posVoulu  : Position à laquelle on veut mettre la carte à controlée
     * @param carte     : Carte qu'on veut contrôlée
     * @param rotation  : Rotation actuel de la carte
     * @param controler : Valeur désignant quels côtés controler selon la position voulu
     * @return          : Booléen confirmant si la carte va à l'endroit voulu
     * @throws          : NIL
     */
bool controle(std::vector<Carte>& plateau, size_t posVoulu, Carte& carte, int rotation, AControler controler);

/**
     * @name            : check
     *
     * @but             : Contrôler si deux cartes correspondent selon leur état actuel
     *
     * @param plateau   : Vecteur servant de zone de test pour les différentes permutations
     * @param posVoulu  : Position à laquelle on veut mettre la carte à controlée
     * @param carte     : Carte qu'on veut contrôlée
     * @param monCote   : Identificateur du côté de la carte à contrôler
     * @param sonCote   : Identificateur du côté de l'autre carte à contrôler
     * @param rotation  : Rotation actuel de la carte
     * @return          : Booléen confirmant si les deux cartes vont ensembles
     * @throws          : NIL
     */
bool check(std::vector<Carte>& plateau, size_t posVoulu, Carte& carte, const int monCote, const int sonCote, int rotation);

#endif //ASD2022_L2_RECURSIVITE_CONTROLE_H