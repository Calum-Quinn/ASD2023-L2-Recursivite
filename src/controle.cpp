/* -----------------------------------------------------------------------------------
Nom du fichier : controle.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 09.03.2023
Description    : Algorithme de contrôle pour savoir si deux cartes correspondent
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include "controle.h"

using namespace std;

bool controle(vector<Carte>& plateau, size_t posVoulu, Carte& carte, int rotation, AControler controler) {

    //Controle la carte à gauche
    if (controler == AControler::GAUCHE) {
        if (!check(plateau, posVoulu, carte, AGAUCHE, ADROITE, rotation))
            return false;
    }
        //Controle la carte au dessus
    else if (controler == AControler::HAUT) {
        if (!check(plateau, posVoulu, carte, DESSUS, DESSOUS, rotation))
            return false;
    }
        //Controle les cartes à gauche et au dessus
    else if (controler == AControler::GAUCHEHAUT) {
        if (!(check(plateau, posVoulu, carte, AGAUCHE, ADROITE, rotation)
              and check(plateau, posVoulu, carte, DESSUS, DESSOUS, rotation)))
            return false;
    }
    return true;
}

bool check(vector<Carte>& plateau, size_t posVoulu, Carte& carte, const int monCote, const int sonCote, int rotation) {

    int decalage;

    //Défini le décalage du motif correspondant
    if ((carte.getMotifs()[size_t((monCote + rotation) % 4)] % 2) != 0)
        decalage = 1;
    else
        decalage = -1;

    //Controle si le motif de la pièce correspond à l'autre
    if (carte.getMotifs()[size_t((monCote + rotation) % 4)] != (plateau[size_t(posVoulu + size_t(monCote + sonCote) - 5)].getMotifs()[size_t((sonCote + plateau[size_t(posVoulu + size_t(monCote + sonCote) - 5)].getRot()) % 4)] + decalage))
        return false;

    return true;
}