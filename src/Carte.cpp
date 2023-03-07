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