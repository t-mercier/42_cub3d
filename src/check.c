/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 17:29:35 by asaijers      #+#    #+#                 */
/*   Updated: 2023/07/04 17:13:53 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	checktb(t_map *m, size_t z, size_t i)
{
	t_v	*row2;
	int	code;

	code = 0;
	if (z > 0)
	{
		row2 = *(t_v **)vget(m->data, z - 1);
		if (row2->len > i)
			code = !ft_isspace(*(char *)vget(row2, i));
	}
	if (!code)
		exiterr("map hole");
	code = 0;
	if (z < m->data->len - 1)
	{
		row2 = *(t_v **)vget(m->data, z + 1);
		if (row2->len > i)
			code = !ft_isspace(*(char *)vget(row2, i));
	}
	if (!code)
		exiterr("map hole");
}

static void	checklr(t_v *row, size_t i)
{
	int	code;

	code = 0;
	if (i > 0)
		code = !ft_isspace(*(char *)vget(row, i - 1));
	if (!code)
		exiterr("map hole");
	if (i < row->len - 1)
		code = !ft_isspace(*(char *)vget(row, i + 1));
	if (!code)
		exiterr("map hole");
}

static void	checkmisc(t_map *m)
{
	if ((!m->floort && !m->floor.a) || (!m->ceilingt && !m->ceiling.a))
		exiterr("missing floor or ceiling");
	if (!m->cam.z)
		exiterr("no spawn set");
}

void	check(t_map *m)
{
	size_t	z;
	t_v		*row;
	size_t	i;
	char	c;

	z = 0;
	while (z < m->data->len)
	{
		row = *(t_v **)vget(m->data, z);
		i = 0;
		while (i < row->len)
		{
			c = *(char *)vget(row, i);
			if (!ft_isspace(c) && c != '1')
			{
				checklr(row, i);
				checktb(m, z, i);
			}
			i++;
		}
		z++;
	}
	checkmisc(m);
}
