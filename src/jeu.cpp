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


//void jouer(vector<Carte>& cartes, vector<int> positions, unsigned posCartes){
//
//    if(posCartes < 9){
//        cartes[posCartes].tourner();
//        if(controle(cartes, cartes[posCartes], posAControle(posCartes))){
//            jouer(cartes, positions, posCartes + 1);
//        }
//
//        jouer(cartes, positions, posCartes + 1);
//    }
//}

void recursif(vector<Carte>& cartes, vector<vector<Carte>>& solutions, size_t position, size_t posVoulu) {


    static int i = 0;

    //Soustraire les cartes déjà placées, selon leur position, du vecteur de cartes qu'on passe en paramètres


    AControler controler;
    switch(carte.getPosition()){
        case 1 :
        case 2 : controler = GAUCHE; break;
        case 3 :
        case 6 : controler = HAUT; break;
        case 4 :
        case 5 :
        case 7 :
        case 8 : controler =GAUCHEHAUT; break;
        default: controler = RIEN;
    }
    //La carte peut aller là
    if (controle(cartes, carte, controler)) {
        //La carte est à la dernière position
        if(position == cartes.size() - 1) {
            //Ajouter le vecteur au vecteur de solutions
            solutions.push_back(cartes);
        }
        //La carte n'est pas à la dernière position
        else {
            //Passer à la prochaine position
            recursif(cartes, solutions, position + 1, posVoulu);

        }
    }
    //La carte ne peut pas aller là
    else {
        //Carte tourné 4 fois
        if(carte.getRot() == 3) {
            //Il reste des cartes
            if(position != cartes.size() - 1) {
                //Prendre la prochaine carte et réessayer
                recursif(cartes, solutions, position + 1, posVoulu);
            }
            //Il ne reste plus de cartes
            else{
                //Retourner à la position d'avant et prendre la prochaine carte

            }
        }
        //Carte pas tourné 3 fois
        else{
            //Tourner la carte
            carte.tourner();
            //Recontroler
        }
    }


    //Si la position qu'on veut changer c'est la première
    if(cartes[position].getPosition() == 0){
        //Reset pour passer toutes les cartes en première position

        ++i;
        for(Carte carte : cartes){
            if(carte.getId() == i){
                deplacer(cartes[0], carte);
            }
        }
        //find foncteur sur l'id??
        deplacer(cartes[0], cartes[i]);
        recursif(cartes, solutions, position + 1, posVoulu);
    }else if(cartes[position].getPosition() != 9){
        //cartes[position].tourner();
        recursif(cartes, solutions, position + 1, posVoulu);
    }else{

    }


}









//vector<Carte> pasDefini(vector<Carte>& cartes, Carte& carte, vector<unsigned> positions, unsigned pos) {
//    vector<unsigned> posSub(positions.begin() + 1,positions.end());
//    AControler controler;
//    switch(pos){
//        case 1 :
//        case 2 : controler = GAUCHE; break;
//        case 3 :
//        case 6 : controler = HAUT; break;
//        case 4 :
//        case 5 :
//        case 7 :
//        case 8 : controler =GAUCHEHAUT; break;
//        default: controler = RIEN;
//    }
//    if (controler) {
//        //La carte correspond?
//        if (controle(cartes, carte, controler)) {
//            //Est-ce qu'elle est tout à la fin du plateau?
//            if (pos == 8) {
//                //Solution!
//                return cartes;
//            } else {
//                //Passer à la prochaine position
//                return pasDefini(cartes,cartes[carte.getPosition() + 1],posSub,pos + 1);
//            }
//        }
//        //La carte correspond pas
//        else {
//            carte.tourner();
//        }
//    }
//    //Pas besoin de controler la carte donc passe à la prochaine case
//    else {
//        return pasDefini(cartes,cartes[carte.getPosition() + 1],posSub,pos + 1);
//    }
