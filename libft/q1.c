/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   q1.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 13:28:31 by asaijers      #+#    #+#                 */
/*   Updated: 2023/07/06 17:03:11 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftex.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	qadd(t_q *q, void *e)
{
	pthread_mutex_lock(&q->m);
	lpush(&q->l, lctor(ft_memcpy(ft_malloc(q->s), e, q->s)));
	pthread_mutex_unlock(&q->m);
}

void	*qtake(t_q *q)
{
	void	*e;
	t_l		*n;

	e = 0;
	pthread_mutex_lock(&q->m);
	n = lshift(&q->l);
	if (n)
	{
		e = n->dat;
		ldtor(n);
	}
	pthread_mutex_unlock(&q->m);
	return (e);
}

int	qempty(t_q *q)
{
	int	r;

	pthread_mutex_lock(&q->m);
	r = !q->l;
	pthread_mutex_unlock(&q->m);
	return (r);
}

t_q	*qcreate(size_t esz)
{
	t_q	*q;

	q = ft_malloc(sizeof(t_q));
	q->s = esz;
	q->l = 0;
	pthread_mutex_init(&q->m, 0);
	return (q);
}

void	qdestroy(t_q *q)
{
	pthread_mutex_destroy(&q->m);
	ldestroy(q->l, free);
	free(q);
}
