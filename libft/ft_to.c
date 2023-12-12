/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_to.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:11:08 by asaijers      #+#    #+#                 */
/*   Updated: 2023/03/14 14:08:26 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}

int	ft_atoi(const char *s)
{
	return ((int)ft_ato64(s));
}

static char	*_ft_itoa(long long n, int o)
{
	static char	_x[12];
	char		*x;

	x = _x;
	x += 11;
	*x-- = 0;
	o = 0;
	if (n < 0)
	{
		o = 1;
		n = -n;
	}
	if (!n)
		*x-- = '0';
	while (n)
	{
		*x-- = '0' + n % 10;
		n /= 10;
	}
	if (o)
		*x-- = '-';
	x++;
	return (x);
}

char	*ft_itoa(int n)
{
	return (_ft_itoa(n, 0));
}
