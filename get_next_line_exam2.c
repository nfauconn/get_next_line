#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER_SIZE 42

size_t	ft_strlen(char *s)
{
	size_t	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*new;
	size_t	i = 0;

	new = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char *source, unsigned int start, size_t len)
{
	char	*new;
	size_t	sourcelen;
	size_t	i = 0;

	sourcelen = ft_strlen(source);
	if (!source || (size_t)start > sourcelen)
		len = 0;
	else if ((size_t)start + len > sourcelen)
		len = sourcelen - (size_t)start;
	new = malloc(sizeof(char) * (len + 1));
	if (len > 0)
		while (source[start] && i < len)
			new[i++] = source[start++];
	new[len] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i = 0;
	size_t	j = 0;

	new = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

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

void	free_replace(char **old, char *new)
{
	char		*tmp;

	if (!new)
		return ;
	tmp = *old;
	*old = new;
	free(tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE];
	static char	*rest;
	size_t		restlen;
	char		*nl_ptr;
	ssize_t		ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!rest)
		rest = ft_strdup("");
	ret = 1;
	while (!(nl_ptr = nl_chr(rest)))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(rest);
			return (NULL);
		}
		else if (ret == 0)
			break ;
		buf[ret] = '\0';
		free_replace(&rest, ft_strjoin(rest, buf));
	}
	line = ft_substr(rest, 0, nl_ptr - rest + 1);
	if (ft_strlen(line) != ft_strlen(rest))
	{
		restlen = ft_strlen(rest) - ft_strlen(line);
		free_replace(&rest, ft_substr(rest, ft_strlen(line), restlen));
	}
	return (line);
}
