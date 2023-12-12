/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v5.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 12:00:24 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/12 14:24:39 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftex.h"
#include <stddef.h>

int	vis_sorted(t_v *v, t_f_compare cmp)
{
	size_t	i;

	i = 0;
	while (++i < v->len)
		if (cmp(vget(v, i), vget(v, i - 1)) > 0)
			return (0);
	return (1);
}

void	*vmax(t_v *v, t_f_compare cmp)
{
	void	*max;
	size_t	i;
	void	*el;

	max = 0;
	i = 0;
	while (i < v->len)
	{
		el = vget(v, i++);
		if (!max || cmp(el, max) > 0)
			max = el;
	}
	return (max);
}

void	*vmin(t_v *v, t_f_compare cmp)
{
	void	*max;
	size_t	i;
	void	*el;

	max = 0;
	i = 0;
	while (i < v->len)
	{
		el = vget(v, i++);
		if (!max || cmp(el, max) < 0)
			max = el;
	}
	return (max);
}

void	vfill(t_v *v, void *e)
{
	size_t	i;

	i = 0;
	while (i < v->len)
		vset(v, i++, e);
}

void	vclear(t_v *v, t_f_dtor f)
{
	vtrunc(v, f, 0);
}
