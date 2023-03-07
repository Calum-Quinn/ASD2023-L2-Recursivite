#ifndef ASD2022_L2_RECURSIVITE_CONTROLE_H
#define ASD2022_L2_RECURSIVITE_CONTROLE_H

#include "Carte.h"

enum AControler {RIEN,GAUCHE,HAUT,GAUCHEHAUT};

bool controle(const std::vector<Carte>& cartes, Carte& carte, AControler controler);

#endif //ASD2022_L2_RECURSIVITE_CONTROLE_H