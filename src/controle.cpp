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