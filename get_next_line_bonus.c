/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:15:52 by nfauconn          #+#    #+#             */
/*   Updated: 2022/09/11 23:30:36 by nfauconn         ###   ########.fr       */
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

static ssize_t	read_until_newline(int fd, char **over, char **newline_ptr)
{
	ssize_t		ret;
	char		*buff;

	buff = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	if (!*over)
		*over = ft_strdup("");
	ret = 1;
	while (ret && !line_return(*over))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		free_replace(over, ft_strjoin(*over, buff));
	}
	free(buff);
	*newline_ptr = line_return(*over);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*over[FOPEN_MAX];
	ssize_t		ret;
	char		*newline_ptr[FOPEN_MAX];
	char		*line;
	size_t		len;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	newline_ptr[fd] = NULL;
	ret = read_until_newline(fd, &over[fd], &newline_ptr[fd]);
	if (ret < 0 || (ret == 0 && !*over[fd]))
	{
		free(over[fd]);
		return (NULL);
	}
	line = ft_substr(over[fd], 0, newline_ptr[fd] - over[fd] + 1);
	if (*over[fd])
	{
		len = ft_strlen(over[fd]) - ft_strlen(line);
		free_replace(&over[fd], \
			ft_substr(over[fd], newline_ptr[fd] - over[fd] + 1, len));
	}
	return (line);
}
