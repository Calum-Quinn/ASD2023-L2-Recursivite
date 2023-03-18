/* -----------------------------------------------------------------------------------
Nom du fichier : Carte.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 07.03.2023
Description    : Programme pour une classe qui défini les pièces du jeu
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include "Carte.h"

#include <algorithm>

using namespace std;

Carte::Carte(const int id, Piece motifs) {
    this->id = id;
    this->rotation = 'a';
    this->rot = 0;
    this->motifs = motifs;
//    this->position = 9;
    this->position = id - 1;
}

Carte::Carte(const Carte& autre) : position(autre.position){
    *this = autre;
}

void Carte::tourner(){
    //On augmente une valeur represantant la rotation de sorte à pouvoir réinitialiser le plateau
    rot = ++rot % 4;
}

void Carte::rotate() {
   //AttachementType tmp = motifs.back();/*on le mémorise avant qu'il ne disparaisse écrasé par table[1]*/

   //for(size_t i = 0; i < motifs.size(); ++i)
    //  motifs[i] = motifs[i+1];
   std::rotate(motifs.rbegin(), motifs.rbegin() + 1, motifs.rend());

   if(rotation == 'd')
      rotation = 'a';
   else{
      ++rotation;
   }

   //for(size_t i = 0; i > 0; --i)
   //   motifs[i] = motifs[i - 1];
  // motifs.front() = tmp;

}

void Carte::reset() {
    rot = 0;
    position = id - 1;
}

Carte& Carte::operator= (const Carte& autre) {
    this->motifs = autre.motifs;
    this->rotation = autre.rotation;
    this->rot = autre.rot;
    this->id = autre.id;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Carte& carte){

    os << "id " << carte.getId() << " : " ;
    for (size_t i = 0; i < carte.motifs.size(); ++i) {
        os << carte.motifs[i] << " ";
    }
    os << "rotation :" << carte.rot << " position :" << carte.position << endl;

    return os;
}