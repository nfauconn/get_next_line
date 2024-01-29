[![en](https://img.shields.io/badge/lang-en-purple.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-pink.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.fr.md)

# Projet : Get Next Line

## Résumé

Développement d'une fonction qui lit un fichier texte référencé par le descripteur de fichier, une ligne à la fois, à travers des appels successifs à cette fonction.

Fonctions Externes Autorisées : `read`, `malloc`, `free`

## Utilisation

```shell
git clone git@github.com:nfauconn/get_next_line.git
cd get_next_line/Projet
```

  - Fichiers : `get_next_line.h`, `get_next_line.c`, `get_next_line_utils.c`
  - Valeur de Retour :
    - Le contenu de la ligne lue, suivi d'un '\n', sauf lorsque la fin du fichier est atteinte (ligne retournée telle quelle) : comportement correct
    - `NULL` : rien d'autre à lire ou une erreur est survenue

- `get_next_line()` a un comportement indéfini si, entre deux appels, le fichier pointé par le descripteur de fichier a été modifié alors que le fichier n'a pas été complètement lu.
- La lecture d'un fichier binaire est considérée comme ayant un comportement indéfini.

Les fichiers sont situés dans `test_files/`

```shell
> cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 main.c get_next_line.c get_next_line_utils.c 
> ./a.out <fichier>
```
 N'hésitez pas à tester différentes valeurs pour BUFFER_SIZE.

#### Bonus (plusieurs fichiers a la fois)

```shell
> cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c 
> ./a.out <fichier1> <fichier2> <fichier3> <...>
```

## Compétences

- **Variables Statiques :** préserver les informations d'état à travers de multiples appels de fonction.

- **Gestion des Descripteurs de Fichier :** lire les données d'un descripteur de fichier de manière efficace et sécurisée.

- **Gestion de la Mémoire :** allocation et libération soigneuses de la mémoire pour éviter les fuites de mémoire et assurer une bonne hygiène de la mémoire.

- **Gestion du Tampon :** lire et traiter efficacement les données stockées dans un tampon.

- **Adhésion aux Normes et Standards de Codage :** écrire un code non seulement opérationnel mais aussi épuré, lisible et en stricte adhérence aux directives du projet ainsi qu'aux hautes normes de codage de l'école
  > *max 5 fonctions par fichier, max 25 lignes par fonction, max 80 col par ligne*