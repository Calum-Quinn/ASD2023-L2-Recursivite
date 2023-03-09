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

Carte::Carte(const int id, Piece motifs) : id(id), position(id-1){
    this->rotation = 'a';
    this->motifs = motifs;
    //this->position = size_t(id - 1);
};

Carte::Carte(const Carte& autre) : position(autre.position){
    *this = autre;
}

void Carte::tourner(){
    rotate(this->motifs.begin(),this->motifs.begin() + 1,this->motifs.end());

    if(this->rotation == 'd'){
        this->rotation = 'a';
    }else{
        ++this->rotation;
    }
}

Carte& Carte::operator= (const Carte& autre) {
    this->motifs = autre.motifs;
    this->rotation = autre.rotation;
    this->id = autre.id;
    //this->position = autre.position;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Carte& carte){

    os << "id " << carte.getId() << " : " ;
    for (size_t i = 0; i < carte.motifs.size(); ++i) {
        os << carte.motifs[i] << " ";
    }
    os << carte.rotation << " " << carte.position << endl;

    return os;
}