/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   l1.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 12:21:07 by asaijers      #+#    #+#                 */
/*   Updated: 2023/07/06 17:03:04 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftex.h"
#include <stdlib.h>

t_l	*lctor(void *dat)
{
	t_l	*l;

	l = ft_malloc(sizeof(t_l));
	l->dat = dat;
	l->prv = 0;
	l->nxt = 0;
	return (l);
}

void	ldtor(t_l *l)
{
	free(l);
}

t_l	*llast(t_l *h)
{
	if (!h)
		return (0);
	while (h->nxt)
		h = h->nxt;
	return (h);
}

void	lpush(t_l **h, t_l *t)
{
	if (!h)
		return ;
	if (!*h)
		*h = t;
	else
		llast(*h)->nxt = t;
}

t_l	*lshift(t_l **h)
{
	t_l	*n;

	if (!h || !*h)
		return (0);
	n = *h;
	*h = n->nxt;
	return (n);
}
