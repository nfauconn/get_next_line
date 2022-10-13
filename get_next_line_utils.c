/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noe <noe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:59:22 by nfauconn          #+#    #+#             */
/*   Updated: 2022/10/13 18:19:07 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	while (n--)
		*dest++ = *source++;
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start + len > s_len)
		len = s_len - start;
	if (start > s_len)
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new = ft_memcpy(new, s + start, len + 1);
	new[len] = '\0';
	return (new);
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	tab = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		new[j + i] = s2[i];
		i++;
	}
	new[j + i] = '\0';
	return (new);
}
