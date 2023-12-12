/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:11:01 by asaijers      #+#    #+#                 */
/*   Updated: 2023/03/13 13:23:20 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	sl;

	sl = ft_strlen(src);
	if (!n)
		return (sl);
	while (n-- > 1 && *src)
		*dst++ = *src++;
	*dst = 0;
	return (sl);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dl;
	size_t	sl;

	dl = ft_strnlen(dst, n);
	sl = ft_strlen(src);
	if (dl == n)
		return (n + ft_strlen(src));
	if (sl < n - dl)
	{
		ft_memcpy(dst + dl, src, sl + 1);
	}
	else
	{
		ft_memcpy(dst + dl, src, n - dl - 1);
		dst[n - 1] = 0;
	}
	return (sl + dl);
}

static char	**alloc_split(const char *s, char c, int *z)
{
	int			i;
	const char	*b;

	if (!s)
		return (0);
	i = 0;
	b = s;
	while (*s)
	{
		b = s;
		while (*b && *b != c)
			b++;
		if (b != s)
		{
			i++;
			s = b;
		}
		while (*s && *s == c)
			s++;
	}
	*z = i;
	return (ft_calloc(i + 1, sizeof(char *)));
}

static char	**free_split(char **a)
{
	char	**x;

	x = a;
	while (*x)
		free(*x++);
	free(a);
	return (0);
}

char	**ft_splitz(char const *s, char c, int *z)
{
	char		**a;
	char		**r;
	const char	*b;

	a = alloc_split(s, c, z);
	if (!a)
		return (0);
	r = a;
	while (*s)
	{
		b = s;
		while (*b && *b != c)
			b++;
		if (b != s)
		{
			*a = ft_substr(s, 0, b - s);
			if (!*a++)
				return (free_split(r));
			s = b;
		}
		while (*s && *s == c)
			s++;
	}
	return (r);
}
