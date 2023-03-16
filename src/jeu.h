/* -----------------------------------------------------------------------------------
Nom du fichier : jeu.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 09.03.2023
Description    : Programme lançant l'algorithme du jeu.
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L2_RECURSIVITE_JEU_H
#define ASD2022_L2_RECURSIVITE_JEU_H

#include "Carte.h"
#include <vector>

const int NB_ROTATIONS = 4;

void jouer(std::vector<Carte>& cartes, std::vector<int> positions, unsigned posCartes);

void recursif(std::vector<Carte>& cartes, std::vector<std::vector<Carte>>& solutions, size_t position,size_t posVoulu);

void recursif_new(std::vector<Carte>& cartes, std::vector<std::vector<Carte>>& solutions, size_t pos, size_t posVoulu);

void algo_rec(std::vector<Carte>& cartes, size_t n);

//std::vector<Carte> pasDefini(std::vector<Carte>& cartes, Carte& carte, std::vector<unsigned> positions, unsigned pos);

#endif //ASD2022_L2_RECURSIVITE_JEU_H
