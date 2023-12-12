/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_to2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 14:07:06 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/17 17:05:50 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include <stdint.h>

int64_t	ft_ato64(const char *s)
{
	int64_t	n;
	int		o;

	n = 0;
	while (*s && ft_isspace(*s))
		s++;
	o = 0;
	if (*s == '-')
		o = 1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s && ft_isdigit(*s))
	{
		n *= 10;
		n += *s - '0';
		s++;
	}
	if (o)
		return (-n);
	return (n);
}

double	_ft_atof64_inner(char *x, double r, double o, double s)
{
	int	e;

	e = 0;
	while (*x && ft_isspace(*x))
		x++;
	if (*x == '-')
		o = -1;
	if (*x == '-' || *x == '+')
		x++;
	while (*x && ft_isdigit(*x))
		r = r * 10 + (*x++ - '0');
	if (*x == '.')
	{
		x++;
		while (*x && ft_isdigit(*x))
		{
			r = r * 10 + (*x++ - '0');
			s *= 10;
		}
	}
	r *= o / s * pow(10, e);
	return (r);
}

double	ft_atof64(char *x)
{
	double	r;
	double	o;
	double	s;

	r = 0;
	o = 1;
	s = 1;
	return (_ft_atof64_inner(x, r, o, s));
}
