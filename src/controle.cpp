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

bool controle(vector<Carte>& cartes, size_t posMoi, size_t posLui, AControler controler) {

    //Controle la carte à sa gauche
    if (controler == AControler::GAUCHE) {
        if (!check(cartes[posMoi], cartes[posLui], AGAUCHE, ADROITE))
            return false;
    }
    //Controle la carte au dessus
    else if (controler == AControler::HAUT) {
        if (!check(cartes[posMoi], cartes[posLui], DESSUS, DESSOUS))
            return false;
    }
    //Controle les cartes à gauche et au dessus
    else if (controler == AControler::GAUCHEHAUT) {
        if (!(check(cartes[posMoi], cartes[posLui], AGAUCHE, ADROITE)
              and check(cartes[posMoi], cartes[posLui], DESSUS, DESSOUS)))
            return false;
    }
    return true;
 }

bool check(Carte& carte1, Carte& carte2, const int moi, const int lui) {

    int decalage;

    //Défini le décalage du motif correspondant
    if ((carte1.getMotifs()[(moi + carte1.getRot()) % 4] % 2) != 0)
        decalage = 1;
    else
        decalage = -1;

    //Controle si le motif de la pièce correspond à l'autre
    if (carte1.getMotifs()[(moi + carte1.getRot()) % 4] != (carte2.getMotifs()[(lui + carte2.getRot()) % 4] + decalage))
        return false;

    return true;
}