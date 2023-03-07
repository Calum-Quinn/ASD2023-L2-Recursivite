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



    unsigned getId() const{
        return id;
    }
    size_t getPosition() const{
        return position;
    }
    char getRotation() const{
        return rotation;
    }
    Piece getMotifs() const{
        return motifs;
    }


private:
    unsigned id;
    const size_t position;
    char rotation;
    Piece motifs;
};



#endif //ASD2022_L2_RECURSIVITE_CARTE_H