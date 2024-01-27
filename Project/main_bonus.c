/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:45:09 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 15:17:26 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
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
	char	*line;
	int		i = 0;
	int		j = 0;
	int		end_all_files = 0;

	printf("\n");
	while (i < nb_fd)
	{
		fd[i] = open(av[i + 1], O_RDONLY);
		if (fd[i] > 0)
			printf("%s opened : fd%d\n", av[i + 1], fd[i]);
		end_fd[i] = 0;
		i++;
	}
	printf("\n");
	while (!end_all_files)
	{
		int i = 0;
		while (i < nb_fd)
		{
			if (!end_fd[i])
			{
				line = get_next_line(fd[i]);
				printf("line[fd%d][%d] = %s", fd[i], j, line);
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
		printf("\n");
		j++;
		end_all_files = is_all_ended(end_fd, nb_fd);
	}
	printf("\n");
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
