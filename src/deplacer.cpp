/* -----------------------------------------------------------------------------------
Nom du fichier : deplacer.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 07.03.2023
Description    : Programme pour déplacer une carte dans le plateau
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include <algorithm>

#include "deplacer.h"

using namespace std;

void deplacer(Carte& carte1,Carte& carte2) {
    swap(carte1, carte2);
}