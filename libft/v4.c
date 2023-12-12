/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v4.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 17:28:34 by asaijers      #+#    #+#                 */
/*   Updated: 2023/06/28 21:03:06 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftex.h"
#include <stdio.h>
#include <stdlib.h>

void	*vunshift(t_v *v, void *a)
{
	vgrow(v, 1);
	ft_memmove(v->dat + v->esz, v->dat, (v->len++) * v->esz);
	return (ft_memcpy(v->dat, a, v->esz));
}

void	*vshift(t_v *v)
{
	void	*a;

	a = ft_malloc(v->esz);
	ft_memcpy(a, v->dat, v->esz);
	ft_memmove(v->dat, v->dat + v->esz, (--v->len) * v->esz);
	return (a);
}

void	*vpopc(t_v *v)
{
	return (ft_memcpy(ft_malloc(v->esz), v->dat + --v->len * v->esz, v->esz));
}

static void	hoarde_partition(t_v *v, t_f_compare cmp, int min, int max)
{
	int		i;
	int		j;
	void	*p;

	i = min;
	j = max;
	p = ft_malloc(v->esz);
	ft_memcpy(p, v->dat + (i + j) / 2 * v->esz, v->esz);
	while (i <= j)
	{
		while (cmp(p, vget(v, i)) > 0)
			i++;
		while (cmp(p, vget(v, j)) < 0)
			j--;
		if (i <= j)
			vswap(v, i++, j--);
	}
	free(p);
	if (min < j)
		hoarde_partition(v, cmp, min, j);
	if (i < max)
		hoarde_partition(v, cmp, i, max);
}

void	vquicksort(t_v *v, t_f_compare cmp)
{
	hoarde_partition(v, cmp, 0, v->len - 1);
}
