/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:15:21 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/23 21:33:54 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

char	*ft_memmove(char *s, size_t n)
{
	size_t	count;
	char	*dst;

	if (!s)
		return (NULL);
	dst = malloc(n);
	if (!dst)
		return (NULL);
	count = 0;
	while (count < n)
	{
		dst[count] = s[count];
		count++;
	}
	return (dst);
}

int	ft_memchr_idx(const char *s, int c, size_t n)
{
	int				idx;
	int				len;
	char			*my_str;
	unsigned char	my_chr;

	len = (int)n;
	idx = 0;
	if (!s)
		return (-1);
	my_str = (char *)s;
	my_chr = (unsigned char)c;
	while (my_str[idx] != my_chr && idx < len)
		idx++;
	if (idx == len)
		return (-1);
	return (idx);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*my_src;
	char	*my_dest;

	if (!dest || !src)
		return (dest);
	my_src = (char *)src;
	my_dest = dest;
	i = 0;
	while (i < n)
	{
		my_dest[i] = my_src[i];
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*out;

	if (SIZE_MAX / nmemb < size)
		return (NULL);
	total = nmemb * size;
	out = malloc(total);
	if (!out)
		return (NULL);
	ft_bzero(out, total);
	return (out);
}

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*my_ptr;

	if (!ptr)
		return ;
	i = 0;
	my_ptr = ptr;
	while (i < n)
	{
		my_ptr[i++] = 0;
	}
}
