# Rapport 

un court rapport au format markdown dans rapport qui
calcule de manière théorique le nombre de permutations possible des 9 pièces pour former un carré, y compris les 4 rotations possibles pour chaque pièce
compare ce calcul au nombre d'appels récursifs effectivement réalisés par votre algorithme. Idéalement votre algorithme ne doit pas explorer les branches de l'arbre de récursion donc il est clair qu'elles ne mènent pas à une solution étant donné qu'au moins 2 pièces sont incompatibles parmi celles déjà posées.
compare vos résultats au texte commercial de Djeco : "des millions de possibilités et une seule solution"

Nombre de possibilités de permutations pour 9 cartes avec chacun 4 rotations possibles:
* Le nombre de possibilités pour placer les cartes sans prendre en compte les rotations est égal aux nombres de cartes factoriel
  * Donc dans notre cas 9! ou bien 362'880.
* Le nombre de possibilités de avec les rotations pour un seul placement des cartes et équivalent au nombre de rotations possibles puissance le nombre de carte.
  Car pour chaque rotation de la première carte la deuxième a 4 possibilités et pour chaque rotation de la deuxième carte la troisième a 4 possibilités et ainsi de suite.
  * Donc le nombre de possibilités avec les rotations pour un seul placement de cartes est équivalent à 4^9 ou bien 262'144.

Le nombre total de possibilités revient donc à multiplier le nombre de rotations possibles par le nmbre de placement de cartes ce qui revient à 362'880 * 262'144 donc 95'126'814'720 possibilités de placement différents.
