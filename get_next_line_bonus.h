/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:55:02 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/24 17:54:08 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# include <stddef.h>

char					*grow_buf(char *old_buf, char *new_buf, size_t buf_size,
							size_t extra_size);
int						get_next_buffer(int fd, char **leftovers,
							size_t *leftover_size);
char					*get_next_line(int fd);
char					*ft_strchr(const char *s, int c);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
void					ft_bzero(void *ptr, size_t n);
char					*ft_memdup(char *s, size_t n);
int						ft_memchr_idx(const char *s, int c, size_t n);
typedef struct s_fd_list
{
	int					fd;
	size_t				leftover_size;
	char				*leftovers;
	struct s_fd_list	*next;
}						t_fd_list;
#endif
