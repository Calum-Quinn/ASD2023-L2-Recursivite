/* -----------------------------------------------------------------------------------
Nom du fichier : main.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 07.03.2023
Description    : Programme trouvant les solutions au jeu Mini Logix
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include <iostream>

#include "pieces.h"
#include "Carte.h"
#include "jeu.h"

using namespace std;

int main() {

    vector<vector<Carte>> solutions = puzzleImpossible();

    cout << "Solutions!" << endl;

    for (vector<Carte>& vecCarte : solutions) {
        for (Carte& carte : vecCarte) {
            cout << carte.getId() << char(carte.getRot() + 97) << " ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}