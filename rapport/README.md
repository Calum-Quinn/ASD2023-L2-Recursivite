# Rapport 

Nombre de possibilités de permutations pour 9 cartes avec chacun 4 rotations possibles:
* Le nombre de possibilités pour placer les cartes sans prendre en compte les rotations est égal au nombre de cartes factoriel.
  * Donc dans notre cas 9! ou bien 362'880.
* Le nombre de possibilités avec les rotations pour un seul placement des cartes et équivalent au nombre de rotations possibles à la puissance du nombre de cartes.
  Car pour chaque rotation de la première carte la deuxième a 4 possibilités et pour chaque rotation de la deuxième carte la troisième a 4 possibilités et ainsi de suite.
  * Donc le nombre de possibilités avec les rotations pour un seul placement de cartes est équivalent à 4^9 ou bien 262'144.

Le nombre total de possibilités revient donc à multiplier le nombre de rotations possibles par le nombre de placements de cartes ce qui revient à 362'880 * 262'144 donc à 95'126'814'720 possibilités de placement différents des 9 cartes avec les rotations.

L'algorithme que nous avons créés fait seulement 3'758 appels récursifs pour contrôler les possibilités nécessaires à trouver toutes les solutions au jeu.
Ceci fait plus de 25'313'149 fois moins que le nombre de possibilités total.

Le fabricant du jeu dis "des millions de possibilités et une seule solution", ce que nous avons pu démontrer comme faux. Selon un ordinateur il y a 8 possibilités distinctes au jeu, pour un humain ce serait plutôt 2. Pour chaque "vrai" solution au jeu nous pouvons tourner le plateau entier sur lui même pour donner la "même" solution avec une rotation différente.

Voici la première solution.
  * 1b 5d 4a 7a 6a 2a 8a 3a 9d
  
![image](https://user-images.githubusercontent.com/114938794/226186385-b6017038-1de1-44b6-bdcb-280357bd74a7.png)

Les solutions suivantes sont des rotations de 90° de la première solution,
- 4b 2b 9a 5a 6b 3b 1c 7b 8b
- 8d 7d 1a 3d 6d 5c 9c 2d 4d
- 9b 3c 8c 2c 6c 7c 4c 5b 1d
  
Voici la deuxième solution.  
  * 1c 9a 6b 2a 4b 8b 7a 3a 5a
  
![image](https://user-images.githubusercontent.com/114938794/226186414-05c6728b-52b9-4898-a135-638f791fdc97.png)
  
Les solutions suivantes sont des rotations de 90° de la première solution,
- 5c 3c 7c 8d 4d 2c 6d 9c 1a
- 6c 8c 5b 9b 4c 3b 1d 2b 7b
- 7d 2d 1b 3d 4a 9d 5d 8a 6a
  
