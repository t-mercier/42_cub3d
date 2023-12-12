/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 11:03:06 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/17 16:28:24 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int	_printf_char(int fd, va_list vl)
{
	char	c;

	c = va_arg(vl, int);
	write(fd, &c, 1);
	return (1);
}

int	_printf_putstr(int fd, char *s)
{
	return (write(fd, s, _printf_strlen(s)));
}

int	_printf_str(int fd, va_list vl)
{
	char	*s;

	s = va_arg(vl, char *);
	if (!s)
		return (_printf_putstr(fd, "(null)"));
	return (_printf_putstr(fd, s));
}

int	_printf_ptr(int fd, va_list vl)
{
	char	*s;
	int		n;

	s = _printf_ultoa((intptr_t)va_arg(vl, void *), "0123456789abcdef");
	n = _printf_putstr(fd, "0x");
	n += _printf_putstr(fd, s);
	free(s);
	return (n);
}

int	_printf_call(int fd, char c, va_list vl)
{
	t_f_		ff;
	static t_f_	g_f[INT8_MAX];

	g_f['x'] = _printf_hex;
	g_f['X'] = _printf_hexupper;
	g_f['d'] = _printf_dec;
	g_f['i'] = _printf_dec;
	g_f['p'] = _printf_ptr;
	g_f['s'] = _printf_str;
	g_f['c'] = _printf_char;
	g_f['u'] = _printf_unsigned;
	ff = g_f[(int)c];
	if (ff)
		return (ff(fd, vl));
	return (0);
}
