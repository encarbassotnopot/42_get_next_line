/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:22:39 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/24 12:02:33 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc < 2)
	{
		printf("Not enough arguments. Usage: "
				"%s filename [filename...]\n",
				argv[0]);
		return (1);
	}
	if (argv[1][0] == '0' && argv[1][1] == '\0')
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	do
	{
		free(line);
		line = get_next_line(fd);
		printf("línia:\t\t %s", line);
	} while (line);
	free(line);
	printf("\n\nwe are so fucking done.\n");
}
