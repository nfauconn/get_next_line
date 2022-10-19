#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFFER_SIZE 42

size_t	ft_strlen(char *s)
{
	size_t	i = 0;
	while (*s)
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*new;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *source, unsigned int start, size_t len)
{
	char	*new;
	size_t	sourcelen;
	size_t	i;

	sourcelen = ft_strlen(source);
	if (!source || (size_t)start > sourcelen)
		len = 0;
	else if ((size_t)start + len > sourcelen)
		len = sourcelen - (size_t)start;
	new = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (len > 0)
		while (source[start] && i < len)
			new[i++] = source[start++];
	new[len] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	size_t		linelen;
	char		buf[BUFFER_SIZE];
	size_t		buflen;
	static char	*rest = NULL;
	ssize_t		ret;
	size_t		nl_pos;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nl_ptr = NULL;
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
		return (NULL);
	line = NULL;
	while (!line)
	{
		nl_pos = newline_index(buf);
		if (nl_pos)
		{
			line = malloc(sizeof(char) * (nl_pos + 1));
			buflen = ft_strlen(buf) - nl_pos;
			while (
		}
	}
}
