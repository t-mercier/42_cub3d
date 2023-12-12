/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   l2.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 12:41:36 by asaijers      #+#    #+#                 */
/*   Updated: 2023/05/01 16:13:40 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftex.h"

void	leach(t_l *l, void (*f)(t_l *))
{
	while (l)
	{
		f(l);
		l = l->nxt;
	}
}

void	ldestroy(t_l *l, void (*f)(void *))
{
	t_l	*t;

	t = 0;
	while (l)
	{
		t = l;
		l = l->nxt;
		f(t->dat);
		ldtor(t);
	}
}
