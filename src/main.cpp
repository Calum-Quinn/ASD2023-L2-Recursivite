/* -----------------------------------------------------------------------------------
Nom du fichier : main.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 07.03.2023
Description    : Programme trouvant les solutions au jeu Mini Logix
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include <iostream>
#include "pieces.h"
#include "deplacer.h"
#include "Carte.h"
#include "controle.h"
#include "jeu.h"

using namespace std;

using Cartes = vector<Carte>;

int main() {

    Pieces pieces = PIECES;

    //Vecteur contenant chaque pièce du puzzle
    Cartes cartes;
    cartes.reserve(PIECES.size());
    vector<unsigned> positions = {1,2,3,4,5,6,7,8,9};

    //Création du plateau de jeu
    for(size_t i = 0; i < PIECES.size(); ++i){
        cartes.push_back(Carte (i + 1, PIECES[i]));
        //cartes[i] = (Carte(i+1, PIECES[i]));
    }

    cartes[0].tourner();
    cartes[0].tourner();
    cartes[0].tourner();
    cartes[1].tourner();

//    for(size_t i = 0; i < 6; ++i){
//        cartes[0].tourner();
//        cout << cartes[0] << endl;
//    }

    for(Carte carte : cartes){
        cout << carte << endl;
    }
//
//    deplacer(cartes[0], cartes[1]);
//    cout << endl << endl;
//
//    for(Carte carte : cartes){
//        cout << carte << endl;
//    }
    cout << boolalpha << controle(cartes,cartes[1],GAUCHE);

    vector<Carte> resultat =  pasDefini(cartes,cartes[0],positions,0);

    for(Carte carte : resultat){
        cout << carte << endl;
    }

    return 0;
}