#include <iostream>
#include "pieces.h"
#include "deplacer.h"
#include "Carte.h"
#include "controle.h"

using namespace std;

using Cartes = vector<Carte>;

int main() {

    Pieces pieces = PIECES;

    //Vecteur contenant chaque pièce du puzzle
    Cartes cartes;
    cartes.reserve(PIECES.size());

    //Création du plateau de jeu
    for(size_t i = 0; i < PIECES.size(); ++i){
        cartes.push_back(Carte (i + 1, PIECES[i]));
        //cartes[i] = (Carte(i+1, PIECES[i]));
    }

//    for(size_t i = 0; i < 6; ++i){
//        cartes[0].tourner();
//        cout << cartes[0] << endl;
//    }

    for(Carte carte : cartes){
        cout << carte << endl;
    }

    deplacer(cartes[0], cartes[1]);
    cout << endl << endl;

    for(Carte carte : cartes){
        cout << carte << endl;
    }
}