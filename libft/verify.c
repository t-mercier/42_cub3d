/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verify.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 16:20:33 by asaijers      #+#    #+#                 */
/*   Updated: 2023/07/04 14:25:35 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftex.h"
#include <limits.h>
#include <stdint.h>

int	ft_isintn(char *s, size_t n)
{
	char	*t;
	t_i64	v;

	t = s;
	if (!n)
		return (0);
	if (*s == '-' || *s == '+')
	{
		s++;
		n--;
	}
	while (*s && n--)
		if (!ft_isdigit(*s++))
			return (0);
	v = ft_ato64(t);
	if (v > INT32_MAX || v < INT32_MIN)
		return (0);
	return (1);
}

int	ft_isint(char *s)
{
	return (ft_isintn(s, ft_strlen(s)));
}

int	ft_isucharn(char *s, size_t n)
{
	char	*t;
	t_i64	v;

	t = s;
	if (!n)
		return (0);
	if (*s == '-' || *s == '+')
	{
		s++;
		n--;
	}
	while (*s && n--)
		if (!ft_isdigit(*s++))
			return (0);
	v = ft_ato64(t);
	if (v > UCHAR_MAX || v < 0)
		return (0);
	return (1);
}

int	ft_isuchar(char *s)
{
	return (ft_isucharn(s, ft_strlen(s)));
}
