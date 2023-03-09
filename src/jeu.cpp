/* -----------------------------------------------------------------------------------
Nom du fichier : jeu.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 09.03.2023
Description    : Algorithme du jeu.
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include "jeu.h"
#include "controle.h"
#include "deplacer.h"

using namespace std;


AControler posAControle(unsigned posCartes){
    switch(posCartes){
        case 1 :
        case 2 : return AControler::GAUCHE;
        case 3 :
        case 6 : return AControler::HAUT;
        case 4 :
        case 5 :
        case 7 :
        case 8 : return AControler::GAUCHEHAUT;
        default: return AControler::RIEN;
    }
}


void jouer(vector<Carte>& cartes, unsigned posCartes){

    if(posCartes < 9){
        cartes[posCartes].tourner();
        if(controle(cartes, cartes[posCartes], posAControle(posCartes))){
            jouer(cartes, posCartes + 1);
        }

        jouer(cartes, posCartes + 1);
    }
}

vector<Carte> pasDefini(vector<Carte>& cartes, Carte& carte, unsigned pos) {
    AControler controler;
    switch(pos){
        case 1 :
        case 2 : controler = GAUCHE;
        case 3 :
        case 6 : controler = HAUT;
        case 4 :
        case 5 :
        case 7 :
        case 8 : controler =GAUCHEHAUT;
        default: controler = RIEN;
    }
    if (controler)
        controle(cartes, carte, controler);
    else
        return pasDefini(cartes,cartes[carte.getPosition() + 1],pos);
}