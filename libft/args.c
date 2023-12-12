/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 13:43:23 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/17 17:06:48 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftex.h"

t_args	get_args(int ac, char **av)
{
	t_args	a;

	a.ac = ac;
	a.av = av;
	return (a);
}

char	*argn_str(t_args a, int n)
{
	int		i;
	int		j;
	char	*v;
	char	*x;

	i = 0;
	j = 0;
	while (i < a.ac)
	{
		v = a.av[i];
		x = ft_strchr(v, '=');
		if (!x)
		{
			if (j == n)
				return (v);
			j++;
		}
		i++;
	}
	return (0);
}

char	argn_char_enum(t_args a, int n, char *e)
{
	char	*v;

	v = argn_str(a, n);
	if (!v)
		return (0);
	while (*e)
		if (*e++ == *v)
			return (*v);
	return (0);
}

t_f64	argn_f64(t_args a, int n, t_f64 d)
{
	char	*v;

	v = argn_str(a, n);
	if (v)
		return (ft_atof64(v));
	return (d);
}

t_i64	argn_i64(t_args a, int n, t_i64 d)
{
	char	*v;

	v = argn_str(a, n);
	if (v)
		return (ft_ato64(v));
	return (d);
}
