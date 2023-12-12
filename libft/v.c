/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:56:49 by asaijers      #+#    #+#                 */
/*   Updated: 2023/06/28 21:15:09 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftex.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

t_v	*vcreate(size_t esz)
{
	t_v	*v;

	v = ft_malloc(sizeof(t_v));
	v->len = 0;
	v->cap = 2;
	v->esz = esz;
	v->dat = ft_calloc(v->cap, v->esz);
	if (!v->dat)
	{
		free(v);
		return (0);
	}
	return (v);
}

static size_t	_round_up_to_multiple_of_2(size_t v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v |= v >> 32;
	return (++v);
}

void	*ft_realloc(void *d, size_t on, size_t n)
{
	void	*z;

	z = ft_malloc(n);
	if (on)
		ft_memcpy(z, d, on);
	free(d);
	return (z);
}

void	vgrow(t_v *v, size_t n)
{
	size_t	ocap;
	size_t	osz;
	size_t	sz;

	if (!v || v->len + n <= v->cap)
		return ;
	ocap = v->cap;
	osz = ocap * v->esz;
	v->cap = _round_up_to_multiple_of_2(v->len + n);
	sz = v->cap * v->esz;
	v->dat = ft_realloc(v->dat, osz, sz);
}
