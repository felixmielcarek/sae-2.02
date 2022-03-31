Compte-Rendu : Exploration algorithmique d'un problème
===
Accessibilité dans un réseau aérien :
---

</br>

## **Sommaire :**

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

</br>
</br>
</br>
</br>

# 1.Description des implémentations choisi

## <ins>__Méthode N°1__</ins>

## Choix de l'implémentation

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Pour la première  implémentation nous avons choisi la représentation N°1 donnée par le sujet, la liste de villes. Pour chaque villes, nous faisont correspondre, dans un vecteur de pointeur de ville, la liste des destinations possibles. Nous remplissons ce vecteur en demandant pour chaque ville déjà existante s'il existe un vol direct vers cette aéroport.
### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Nous avons aussi implémentais une listes de villes par défaut afin de facilement tester les potentielles erreurs du programme ou bien simplement faciliter l'utilisation du programme.

## Détails des structures

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Les vecteurs contenants les villes existantes et les destinations sont des pointeurs de villes car cela était, d'après nous beaucoup plus léger de passer en paramètre un vecteur de pointeur plutôt que les villes en elle même. Au risque de rendre le code moins claire avec l'utilisation d'itérateur sur des pointeurs pour les appels de fonctions.

## <ins>__Méthode N°2__</ins>

## Choix de l'implémentation

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Pour la seconde implémentation, nous avons choisi la 4eme méthode proposée par le sujet, la matrice des villes. Pour implémenter la matrice en c++, nous avons choisi d'insérer des vecteurs de types booléen dans un vecteur. Nous utilisons la première liste de villes pour les insérers à la même place dans ce vecteur. Nous demandons ensuite à l'utilisateur les destinations directes de chacunes des villes et changeons les valeurs booléennes situé à la positions correspondantes (TRUE correspond à un vol direct).

</br>
</br>
</br>
</br>

# 2. Explication des algorithmes développés

## **Méthode N°1 :**

L'agorithme développer pour connaître si un vol est possible, et de savoir en combien de coût si le vol est possible est basé sur une fonction récursive. La fonction commence par tester si nous ne sommes pas déjà sur place. Puis vérifie si nous sommes déjà passé par cette ville. Si aucun des tests n'est vérifié, alors elle apelle récursivement chacune des destinations possibles de la ville actuelle.

</br>
</br>

Pour mieu comprendre suivons le processus à travers un exemple simple :

![image](mod11.png)

Dans cette exemple nous souhaitons atteindre la **_Ville D_** depuis la **_Ville A_**.

Dans un premier tant on test si nous sommes arrivé, ce n'est pas le cas. On test si nous sommes déjà passer par cette ville, ce n'est pas le cas non plus. Alors nous allons à la **_Ville B_**, première destination de la **_Ville A_**. (Trajet 1)

</br>
</br>
</br>

![image](mod12.png)

Nous refaisons les vérifications : Sommes-nous arrivé ? Non. Sommes-nous déjà passer par la ? Non.

On se déplace vers la seule destination possible : la **_Villa A_** (Trajet 2).

Lors des tests, on se rend compte que nous sommes déjà passer par là. Il nous faut donc nous arrêter (pour éviter de tourner en rond) et retourner vers les villes non-visiter accessible par **_Ville B_**. 

Dans notre cas **_Ville B_** n'a que **_Ville A_** en destination directe. On retourne donc encore en arrière, vers les autres destinations de **_Ville A_**.

</br>
</br>
</br>

![image](mod13.png)

On se rend donc dans la **_Ville C_** où nous effectuons les deux tests. Nous ne sommes ni arrivé, ni déjà passé par ici, on continue donc. La prochaine ville est la **_Ville D_**. (Trajet 3)

</br>
</br>
</br>

![image](mod14.png)

Une fois à la **_Ville D_** le test d'arrivé est validé, on retiens le nombre de coups qu'il nous a fallu. Cependant on ne s'arrête pas, car un chemin plus court existe peut-être. La **_Ville D_** ne mène qu'a la **_Ville C_** qui à déjà été visiter. Il nous reste la deuxième destination de la **_Ville C_**.

</br>
</br>
</br>

![image](mod15.png)

On se rend donc à la **_Ville A_** qui est la dernière destination possible. Elle ne respecte évidement pas les tests. On retourne alors le plus petit trajet retenu (il n'y en a qu'un ici).


</br>
</br>
</br>
</br>

# 3. Comparaison de complexité

## Quelle est la compléxité d'une recherche avec le modèle en liste ? (modèle 1)

La fonction de recherche est divisé en différentes étapes. En premier lieu elle lance une boucle qui va parcrourir chaque ville présente dans le réseau. A chaque nouveau tour la prochaine ville présente dans le réseau est pointé. Cependant avant de terminer la boucle, la fonction de recherche est appellé de manière récursive sur chacune des villes accessibles depuis la ville pointé dans la boucle.

On se retrouve donc avec une boucle itérative faisant **_n_** opérations, de plus on effectue 2 tests **_(+2)_**, ainsi que 2 potentiels opérations **_(+2)_**. Puis lors de chaque tour de boucle, on fait un appelle récursif **_n-1_** fois, car la ville déjà visiter ne sera pas revisité par l'algo (test n°1). 

On se retrouve donc avec une compléxité de **_(n * 2 + 4) * n-1_**

</br>
</br>
</br>
</br>

# 4. Peut-il résoudre d'autres problème ?

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Nous pensons que nos implémentations peuvent être implémenter dans de nombreux cas. L'objectif de ce programme est de savoir s'il est possible d'arrivé à un point B à partir d'un point A. Dans le cas présent nous parlons de villes et d'aéroports, cependant il est aussi possible de l'appliquer à des situations différentes. 

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;En effet nous pouvons prendres l'exemple d'une recettes de cuisines. A partir d'une tomate (point A), nous pouvons à travers plusieurs étapes, obtenirs une salade (point B). Cela permettrais de montrer à l'utilisateur les différentes étapes de la transformation de la tomate pour arriver à la fin de la recette. 

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;D'autres implémentations peuvent être envisagés notamment pour la créations d'objets techniques avec de nombreuses étapes, nous pouvons prendre l'exemple du jeu "Minecraft" qui possède un arbre de création conséquent et représente parfaitement cette situation.
![Regardez notamment les différentes créations  possible avec un minerai de fer](https://jolstatic.fr/attachments/8/6/403/1/NmVmNDdkNDc2NTJkMTkwOWQyNmM3YTI3NmJiY2ZlY2Q/minecraft_tree.png)
