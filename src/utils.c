/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 15:22:52 by tmercier      #+#    #+#                 */
/*   Updated: 2023/07/06 12:12:03 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

t_u32	get_color(uint8_t *px, double f)
{
	t_rgba	c;
	int		r;
	int		g;
	int		b;

	f = fmin(f, 2.5);
	r = px[0] * f;
	g = px[1] * f;
	b = px[2] * f;
	c.r = max(min(r, 0xff), 0x00);
	c.g = max(min(g, 0xff), 0x00);
	c.b = max(min(b, 0xff), 0x00);
	c.a = 255;
	return (rgba_to_hex(c));
}

char	mapget(t_map map, t_v2i pos)
{
	t_v		*row;
	char	c;

	if (pos.y >= (int)map.data->len || pos.y < 0)
		return (0);
	row = *(t_v **)vget(map.data, pos.y);
	if (pos.x >= (int)row->len || pos.x < 0)
		return (0);
	c = *(char *)vget(row, pos.x);
	return (c);
}

char	*skipws(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	return (s);
}

void	exiterr(char *fmt, ...)
{
	va_list	v;

	fprintf(stderr, "Error: ");
	va_start(v, fmt);
	vfprintf(stderr, fmt, v);
	va_end(v);
	fprintf(stderr, "\n");
	exit(1);
}

void	draw(t_cub *c, int x, int y, t_texture t)
{
	int		i;
	uint8_t	*px;

	i = (t.data->width * t.y + t.x) * 4;
	px = (uint8_t *)((int *)t.data->pixels) + i;
	t.color = get_color(px, t.f);
	mlx_put_pixel(c->img, x, y, t.color);
}

// void printmap(t_map m) {
//   int i;
//   t_v *row;
//   int j;

//   printf("NO %s\n", m.north);
//   printf("SO %s\n", m.south);
//   printf("WE %s\n", m.west);
//   printf("EA %s\n", m.east);
//   printf("F %x\n", m.floor);
//   printf("C %x\n", m.ceiling);
//   i = 0;
//   while (i < m.data->len) {
//     row = *(t_v **)vget(m.data, i++);
//     j = 0;
//     while (j < row->len)
//       printf("%c", *(char *)vget(row, j++));
//     printf("\n");
//   }
// }
