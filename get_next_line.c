/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:48:08 by nfauconn          #+#    #+#             */
/*   Updated: 2022/10/21 16:17:36 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*nl_chr(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE];
	static char	*rest;
	char		*nl_ptr;
	ssize_t		ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!rest)
		rest = ft_strdup("");
	nl_ptr = NULL;
	ret = 1;
	while (ret && !nl_ptr)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0 || (ret == 0 && !*rest))
			return (ft_replace(&rest, NULL));
		buf[ret] = '\0';
		ft_replace(&rest, ft_strjoin(rest, buf));
		nl_ptr = nl_chr(rest);
	}
	line = ft_substr(rest, 0, nl_ptr - rest + 1);
	ft_replace(&rest, \
			ft_substr(rest, ft_strlen(line), ft_strlen(rest) - ft_strlen(line)));
	return (line);
}

