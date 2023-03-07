#include <algorithm>

#include "deplacer.h"

using namespace std;

void tourner(Piece& piece) {
    rotate(piece.begin(),piece.begin() + 1,piece.end());
}

void deplacer(Piece& piece,unsigned position) {

}