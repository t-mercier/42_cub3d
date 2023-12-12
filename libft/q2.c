/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   q2.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 13:26:55 by asaijers      #+#    #+#                 */
/*   Updated: 2023/05/01 13:00:08 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftex.h"

void	qclear(t_q *q, void (*f)(void *))
{
	pthread_mutex_lock(&q->m);
	ldestroy(q->l, f);
	q->l = 0;
	pthread_mutex_unlock(&q->m);
}
