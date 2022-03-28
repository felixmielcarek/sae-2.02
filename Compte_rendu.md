# Compte-Rendu

## 1. Description des implémentations choisi:

- ### Méthode N°1
    
    - #### Choix de l'implémentation
    
    - #### Détails des structures

- ### Methode N°2
    
    - #### Choix de l'implémentation
    
    - #### Détails des structures

## 2. Explication des algorithmes développés

## 3. Comparaison de complexité

- ### Méthode N°1

- ### Méthode N°2

## 4. Peut-il résoudre d'autres problèmes ?

---

# 1.Description des implémentations choisi

## <ins>__Méthode N°1__</ins>

## Choix de l'implémentation

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Pour la première  implémentation nous avons choisi la représentation N°1 donnée par le sujet, la liste de villes. Pour chaque villes, nous faisont correspondre, dans un vecteur de pointeur de ville, la liste des destinations possibles. Nous remplissons ce vecteur en demandant pour chaque ville déjà existante s'il existe un vol direct vers cette aéroport.
### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Nous avons aussi implémentais une listes de villes par défaut afin de facilement tester les potentielles erreurs du programme ou bien simplement faciliter l'utilisation du programme.

## Détails des structures

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Les vecteurs contenants les villes existantes et les destinations sont des pointeurs de villes car cela était, d'après nous beaucoup plus léger de passer en paramètre un vecteur de pointeur plutôt que les villes en elle même. au risque de rendre le code moins claire avec l'utilisation d'itérateur sur des pointeurs pour les appels de fonctions.

## <ins>__Méthode N°2__</ins>

## Choix de l'implémentation

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Pour la seconde implémentation, nous avons choisi la 4eme méthode proposée par le sujet, la matrice des villes. Pour implémenter la matrice en c++, nous avons choisi d'insérer des vecteurs de types booléen dans un vecteur. Nous utilisons la première liste de villes pour les insérers à la même place dans ce vecteur. Nous demandons ensuite à l'utilisateur les destinations directes de chacunes des villes et changeons les valeurs booléennes situé à la positions correspondantes (TRUE correspond à un vol direct).

---

## 2.Explication des algorithmes développés



---

## 3. Comparaison de complexité

---

## 4. Peut-il résoudre d'autres problème ?

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Nous pensons que nos implémentations peuvent être implémenter dans de nombreux cas. L'objectif de ce programme est de savoir s'il est possible d'arrivé à un point B à partir d'un point A. Dans le cas présent nous parlons de villes et d'aéroports, cependant il est aussi possible de l'appliquer à des situations différentes. 

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;En effet nous pouvons prendres l'exemple d'une recettes de cuisines. A partir d'une tomate (point A), nous pouvons à travers plusieurs étapes, obtenirs une salade (point B). Cela permettrais de montrer à l'utilisateur les différentes étapes de la transformation de la tomate pour arriver à la fin de la recette. 

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;D'autres implémentations peuvent être envisagés notamment pour la créations d'objets techniques avec de nombreuses étapes, nous pouvons prendre l'exemple du jeu "Minecraft" qui possède un arbre de création conséquent et représente parfaitement cette situation.
![Regardez notamment les différentes créations  possible avec un minerai de fer](https://jolstatic.fr/attachments/8/6/403/1/NmVmNDdkNDc2NTJkMTkwOWQyNmM3YTI3NmJiY2ZlY2Q/minecraft_tree.png)
