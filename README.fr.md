[![en](https://img.shields.io/badge/lang-en-purple.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-pink.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.fr.md)

*Langage de programmation C* • *Variables statiques* • *Gestion des descripteurs de fichiers* • *Gestion des buffers* • *Gestion de la mémoire* • *Gestion des erreurs* • *Normes de codage (Conformité aux normes)*

# Get Next Line

Une fonction qui lit un fichier texte référencé par le descripteur de fichier, une ligne à la fois, à travers des appels successifs à cette fonction.

Fonctions externes autorisées : `read`, `malloc`, `free`. Pas de variables globales autorisées.

## Utilisation

```shell
git clone git@github.com:nfauconn/get_next_line.git
cd get_next_line/Project
```

  - Fichiers : `get_next_line.h`, `get_next_line.c`, `get_next_line_utils.c`
  - Valeur de retour :
    - Le contenu de la ligne lue, suivi d'un '\n', sauf lorsque la fin du fichier a été atteinte (ligne retournée telle quelle) : comportement correct
    - `NULL` : rien d'autre à lire OU une erreur s'est produite

- `get_next_line()` a un comportement indéfini si, entre deux appels, le fichier pointé par le descripteur de fichier a été modifié alors que le fichier n'a pas été complètement lu.
- La lecture d'un fichier binaire est considérée comme ayant un comportement indéfini.

Les fichiers sont situés dans `test_files/`

```shell
> cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 main.c get_next_line.c get_next_line_utils.c 
> ./a.out <fichier>
```
N'hésitez pas à tester différentes valeurs pour BUFFER_SIZE.

#### Utilisation avec plusieurs fds

```shell
> cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c 
> ./a.out <fichier1> <fichier2> <fichier3> <...>
```