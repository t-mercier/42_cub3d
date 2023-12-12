/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:56:22 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/17 16:30:01 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

typedef int	(*t_f_)(int fd, va_list vl);
size_t		_printf_strlen(const char *s);
void		*_printf_memcpy(void *dst, const void *src, size_t n);
char		*_printf_strdup(char *s);
int			ft_printf(const char *fmt, ...);
int			ft_fprintf(int fd, const char *fmt, ...);
int			ft_vfprintf(int fd, const char *fmt, va_list v);

char		*_printf_ultoa(unsigned long n, char *base);
char		*_printf_sltoa(long n, int o, char *base);
int			_printf_hex(int fd, va_list vl);
int			_printf_hexupper(int fd, va_list vl);
int			_printf_dec(int fd, va_list vl);
int			_printf_putstr(int fd, char *s);
int			_printf_call(int fd, char c, va_list vl);
int			_printf_unsigned(int fd, va_list vl);

#endif
