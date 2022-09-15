#include "get_next_line.h"

int main()
{
	int fd1 = open("file1", O_RDONLY);
	char *str = get_next_line(fd1);
	int	i = 0;

	while (str)
	{
		printf("line[%d] = %s\n", i++, str);
		free(str);
		str = get_next_line(fd1);
	}
	close(fd1);
	return (0);
}
