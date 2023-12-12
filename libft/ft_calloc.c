/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:09:07 by asaijers      #+#    #+#                 */
/*   Updated: 2023/07/06 17:01:43 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#ifndef LIBFT_NO_MALLOC

void	*ft_malloc(size_t n)
{
	void	*a;

	a = malloc(n);
	if (!a)
		exit_message("error: malloc", 1);
	return (a);
}
#endif

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	a = ft_malloc(nmemb * size);
	ft_bzero(a, nmemb * size);
	return (a);
}
