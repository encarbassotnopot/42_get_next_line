/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:22:39 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/27 11:50:53 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fds[--argc];
	char	*line;
	int		i;
	int		files;

	i = 0;
	line = NULL;
	if (argc < 1)
	{
		printf("Not enough arguments. Usage: "
				"%s filename [filename...]\n",
				argv[0]);
		return (1);
	}
	argv++;
	printf("Buffer Size is %zu.\n", REAL_BUFF);
	while (i < argc)
	{
		if (strlen(argv[i]) == 1 && (argv[i][0] == '0' || argv[i][0] == '1'
				|| argv[i][0] == '2'))
			fds[i] = argv[i][0] - '0';
		else
			fds[i] = open(argv[i], O_RDONLY);
		i++;
	}
	files = i;
	printf("we have %d files\n", files);
	while (files > 0)
	{
		while (i < argc)
		{
			line = get_next_line(fds[i]);
			printf("fd #%i, file \"%s\" línia:\t\t %s", fds[i], argv[i], line);
			if (!line && fds[i] >= 0) {
				printf("\nfd #%i is isn't giving lines, "
					"file \"%s\". removing.\n", fds[i], argv[i]);
					close(fds[i]);
				fds[i] = -1;
				files--;
			}
			free(line);
			i++;
		}
		i = 0;
	}
	printf("\nwe are so fucking done.\n");
	i++;
}
