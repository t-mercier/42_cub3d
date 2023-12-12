/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 16:29:02 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/17 16:31:46 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <sys/_types/_va_list.h>
#include <unistd.h>

int	ft_vfprintf(int fd, const char *fmt, va_list vl)
{
	char	*a;
	int		n;

	a = (char *)fmt;
	n = 0;
	while (*a)
	{
		if (*a == '%')
		{
			a++;
			n += _printf_call(fd, *a, vl);
			if (*a == '%')
				n += write(fd, "%", 1);
		}
		else
			n += write(fd, a, 1);
		if (*a)
			a++;
	}
	return (n);
}

int	ft_fprintf(int fd, const char *fmt, ...)
{
	va_list	v;
	int		r;

	va_start(v, fmt);
	r = ft_vfprintf(fd, fmt, v);
	va_end(v);
	return (r);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	v;
	int		r;

	va_start(v, fmt);
	r = ft_vfprintf(STDOUT_FILENO, fmt, v);
	va_end(v);
	return (r);
}
