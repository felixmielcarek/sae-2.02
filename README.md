SAE-2.02 : Exploration algorithmique d'un problème :
===

Accessibilité dans un réseau aérien :
---

Cette SAE à été réaliser par : MIELCAREK Félix, JAULT Aurian et DE LA FUENTE Axel

### Informations importantes :

Si la résolution de votre écran est trop petite (souvent sur les ordinateurs portables), il est possible qu'il y'ai des bugs d'affichage avec les matrices. Pour résoudre ce problème il faut réduire la taille de la police de son terminal ('Ctrl + -').

Dans le code : 

- cityMod1 correspond au modèle 1 proposé par le sujet (les listes)
- cityMod4 correspond au modèle 4 proposé par le sujet (les matrices)

### Utilisation : 

Un Makefile est livré avec le code, il est excécutable grâce à la commande :

```
make
```
 
Une fois excécuté, un fichier **_exe_** est créé dans le répertoire **_./bin_** :

```
./bin/exe
```

Afin d'excécuter le programme.

### Documentation :

Pour générer la documention doxygen :

```
make docu
```

Pour supprimer les fichiers objets, l'executable et la documentation html :

```
make clean
```

De plus du _compteRendu.pdf_ disponible sur karuta et par mail. Sa version _compteRendu.md_ est disponible dans

```
./doc/compteRendu.md
```

### Répartition des documents dans l'arborescence

**_./bin_** est le répertoire dans lequel l'excécutable sera créé lors de la compilation.

**_./obj_** est le répertoire dans lequel les fichiers objets seront créés lors de la compilation.

**_./src_** est le répertoire dans lequel les fichiers sources (.cpp et .hpp) sont stockés.

**_./doc_** est le répertoire dans lequel les fichiers de documentations du code, ainsi que le compte rendu au format '.md' sont stockés.
