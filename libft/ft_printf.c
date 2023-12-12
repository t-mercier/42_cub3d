/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:39:13 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/17 16:29:49 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int	_printf_hex(int fd, va_list vl)
{
	unsigned int	p;
	char			*s;
	int				n;

	p = va_arg(vl, unsigned int);
	s = _printf_ultoa(p, "0123456789abcdef");
	n = _printf_putstr(fd, s);
	free(s);
	return (n);
}

int	_printf_hexupper(int fd, va_list vl)
{
	unsigned int	p;
	char			*s;
	int				n;

	p = va_arg(vl, unsigned int);
	s = _printf_ultoa(p, "0123456789ABCDEF");
	n = _printf_putstr(fd, s);
	free(s);
	return (n);
}

int	_printf_dec(int fd, va_list vl)
{
	int		a;
	char	*s;
	int		n;

	a = va_arg(vl, int);
	s = _printf_sltoa(a, 0, "0123456789");
	n = _printf_putstr(fd, s);
	free(s);
	return (n);
}

int	_printf_unsigned(int fd, va_list vl)
{
	unsigned int	a;
	char			*s;
	int				n;

	a = va_arg(vl, unsigned int);
	s = _printf_sltoa(a, 0, "0123456789");
	n = _printf_putstr(fd, s);
	free(s);
	return (n);
}
