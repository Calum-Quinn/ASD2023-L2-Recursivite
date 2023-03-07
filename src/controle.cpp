#include "controle.h"

using namespace std;

bool controle(const std::vector<Carte>& cartes, Carte& carte, AControler controler) {
    if (controler == AControler::GAUCHE) {
        if (carte.getMotifs()[3] != cartes[carte.getPosition() - 1].getMotifs()[1])
            return false;
    }
    else if (controler == AControler::HAUT) {
        if (carte.getMotifs()[0] != cartes[carte.getPosition() - 3].getMotifs()[2])
            return false;
    }
    else if (controler == AControler::GAUCHEHAUT) {
        if( carte.getMotifs()[0] != cartes[carte.getPosition() - 3].getMotifs()[2] or
            carte.getMotifs()[3] != cartes[carte.getPosition() - 1].getMotifs()[1] )
            return false;
    }
    return true;
 }

