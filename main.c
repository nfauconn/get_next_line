#include "get_next_line.h"

int main(int ac, char**av)
{
	int		 fd1;
	char	*str;
	int		i;

	if (ac == 2)
	{
		fd1 = open(av[1], O_RDONLY);
		str = get_next_line(fd1);
		i = 0;
		while (str)
		{
			printf("line[%d] = %s\n", i++, str);
			free(str);
			str = get_next_line(fd1);
		}
		close(fd1);
	}
	else
		printf("please enter a file\n");
	return (0);
}
