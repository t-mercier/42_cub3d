/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v6.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 14:23:07 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/12 14:24:08 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftex.h"

void	vtrunc(t_v *v, t_f_dtor f, size_t n)
{
	size_t	i;

	i = n;
	if (f)
		while (i < v->len)
			f(vget(v, i++));
	v->len = n;
}
