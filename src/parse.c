/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:39:19 by asaijers      #+#    #+#                 */
/*   Updated: 2023/07/06 16:15:27 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_rgba	color(char *s)
{
	t_rgba	c;

	c = (t_rgba){0, 0, 0, 255};
	s = skipws(s);
	if (!ft_strchr(s, ',') || !ft_isucharn(s, ft_strchr(s, ',') - s))
		exiterr("invalid color 1");
	c.r = ft_atoi(s);
	s = ft_strchr(s, ',') + 1;
	if (!ft_strchr(s, ',') || !ft_isucharn(s, ft_strchr(s, ',') - s))
		exiterr("invalid color 2");
	c.g = ft_atoi(s);
	s = ft_strchr(s, ',') + 1;
	if (!ft_isucharn(s, ft_strchr(s, '\n') - s))
		exiterr("invalid color 3");
	c.b = ft_atoi(s);
	return (c);
}

static char	*path(char *x, char **y)
{
	char	*s;
	char	*r;

	s = x;
	while (*x && !ft_isspace(*x))
		x++;
	r = ft_malloc(x - s + 1);
	ft_memcpy(r, s, x - s);
	r[x - s] = 0;
	if (*y)
		free(*y);
	*y = r;
	return (r);
}

static int	elements(t_map *m, char *s)
{
	if (!ft_strncmp(s, "NO", 2))
		path(skipws(s + 2), &m->north);
	else if (!ft_strncmp(s, "SO", 2))
		path(skipws(s + 2), &m->south);
	else if (!ft_strncmp(s, "WE", 2))
		path(skipws(s + 2), &m->west);
	else if (!ft_strncmp(s, "EA", 2))
		path(skipws(s + 2), &m->east);
	else if (*s == 'F')
	{
		if (ft_strchr(s, ','))
			m->floor = color(s + 1);
		else
			path(skipws(s + 1), &m->floort);
	}
	else if (*s == 'C')
	{
		if (ft_strchr(s, ','))
			m->ceiling = color(s + 1);
		else
			path(skipws(s + 1), &m->ceilingt);
	}
	else
		return (0);
	return (1);
}

static void	parse_map(t_map *m, char *s, int i)
{
	t_v		*row;
	char	*x;

	row = vcreate(sizeof(char));
	vpush(m->data, &row);
	x = s;
	while (*x && (ft_strchr("10NSEW", *x) || ft_isspace(*x)))
	{
		if (ft_strchr("NSEW", *x))
		{
			if (m->cam.z)
				exiterr("spawn already set");
			m->cam = (t_v3i){x - s, i, *x};
		}
		vpush(row, x++);
	}
	if (*x != '\n' && *x != 0)
		exiterr("map invalid char %c %d+%d, '%s'+'%s'", *x, i, x - s, x, s);
}

t_map	parse(int fd)
{
	char	*s;
	t_map	m;
	int		i;

	m = (t_map){.data = vcreate(sizeof(t_v *))};
	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		if (*s == EOF)
			return (free(s), m);
		if (!elements(&m, s))
		{
			if (ft_strlen(skipws(s)))
				parse_map(&m, s, i++);
			else if (i)
				exiterr("empty line in map");
		}
		free(s);
		s = get_next_line(fd);
	}
	return (check(&m), m);
}
