/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str4.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 14:06:16 by asaijers      #+#    #+#                 */
/*   Updated: 2023/03/13 13:23:13 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*r;
	const char	*a;
	char		*q;

	r = ft_malloc(ft_strlen(s) + 1);
	if (!r)
		return (0);
	q = r;
	a = s;
	while (*a)
	{
		*r++ = f(a - s, *a);
		a++;
	}
	*r = 0;
	return (q);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*a;

	a = s;
	while (*a)
	{
		f(a - s, a);
		a++;
	}
}

static char	*_ft_strtrim(char const *s1, char const *set, const char *a,
		const char *b)
{
	size_t		l1;
	const char	*c;

	l1 = ft_strlen(s1);
	a = s1;
	b = s1 + l1;
	while (*a)
	{
		c = set;
		while (*c && *c != *a)
			c++;
		if (!*c)
			break ;
		a++;
	}
	while (b > a)
	{
		c = set;
		while (*c && *c != *b)
			c++;
		if (!*c && *b)
			break ;
		b--;
	}
	return (ft_substr(s1, a - s1, b + 1 - a));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	return (_ft_strtrim(s1, set, 0, 0));
}

char	**ft_split(char const *s, char c)
{
	int	z;

	return (ft_splitz(s, c, &z));
}
