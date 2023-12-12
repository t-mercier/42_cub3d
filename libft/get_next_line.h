/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:34:10 by asaijers      #+#    #+#                 */
/*   Updated: 2022/10/27 21:17:37 by alfa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stddef.h>
# include <stdio.h>

typedef struct s_gnl
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bl;
	ssize_t	dx;
	int		ofd;
	char	*line;
	size_t	odx;
	char	*a;
	int		nl;
	int		fd;
}			t_gnl;

void		*_gnl_memcpy(void *dst, void *src, size_t n);
size_t		_gnl_strlen(const char *s);
void		*_gnl_fake_realloc(void *p, size_t on, size_t n);
char		*get_next_line(int fd);

#endif