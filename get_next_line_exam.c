# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd)
{
	char	linestack[666666] = 0;
	char *line;
	int ret = 0;
	int	i = 0;
	int j = 0;
	char buf = 0;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
//	line = malloc(400000);
	while  ((ret = read(fd, &buf, 1)) == 1 && buf != '\n')
	{
		(linestack)[i++] = buf;
	}
	(linestack)[i] = '\0';
	if (!line[0] && ret == 0)
	{
		free(line);
		return (NULL);
	}
	line = malloc(i + 1);
	while (j < i)
	{
		line = linestack[j++];
	}
	line[i] = '\0';
	return (line);
}
