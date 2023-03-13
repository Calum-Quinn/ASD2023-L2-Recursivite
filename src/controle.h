/* -----------------------------------------------------------------------------------
Nom du fichier : controle.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 09.03.2023
Description    : Programme principal
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

bool controle(std::vector<Carte>& cartes, size_t posMoi, size_t posLui, AControler controler);

bool check(Carte& carte1, Carte& carte2, const int moi, const int lui);

#endif //ASD2022_L2_RECURSIVITE_CONTROLE_H