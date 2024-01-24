/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:54:50 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/24 14:42:14 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_newstr
{
	char	*str;
	size_t	len;
}	t_newstr;

/* GNL */
char	*get_next_line(int fd);

/* UTILS */
size_t	ft_strlen(char *s);
char	*ft_substr(char *source, size_t start, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*free_replace(char **old, char *new);

#endif
