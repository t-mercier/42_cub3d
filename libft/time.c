/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:08:31 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/24 14:15:32 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftex.h"
#include <sys/time.h>

uint64_t	getts(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_usec / 1000 + tv.tv_sec * (uint64_t)1000);
}
