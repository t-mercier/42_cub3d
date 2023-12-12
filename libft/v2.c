/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:10:40 by asaijers      #+#    #+#                 */
/*   Updated: 2023/07/06 17:03:20 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftex.h"
#include <stdio.h>
#include <stdlib.h>

void	*vpush(t_v *v, void *el)
{
	vgrow(v, 1);
	return (ft_memcpy(v->dat + (v->len++) * v->esz, el, v->esz));
}

void	*vpop(t_v *v)
{
	return (v->dat + --v->len * v->esz);
}

void	vswap(t_v *v, int a, int b)
{
	void	*t;

	t = ft_malloc(v->esz);
	ft_memcpy(t, vget(v, a), v->esz);
	ft_memcpy(vget(v, a), vget(v, b), v->esz);
	ft_memcpy(vget(v, b), t, v->esz);
	free(t);
}

t_v	*vcopy(t_v *v)
{
	t_v	*n;

	n = vcreate(v->esz);
	vgrow(n, v->cap);
	n->len = v->len;
	ft_memcpy(n->dat, v->dat, v->len * v->esz);
	return (n);
}

void	*vget(t_v *v, ssize_t i)
{
	if (i < 0)
		i = (v->len + i);
	if ((size_t)i > v->len || i < 0)
		exit_message("Error: vget overflow", 1);
	return (v->dat + i * v->esz);
}
