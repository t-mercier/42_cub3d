/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 17:06:33 by asaijers      #+#    #+#                 */
/*   Updated: 2023/04/17 17:07:22 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftex.h"

char	*argf_str(t_args a, char *k)
{
	int		i;
	char	*v;
	char	*x;

	i = 0;
	while (i < a.ac)
	{
		v = a.av[i];
		x = ft_strchr(v, '=');
		if (x && !ft_strncmp(v, k, x - v))
			return (x + 1);
		i++;
	}
	return (0);
}

t_f64	argf_f64(t_args a, char *k, t_f64 d)
{
	char	*v;

	v = argf_str(a, k);
	if (v)
		return (ft_atof64(v));
	return (d);
}

t_i64	argf_i64(t_args a, char *k, t_i64 d)
{
	char	*v;

	v = argf_str(a, k);
	if (v)
		return (ft_ato64(v));
	return (d);
}
