[![en](https://img.shields.io/badge/lang-en-purple.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-pink.svg)](https://github.com/nfauconn/get_next_line/blob/master/README.fr.md)

i# Projet : Get Next Line

## 🏁 Objectif 🏁
Développer une fonction qui nous permet de lire un fichier texte référencé par le descripteur de fichier, une ligne à la fois, par des appels successifs à cette fonction.

## 💡 Apprentissages 💡

### 🌐 Langage : C 🌐

- **Variables Statiques :** préserver des informations d'état à travers de multiples appels de fonction.

### 🔧 Pratiques de Développement et Outils 🔧

- **Gestion des Descripteurs de Fichier :** lire efficacement et en toute sécurité les données depuis un descripteur de fichier.

- **Gestion de la Mémoire :** éviter les fuites de mémoire et garantir une bonne hygiène de la mémoire.

- **Gestion des Buffers :** lire et traiter efficacement les données stockées dans un buffer.

- **Adhérence aux Normes et Standards de Codage**: écrire du code non seulement opérationnel mais aussi épuré, lisible et en stricte adhérence à la fois aux directives du projet et aux standards élevés de codage de l'école
  > *max 5 fonctions par fichier, max 25 lignes par function, max 80 colonnes par ligne*

## 📋 Sujet 📋

## Exigences et Règles

### Langage et Standards
- Le projet doit être écrit en C.
- Il doit adhérer à la norme de codage de 42. Tout écart entraînera un score de 0.
- Les fonctions ne doivent pas quitter de manière inattendue (faute de segmentation, erreur de bus, double libération, etc.), sauf en cas de comportement indéfini.

### Gestion de la Mémoire
- Toute la mémoire allouée sur le tas doit être libérée lorsque nécessaire. Aucune fuite de mémoire ne sera tolérée.

### Compilation et Exécution
- Le programme doit se compiler avec les drapeaux `-Wall`, `-Wextra`, et `-Werror` et avec l'option : `-D BUFFER_SIZE=n`. Cette macro, définie au moment de l'invocation du compilateur, sera utilisée pour spécifier la taille du buffer lors des appels à `read()` dans notre fonction `get_next_line()`.
- La valeur de BUFFER_SIZE sera modifiée lors de l'évaluation par les pairs et par la Moulinette (le programme d'évaluation de 42) à des fins de test.
- La commande de compilation sera similaire à : 
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <fichiers>.c
```

### Fonctionnalité
- `get_next_line` :
  - Prototype : `char *get_next_line(int fd);`
  - Fichiers : `get_next_line.h`, `get_next_line.c`, `get_next_line_utils.c`
  - Paramètres : `fd` : le descripteur de fichier à lire
  - Valeur de Retour : 
    - Le contenu de la ligne lue : comportement correct
    - `NULL` : plus rien à lire ou une erreur s'est produite
  - Fonctions Externes Autorisées : `read`, `malloc`, `free`

- La fonction doit se comporter correctement que ce soit en lisant depuis un fichier ou depuis l'entrée standard.
 
- Elle doit retourner la ligne qui a été lue suivie d'un `\n`, sauf lorsque la fin du fichier a été atteinte (ligne retournée telle quelle).

- `get_next_line()` a un comportement indéfini si, entre deux appels, le fichier pointé par le descripteur de fichier a été modifié alors que le fichier n'a pas été complètement lu.
- La lecture depuis un fichier binaire est considérée comme ayant un comportement indéfini.

### Ce qui n'est Pas Autorisé
- `libft` n'est pas autorisé pour ce projet.
- La fonction `lseek()` est interdite.
- Les variables globales sont interdites.

## Partie Bonus

- Implémenter `get_next_line()` avec seulement une variable statique.
- Étendre `get_next_line()` pour gérer plusieurs descripteurs de fichiers. Par exemple, si les descripteurs de fichiers 3, 4, et 5 sont accessibles pour la lecture, il devrait être possible de les lire tour à tour sans jamais perdre le contenu lu sur chacun des descripteurs de fichiers et sans retourner la mauvaise ligne.

Ajouter le suffixe `_bonus.[c/h]` aux fichiers de cette partie. En plus des 3 fichiers obligatoires, soumettre les fichiers suivants :
- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

```c
#include "get_next_line_bonus.h"

static char	*nl_chr(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

static char	*all(char **buf, char **rest)
{
	*buf = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (NULL);
	if (!*rest)
	{
		*rest = ft_strdup("");
		if (!*rest)
		{
			free(*buf);
			return (NULL);
		}
	}
	return (*rest);
}

static char	*fill_rest(char **rest, t_newstr *line)
{
	t_newstr	newrest;

	newrest.len = ft_strlen(*rest) - line->len;
	newrest.str = ft_substr(*rest, line->len + 1, newrest.len);
	if (!newrest.str)
		free(line->str);
	return (free_replace(rest, newrest.str));
}

static char	*fill_line(char **rest, char *nl_ptr)
{
	t_newstr	line;

	line.str = NULL;
	if (nl_ptr)
	{
		line.len = nl_ptr - *rest;
		line.str = ft_substr(*rest, 0, line.len + 1);
		if (!line.str)
			return (free_replace(rest, NULL));
		fill_rest(rest, &line);
		if (!rest)
			return (NULL);
	}
	else
	{
		line.str = ft_strdup(*rest);
		free_replace(rest, NULL);
		if (!line.str)
			return (NULL);
	}
	return (line.str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*rest[PATH_MAX];
	char		*nl_ptr;
	ssize_t		ret;

	nl_ptr = NULL;
	ret = 1;
	while (ret && !nl_ptr)
	{
		if (fd < 0 || fd > PATH_MAX || BUFFER_SIZE < 1 || !all(&buf, &rest[fd]))
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0 || (ret == 0 && !*rest[fd]))
		{
			free(buf);
			return (free_replace(&rest[fd], NULL));
		}
		buf[ret] = '\0';
		free_replace(&rest[fd], ft_strjoin(rest[fd], buf));
		free(buf);
		if (!rest[fd])
			return (NULL);
		nl_ptr = nl_chr(rest[fd]);
	}
	return (fill_line(&rest[fd], nl_ptr));
}

```