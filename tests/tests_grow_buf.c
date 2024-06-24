/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_grow_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:59:32 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/24 11:28:01 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ready_buffers(char **a_buf, char **b_buf)
{
	if (!a_buf || !b_buf)
		return ;
	if (*a_buf)
		free(*a_buf);
	if (*b_buf)
		free(*b_buf);
	*a_buf = malloc(10);
	*b_buf = malloc(5);
	memset(*a_buf, 'A', 10);
	if (*a_buf)
	memset(*b_buf, 'B', 5);
}

unsigned int	test_grow_buf(void)
{
	char	*a_buf;
	char	*b_buf;
	int		i;

	ready_buffers(&a_buf, &b_buf);
	for (i = 0; i < 10; i++)
		printf("%02x ", a_buf[i]);
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("%02x ", b_buf[i]);
	printf("\n");
	a_buf = grow_buf(a_buf, b_buf, 10, 5);
	for (i = 0; i < 5; i++)
		printf("%02x ", b_buf[i]);
	printf("\n");
	for (i = 0; i < 15; i++)
		printf("%02x ", a_buf[i]);
	printf("\n");
	/**/
	ready_buffers(&a_buf, &b_buf);
	free(a_buf);
	a_buf = grow_buf(NULL, b_buf, 0, 4);
	for (i = 0; i < 5; i++)
		printf("%02x ", b_buf[i]);
	printf("\n");
	for (i = 0; i < 4; i++)
		printf("%02x ", a_buf[i]);
	printf("\n");
	/**/
	ready_buffers(&a_buf, &b_buf);
	a_buf = grow_buf(a_buf, b_buf, 8, 4);
	for (i = 0; i < 5; i++)
		printf("%02x ", b_buf[i]);
	printf("\n");
	for (i = 0; i < 12; i++)
		printf("%02x ", a_buf[i]);
	printf("\n");
	/**/
	ready_buffers(&a_buf, &b_buf);
	a_buf = grow_buf(a_buf, b_buf, 8, 0);
	for (i = 0; i < 8; i++)
		printf("%02x ", a_buf[i]);
	printf("\n");
	char	*c_buf;
	c_buf = grow_buf(malloc(1), b_buf, 0, 2);
	for (i = 0; i < 2; i++)
		printf("%02x ", c_buf[i]);
	printf("\n");
	free(a_buf);
	free(b_buf);
	free(c_buf);
	return (0);
}

int	main(void)
{
	test_grow_buf();
}
