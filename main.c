#include "get_next_line_bonus.h"

static int	is_all_ended(int *end_fd, int nb_fd)
{
	int	i = 0;
	while (i < nb_fd && end_fd[i])
		i++;
	if (i == nb_fd)
		return (1);
	else
		return (0);
}

void	test_gnl(int nb_fd, char **av)
{
	int		fd[nb_fd];
	int		end_fd[nb_fd];
	int		line_no[nb_fd];
	char	*line;
	int		i = 0;
	int		j = 0;
	int		end_all_files = 0;

	while (i < nb_fd)
	{
		fd[i] = open(av[i + 1], O_RDONLY);
		end_fd[i] = 0;
		i++;
	}
	while (!end_all_files)
	{
		int i = 0;
		while (i < nb_fd)
		{
			if (!end_fd[i])
			{
				line = get_next_line(fd[i]);
				printf("line[%d][%d] = %s", fd[i], j, line);
				if (!line)
				{
					printf("\n");
					end_fd[i] = 1;
				}
				else
				{
					free(line);
					line = NULL;
				}
			}
			i++;
		}
		j++;
		end_all_files = is_all_ended(end_fd, nb_fd);
	}
}

int	main(int ac, char **av)
{
	int	nb_fd;

	if (ac > 1)
	{
		nb_fd = ac - 1;
		test_gnl(nb_fd, av);
	}
	else
		printf("please enter at list a file as argument for GNL to be tested\n");
	return (0);
}
