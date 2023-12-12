/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vertical.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 21:42:41 by root_         #+#    #+#                 */
/*   Updated: 2023/07/06 11:48:44 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling(t_cub *c, int x, t_texture t, t_horizon *h)
{
	uint8_t	*px;
	int		i;
	int		y;
	double	weight;

	y = 0;
	h->dist = c->ray.dist;
	while (y < c->render.p1.y)
	{
		h->half = H / 2.;
		h->curr.x = H / (H - 2.0 * (y - c->cam.pitch));
		weight = (h->curr.x) / (h->dist);
		h->pos.x = weight * h->wall.x + (1.0 - weight) * c->cam.pos.x;
		h->pos.y = weight * h->wall.y + (1.0 - weight) * c->cam.pos.y;
		t.data = c->tx[CEILING].data;
		t.x = (int)(h->pos.x * t.data->width) & (t.data->width - 1);
		t.y = (int)(h->pos.y * t.data->height) & (t.data->height - 1);
		i = (t.data->width * t.y + t.x) * 4;
		px = (uint8_t *)((int *)t.data->pixels) + i;
		t.f = -((y - h->half - c->cam.pitch) / (h->half));
		t.color = get_color(px, t.f);
		mlx_put_pixel(c->img, x, y, t.color);
		y++;
	}
}

static void	draw_floor(t_cub *c, int x, t_texture t, t_horizon *h)
{
	uint8_t	*px;
	int		i;
	int		y;
	double	weight;

	y = c->render.p2.y;
	while (y < H)
	{
		h->curr.x = H / (2.0 * (y - c->cam.pitch) - H);
		h->half = H / 2.;
		weight = (h->curr.x) / (h->dist);
		h->pos.x = weight * h->wall.x + (1.0 - weight) * c->cam.pos.x;
		h->pos.y = weight * h->wall.y + (1.0 - weight) * c->cam.pos.y;
		t.data = c->tx[FLOOR].data;
		t.x = (int)(h->pos.x * t.data->width) & (t.data->width - 1);
		t.y = (int)(h->pos.y * t.data->height) & (t.data->height - 1);
		i = (t.data->width * t.y + t.x) * 4;
		px = (uint8_t *)((int *)t.data->pixels) + i;
		t.f = ((y - h->half - c->cam.pitch) / (h->half));
		t.color = get_color(px, t.f);
		mlx_put_pixel(c->img, x, y, t.color);
		y++;
	}
}

void	vertical(t_cub *c, int x, t_texture t)
{
	t_horizon	h;

	if (c->ray.axis == 0 && c->ray.dir.x > 0)
	{
		h.wall.x = c->ray.map.x;
		h.wall.y = c->ray.map.y + c->ray.wallx;
	}
	else if (c->ray.axis == 0 && c->ray.dir.x < 0)
	{
		h.wall.x = c->ray.map.x + 1.0;
		h.wall.y = c->ray.map.y + c->ray.wallx;
	}
	else if (c->ray.axis == 1 && c->ray.dir.y > 0)
	{
		h.wall.x = c->ray.map.x + c->ray.wallx;
		h.wall.y = c->ray.map.y;
	}
	else
	{
		h.wall.x = c->ray.map.x + c->ray.wallx;
		h.wall.y = c->ray.map.y + 1.0;
	}
	draw_ceiling(c, x, t, &h);
	draw_floor(c, x, t, &h);
}
