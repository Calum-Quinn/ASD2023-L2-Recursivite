/* -----------------------------------------------------------------------------------
Nom du fichier : Carte.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 07.03.2023
Description    : Programme pour une classe qui défini les pièces du jeu
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L2_RECURSIVITE_CARTE_H
#define ASD2022_L2_RECURSIVITE_CARTE_H

#include "pieces.h"

#include <iostream>
#include <array>
#include <vector>

class Carte {
public:
    Carte() = default;
    Carte(const int id, Piece motifs);
    Carte(const Carte& c);

    friend std::ostream& operator<<(std::ostream& os, const Carte& carte);

    friend bool controle(const std::vector<Carte>& cartes, Carte& carte);

    Carte& operator= (const Carte& autre);
    void tourner();
    void rotate();
    void reset();


    unsigned getId() const{
        return id;
    }
    size_t getPosition() const{
        return position;
    }
    char getRotation() const{
        return rotation;
    }
    int getRot() const {
        return rot;
    }
    Piece getMotifs() const{
        return motifs;
    }


private:
    unsigned id;
    size_t position;
    char rotation;
    int rot;
    Piece motifs;
};



#endif //ASD2022_L2_RECURSIVITE_CARTE_H