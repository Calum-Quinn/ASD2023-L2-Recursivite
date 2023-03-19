/* -----------------------------------------------------------------------------------
Nom du fichier : jeu.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 09.03.2023
Description    : Algorithme qui trouve toutes les solutions au jeu
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include "jeu.h"
#include "controle.h"

using namespace std;

using Cartes = vector<Carte>;

vector<Cartes> puzzleImpossible() {
    //Vecteur contenant chaque pièce du puzzle
    Cartes cartes;
    //Vecteur qui servira pour tester les cartes ensembles
    Cartes plateau;
    cartes.reserve(PIECES.size());
    //Vecteur qui contiendra toutes les solutions possibles
    vector<Cartes> solutions;
    solutions.reserve(10);

    //Création du vecteur des cartes
    for(size_t i = 0; i < 9; ++i){
        cartes.push_back(Carte((unsigned int)(i + 1), PIECES[i]));
    }

    //Appels de la fonction de calcul
    for(size_t i = 0; i < cartes.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            resolution(cartes, plateau, i, 0, solutions);
            plateau.clear();
            cartes[i].tourner();
        }
    }

    return solutions;
}

void resolution(vector<Carte>& cartes, vector<Carte>& plateau, size_t pos, size_t posVoulu, vector<vector<Carte>>& solutions) {

    static int globalCount = 0;
    ++globalCount;
    cout << globalCount << endl;

    AControler controler;

    //Si on est à la première place
    if (!posVoulu) {
        //Placer carte
        plateau.push_back(cartes[pos]);

        //Lui mets la bonne position pour le vecteur
        plateau[plateau.size() - 1].setPosition(plateau.size() - 1);
        //Passer à la prochaine position et à la prochaine carte
        ++posVoulu;
        pos = ++pos % cartes.size();
    }

    //Contrôler quelle carte peut aller avec
    for (int i = 1; i <= int(cartes.size() - plateau.size()); ++i) {
        //Contrôler chaque motif pour un qui correspond
        for (int j = 0; j < 4; ++j) {

            //Défini quelles autres cartes il faut comparer
            switch (posVoulu) {
                case 1 :
                case 2 :
                    controler = GAUCHE; break;
                case 3 :
                case 6 :
                    controler = HAUT; break;
                case 4 :
                case 5 :
                case 7 :
                case 8 :
                    controler = GAUCHEHAUT; break;
                default:
                    controler = RIEN;
            }


            //Si le motif concorde
            if (controle(plateau, posVoulu,cartes[pos],j,controler)) {
                //Placer la deuxième carte
                plateau.push_back(cartes[pos]);

                //Lui mets la bonne position et passe à la prochaine carte
                plateau[plateau.size() - 1].setPosition(plateau.size() - 1);

                //Tourner la carte pour être dans la bonne position dans le plateau
                for (int k = 1; k <= j; ++k) {
                    plateau[plateau.size() - 1].tourner();
                }

                pos = ++pos % cartes.size();

                //Si on est à la fin du plateau
                if (posVoulu == cartes.size() - 1) {
                    //Ajouter la solution
                    solutions.push_back(plateau);
                }
                else {
                    checkID(cartes,plateau,pos);

                    //Continuer avec la prochaine position
                    ++posVoulu;
                    resolution(cartes, plateau,pos,posVoulu,solutions);

                    //Quand on remonte la branche il faut passer à la case d'avant
                    --posVoulu;
                }
                //Pour éviter de regarder les autres côtés d'une carte déjà confirmée
                j = 3;
                --pos;
                plateau.resize(posVoulu);
            }

            //Si la carte a déjà été tournée trois fois et qu'il reste des cartes à regarder
            if (j == 3 and i != int(cartes.size() - plateau.size())) {
                pos = ++pos % cartes.size();

                checkID(cartes,plateau,pos);
            }
        }
    }
}

void checkID(std::vector<Carte>& cartes, std::vector<Carte>& plateau, size_t& pos) {
    //Contrôle que la prochaine carte à contrôler n'est pas déjà utilisée
    for (int l = 0; l < int(plateau.size()); ++l) {
        MemeID m(cartes[pos].getId());
        bool b = m(plateau[size_t(l)]);
        if (b) {
            //Si la carte est déjà utilisée, contrôle la prochaine
            pos = ++pos % cartes.size();
            l = -1;
        }
    }

}