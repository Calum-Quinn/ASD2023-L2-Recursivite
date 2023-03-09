/* -----------------------------------------------------------------------------------
Nom du fichier : controle.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 09.03.2023
Description    : Programme principal
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include "controle.h"

using namespace std;

bool controle(const vector<Carte>& cartes, Carte& carte, AControler controler) {
    int decalage;

    //Controle la carte à sa gauche
    if (controler == AControler::GAUCHE) {
        if (!check(cartes, carte, controler, AGAUCHE, ADROITE))
            return false;
    }
    //Controle la carte au dessus
    else if (controler == AControler::HAUT) {
        if (!check(cartes, carte, controler, DESSUS, DESSOUS))
            return false;
    }
    //Controle les cartes à gauche et au dessus
    else if (controler == AControler::GAUCHEHAUT) {
        if (!(check(cartes, carte, GAUCHE, AGAUCHE, ADROITE)
              and check(cartes, carte, HAUT, DESSUS, DESSOUS)))
            return false;
    }
    return true;
 }

bool check(const std::vector<Carte>& cartes, Carte& carte, AControler controler, const int moi, const int lui) {

    int decalage;

    //Défini le décalage du motif correspondant
    if (carte.getMotifs()[moi] % 2)
        decalage = 1;
    else
        decalage = -1;

    //Controle si le motif de la pièce correspond à l'autre
    if (carte.getMotifs()[moi] != (cartes[carte.getPosition() - (controler == 1 ? 1 : 3)].getMotifs()[lui]) + decalage)
        return false;

    return true;
}