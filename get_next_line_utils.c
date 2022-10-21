/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:41:00 by nfauconn          #+#    #+#             */
/*   Updated: 2022/10/21 16:21:03 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char *source, size_t start, size_t len)
{
	char	*new;
	size_t	sourcelen;
	size_t	i;

	if (!source || len == 0 || start > ft_strlen(source))
		return (ft_strdup(""));
	sourcelen = ft_strlen(source);
	new = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (source[start] && i < len)
		new[i++] = source[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	newlen;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (s1 && s2)
		newlen = ft_strlen(s1) + ft_strlen(s2);
	else if (s1 && !s2)
		newlen = ft_strlen(s1);
	else if (!s2 && s1)
		newlen = ft_strlen(s2);
	new = malloc(sizeof (char) * (newlen + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

char	*ft_replace(char **old, char *new)
{
	char	*tmp;

	tmp = *old;
	*old = new;
	free(tmp);
	return (NULL);
}

