#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char**av)
{
	int		 fd1;
	char	*str;
	int		i;

	if (ac == 2)
	{
		fd1 = open(av[1], O_RDONLY);
		i = 0;
		while (1)
		{
			str = get_next_line(fd1);
			printf("line[%d] = %s\n", i++, str);
			if (!str)
				break ;
			free(str);
		}
		close(fd1);
	}
	else
		printf("please enter a file\n");
	return (0);
}
