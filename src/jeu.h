/* -----------------------------------------------------------------------------------
Nom du fichier : jeu.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 09.03.2023
Description    : Programme lançant l'algorithme du jeu.
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L2_RECURSIVITE_JEU_H
#define ASD2022_L2_RECURSIVITE_JEU_H

#include <vector>

#include "Carte.h"

/**
     * @name            : puzzleImpossible
     *
     * @but             : Appeler la fonction resolution pour calculer toutes les solutions au jeu
     *
     * @return          : le vecteur contenant toutes les solutions
     * @throws          : NIL
     */
std::vector<std::vector<Carte>> puzzleImpossible();


/**
     * @name            : resolution
     *
     * @but             : Passer le moins de permutations possibles de sorte à trouver toutes les solutions au jeu
     *
     * @param cartes    : Vecteur contenant toutes les cartes
     * @param plateau   : Vecteur servant de zone de test pour les différentes permutations
     * @param pos       : Position de la carte qu'on veut contrôler
     * @param posVoulu  : Position à laquelle on veut mettre la carte controlée
     * @param solutions : Vecteur contenant toutes les solutions au jeu
     * @return          : void
     * @throws          : NIL
     */
void resolution(std::vector<Carte>& cartes, std::vector<Carte>& plateau, size_t pos, size_t posVoulu, std::vector<std::vector<Carte>>& solutions);


/**
     * @name            : checkID
     *
     * @but             : Contrôle que la prochaine carte à contrôler n'est pas déjà utilisée
     *
     * @param cartes    : Vecteur contenant toutes les cartes
     * @param plateau   : Vecteur servant de zone de test pour les différentes permutations
     * @param pos       : Position de la carte qu'on veut contrôler
     * @return          : void
     * @throws          : NIL
     */
void checkID(std::vector<Carte>& cartes, std::vector<Carte>& plateau, size_t& pos);


//Foncteur pour trouver une carte avec le même ID
class MemeID {
public:
    /**
     * @name                : MemeID
     *
     * @but                 : Constructeur avec paramètre
     *
     * @param id            : valeur de l'id qu'on veut trouver
     * @return              : void
     * @throws              : NIL
     */
    explicit MemeID(unsigned id) : id_(id){}

    /**
     * @name                : operator()
     *
     * @but                 : Opérateur de surcharge des ()
     *
     * @param carte         : Carte pour laquelle on cherche l'identificateur
     * @return              : Booléen disant si l'id de la carte est le même que celui passé en paramêtre
     * @throws              : NIL
     */
    bool operator()(Carte& carte) const {
        return carte.getId() == id_;
    }
private:
    unsigned id_;
};

#endif //ASD2022_L2_RECURSIVITE_JEU_H
