/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 14:49:28 by asaijers      #+#    #+#                 */
/*   Updated: 2023/06/28 21:02:42 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftex.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t	vindexof(t_v *v, void *e, t_f_compare cmp)
{
	size_t	i;

	i = 0;
	while (i < v->len)
	{
		if (cmp(vget(v, i), e) == 0)
			return (i);
		i++;
	}
	return (-1);
}

// add n * v.esz bytes of d to the end of v
void	vconcat(t_v *v, void *d, size_t n)
{
	vgrow(v, n);
	ft_memcpy(v->dat + v->len * v->esz, d, n * v->esz);
}

void	vdestroy(t_v *v)
{
	free(v->dat);
	free(v);
	v = NULL;
}

void	*vset(t_v *v, size_t i, void *el)
{
	return (ft_memcpy(v->dat + i * v->esz, el, v->esz));
}

void	*vdelfast(t_v *v, size_t i)
{
	if (i < 0 || i >= v->len)
		return (0);
	vswap(v, i, v->len - 1);
	return (vpop(v));
}
