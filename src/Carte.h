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

#include <iostream>
#include <array>
#include <vector>

#include "pieces.h"

class Carte {
public:
   Carte() = default;

   /**
    * @name                : Carte
    *
    * @but                 : Constructeur avec paramètre
    *
    * @param id            : identificateur unique
    * @motifs              : vecteur contenant les images sur la carte
    * @return              : void
    * @throws              : NIL
    */
   Carte(const unsigned id, Piece motifs);

   /**
    * @name                : Carte
    *
    * @but                 : Constructeur par copie
    *
    * @param autre         : Carte à copier
    * @return              : void
    * @throws              : NIL
    */
   Carte(const Carte& c);

   /**
    * @name            : tourner
    *
    * @but             : Fonction qui tourne une carte
    *
    * @return          : void
    * @throws          : NIL
    */
   void tourner();

   /**
    * @name            : operator=
    *
    * @but             : Opérateur d'affectation
    *
    * @param autre     : Carte à affecter
    * @return          : La carte
    * @throws          : NIL
    */
   Carte& operator= (const Carte& autre);

   /**
    * @name            : operator<<
    *
    * @but             : Afficher une carte
    *
    * @param os        : Flux de sortie
    * @param carte     : Carte à afficher
    * @return          : Le flux de sortie
    * @throws          : NIL
    */
   friend std::ostream& operator<<(std::ostream& os, const Carte& carte);

   /**
    * @name            : getId
    *
    * @but             : Fonction qui retourne l'identificateur d'une carte
    *
    * @return          : L'identificateur
    * @throws          : NIL
    */
   unsigned getId() const{
      return id;
   }

   /**
    * @name            : setPosition
    *
    * @but             : Fonction qui permet de donner une position à une carte
    *
    * @param pos       : Position à donner à la carte
    * @return          : void
    * @throws          : NIL
    */
   void setPosition(size_t pos) {
      position = pos;
   }

   /**
    * @name            : getRot
    *
    * @but             : Fonction qui retourne la rotation d'une carte
    *
    * @return          : La rotation
    * @throws          : NIL
    */
   int getRot() const {
      return rot;
   }

   /**
    * @name            : getMotifs
    *
    * @but             : Fonction qui retourne le vecteur des motifs d'une carte
    *
    * @return          : Le vecteur de motifs
    * @throws          : NIL
    */
   Piece getMotifs() const{
      return motifs;
   }


private:
   unsigned id;
   size_t position;
   int rot;
   Piece motifs;
};



#endif //ASD2022_L2_RECURSIVITE_CARTE_H