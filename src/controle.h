#ifndef ASD2022_L2_RECURSIVITE_CONTROLE_H
#define ASD2022_L2_RECURSIVITE_CONTROLE_H

#include "Carte.h"

enum AControler {RIEN,GAUCHE,HAUT,GAUCHEHAUT};

const unsigned  DESSUS = 0,
                ADROITE = 1,
                DESSOUS = 2,
                AGAUCHE = 3;

bool controle(const std::vector<Carte>& cartes, Carte& carte, AControler controler);

bool check(const std::vector<Carte>& cartes, Carte& carte, AControler controler, const int moi, const int lui);

#endif //ASD2022_L2_RECURSIVITE_CONTROLE_H