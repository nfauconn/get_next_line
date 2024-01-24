/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:48:08 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/24 14:42:20 by nfauconn         ###   ########.fr       */
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

static char	*alloc_buffers(char **buf, char **rest)
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
	static char	*rest;
	char		*nl_ptr;
	ssize_t		ret;

	nl_ptr = NULL;
	ret = 1;
	while (ret && !nl_ptr)
	{
		if (fd < 0 || BUFFER_SIZE < 1 || !alloc_buffers(&buf, &rest))
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0 || (ret == 0 && !*rest))
		{
			free(buf);
			return (free_replace(&rest, NULL));
		}
		buf[ret] = '\0';
		free_replace(&rest, ft_strjoin(rest, buf));
		free(buf);
		if (!rest)
			return (NULL);
		nl_ptr = nl_chr(rest);
	}
	return (fill_line(&rest, nl_ptr));
}
