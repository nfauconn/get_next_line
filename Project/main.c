/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:40:03 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/24 14:42:28 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (!str)
			{
				printf("str = null\n");
				break ;
			}
			printf("line[%d] = %s\n", i++, str);
			free(str);
		}
		close(fd1);
	}
	else
		printf("please enter a file\n");
	return (0);
}
