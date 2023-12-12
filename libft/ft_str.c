/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:06:52 by asaijers      #+#    #+#                 */
/*   Updated: 2022/10/27 21:18:11 by alfa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	a = (char *)s;
	while (*a)
	{
		if (*a == (char)c)
			return (a);
		a++;
	}
	if (!(char)c)
		return (a);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = (char *)s;
	a += ft_strlen(s);
	while (a >= s)
	{
		if (*a == (char)c)
			return (a);
		a--;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	const char	*a;

	a = s;
	while (*s)
		s++;
	return (s - a);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	while (n && *s1 && (*s2 == *s1))
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t	ft_strnlen(const char *s, size_t n)
{
	const char	*a;

	a = s;
	while (*s && n)
	{
		s++;
		n--;
	}
	return (s - a);
}
