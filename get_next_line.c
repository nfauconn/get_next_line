/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:48:08 by nfauconn          #+#    #+#             */
/*   Updated: 2022/10/22 17:28:49 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*fill_line(char **rest, char *nl_ptr)
{
	char	*line;
	size_t	linelen;
	char	*newrest;
	size_t	newrestlen;

	if (nl_ptr)
	{
		linelen = nl_ptr - *rest;
		line = ft_substr(*rest, 0, linelen + 1);
		if (!line)
			return (ft_replace(rest, NULL));
		newrestlen = ft_strlen(*rest) - linelen;
		newrest = ft_substr(*rest, linelen + 1, newrestlen);
		if (!newrest)
		{
			free(line);
			return (ft_replace(rest, NULL));
		}
		ft_replace(rest, newrest);
	}
	else if (**rest)
	{
		line = ft_strdup(*rest);
		return (ft_replace(rest, NULL));
	}
	else
		return (ft_replace(rest, NULL));
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*rest;
	static char	*newrest;
	char		*nl_ptr;
	ssize_t		ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!rest)
	{
		rest = ft_strdup("");
		if (!rest)
			return (NULL);
	}
	nl_ptr = NULL;
	ret = 1;
	while (ret && !nl_ptr)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0 || (ret == 0 && !*rest))
			return (ft_replace(&rest, NULL));
		buf[ret] = '\0';
		newrest = ft_strjoin(rest, buf);
		if (!newrest)
			return (ft_replace(&rest, NULL));
		ft_replace(&rest, newrest);
		nl_ptr = nl_chr(rest);
	}
	return (fill_line(&rest, nl_ptr));
}

