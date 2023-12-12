/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:10:56 by asaijers      #+#    #+#                 */
/*   Updated: 2022/10/27 21:18:11 by alfa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *s)
{
	size_t	n;
	void	*d;

	n = ft_strlen(s) + 1;
	d = ft_malloc(n);
	if (!d)
		return (0);
	return (ft_memcpy(d, s, n));
}

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	ll;
	size_t	bl;
	long	i;

	ll = ft_strlen(little);
	bl = ft_strlen(big);
	if (!ll)
		return (big);
	if (len > bl)
		len = bl;
	if (!little || bl < ll)
		return (0);
	i = 0;
	while (i <= (long)(len - ll))
	{
		if (*big == *little && !ft_strncmp(big, little, ll))
			return (big);
		big++;
		i++;
	}
	return (0);
}

static inline size_t	min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;

	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	len = min(len, ft_strlen(s + start));
	r = ft_malloc(len + 1);
	if (!r)
		return (0);
	ft_strlcpy(r, s + start, len + 1);
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*r;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	r = ft_malloc(l1 + l2 + 1);
	if (!r)
		return (0);
	ft_memcpy(r, (void *)s1, l1);
	ft_memcpy(r + l1, (void *)s2, l2);
	r[l1 + l2] = 0;
	return (r);
}
