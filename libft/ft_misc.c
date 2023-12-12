/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_misc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:10:47 by asaijers      #+#    #+#                 */
/*   Updated: 2023/06/28 21:16:10 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int	ft_cmp_int_ptr(void *a, void *b)
{
	return ((*(int *)a) - (*(int *)b));
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	exit_message(char *s, int code)
{
	ft_putendl_fd(s, 2);
	exit(code);
}
