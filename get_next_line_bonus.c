/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:15:52 by nfauconn          #+#    #+#             */
/*   Updated: 2022/10/08 17:12:29 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*line_return(char *over)
{
	while (over && *over)
	{
		if (*over == '\n')
			return (over);
		over++;
	}
	return (NULL);
}

static void	free_replace(char **over, char *joined)
{
	char	*tmp;

	if (!over)
		return ;
	tmp = *over;
	*over = ft_strdup(joined);
	free(tmp);
	free(joined);
}

static ssize_t   	read_until_newline(int fd, char **over, char **newline_ptr)
{
	ssize_t		ret;
	char		*buff;

	buff = (char *)malloc(sizeof (char) * (BUFFER_SIZE * 1));
	if (!buff)
		return (-1);
	if (!*over)
		*over = ft_strdup("");
	ret = 1;
	while (ret && !line_return(*over))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buff);
			return (-1);
		}
		buff[ret] = '\0';
		free_replace(over, ft_strjoin(*over, buff));
	}
	free(buff);
	*newline_ptr = line_return(*over);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*over;
	ssize_t		ret;
	char		*newline_ptr;
	char		*line;
	size_t		len;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	newline_ptr = NULL;
	ret = read_until_newline(fd, &over, &newline_ptr);
	if (ret < 0 || (ret == 0 && !*over))
	{
		free(over);
		return (NULL);
	}
	line = ft_substr(over, 0, newline_ptr - over + 1);
	if (*over)
	{
		len = ft_strlen(over) - ft_strlen(line);
		free_replace(&over, \
			ft_substr(over, newline_ptr - over + 1, len));
	}
	return (line);
}
