/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:07:13 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/23 16:46:32 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	buffered_line_reader(int fd, char **buf)
{
	int	r;
	int	buf_size = BUFFER_SIZE;

	if (!*buf)
	{
		buf_size = 1;
		*buf = malloc(buf_size);
		*buf[buf_size - 1] = '\0';
	}
	else
		buf_size = ft_strlen(*buf) + 1;
	//	*buf = str_plus_one(buf, ++buf_size);
	if (!*buf)
		return (-1);
	r = read(fd, (char *)(*buf + buf_size - 2), 1);
	if (*buf[buf_size - 2] == '\n')
		*buf[buf_size - 2] = '\0';
	else
		*buf[buf_size - 1] = '\0';
	return (r);
}

char	*read_line(int fd)
{
	static char	*buf;
	int		r;

	r = 1;
	buf = malloc(sizeof(void *));
	if (!buf)
		return (NULL);
	while (r > 0)
	{
		r = buffered_line_reader(fd, &buf);
		if (r == 0)
			return (buf);
		if (r < 0)
		{
			return (NULL);
		}
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	if (fd < 0)
		return (NULL);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		printf("Not enough arguments. Usage: "
				"%s filename [filename...]\n",
				argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
		printf("\n\nwe are so fucking done.\n");
}
