/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 14:00:46 by tmercier      #+#    #+#                 */
/*   Updated: 2023/07/06 12:21:35 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rect(mlx_image_t *img, t_v2i n1, t_v2i n2, t_u32 corr)
{
	t_u32	*p;
	int		x;
	int		y;

	x = n1.x;
	p = (t_u32 *)img->pixels;
	while (x < n2.x)
	{
		if (x < 0)
			continue ;
		if (x > (int)img->width)
			break ;
		y = n1.y;
		while (y < n2.y)
		{
			if (y < 0)
				continue ;
			if (y > (int)img->height)
				break ;
			mlx_put_pixel(img, x, y, (UINT_MAX - p[y * img->width + x] - corr));
			y++;
		}
		x++;
	}
}

static void	draw_rect(t_cub *c, t_v2i *d, t_v2i p1)
{
	int		cell;
	t_v2i	n1;
	t_v2i	n2;
	int		start;

	start = (TILE * (RANGE - 1));
	n1 = (t_v2i){(start + d->x * TILE) + 25, (start + d->y * TILE) + 25};
	n2 = (t_v2i){n1.x + TILE, n1.y + TILE};
	cell = mapget(c->map, p1);
	if (cell == '1')
		rect(c->img, n1, n2, 0x323232ff);
	if (!d->x && !d->y)
	{
		rect(c->img, n1, n2, 0x0);
		n1.x += TILE / 2;
		n1.y += TILE / 2;
		n2.y = n1.y + (TILE / 2.) * c->cam.dir.y;
		n2.x = n1.x + (TILE / 2.) * c->cam.dir.x;
		line(c->img, n1, n2, 0xff0000ff);
	}
}

void	minimap(t_cub *c)
{
	t_v2i	p1;
	t_v2i	p2;
	t_v2i	d;
	t_v2i	p;

	p = (t_v2i){floor(c->cam.pos.x), floor(c->cam.pos.y)};
	p1 = (t_v2i){(p.x - RANGE), (p.y - RANGE)};
	p2 = (t_v2i){(p.x + RANGE), (p.y + RANGE)};
	d = (t_v2i){(-RANGE), -RANGE};
	while (p1.y < p2.y)
	{
		p1.x = p.x - RANGE;
		d.x = -RANGE;
		while (p1.x < p2.x)
		{
			draw_rect(c, &d, p1);
			p1.x++;
			d.x++;
		}
		p1.y++;
		d.y++;
	}
}
