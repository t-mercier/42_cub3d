/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 13:43:30 by tmercier      #+#    #+#                 */
/*   Updated: 2023/12/12 01:06:26 by timothee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	textures(t_cub *c)
{
	t_texture	texture;
	int			half_w;
	int			half_img;

	half_img = (double)H / 2;
	half_w = (double)c->ray.height / 2;
	texture = c->tx[c->wall];
	c->ray.wallx = c->cam.pos.x + c->ray.dist * c->ray.dir.x;
	if (c->ray.axis == 0)
		c->ray.wallx = c->cam.pos.y + c->ray.dist * c->ray.dir.y;
	c->ray.wallx -= floor(c->ray.wallx);
	texture.x = c->ray.wallx * texture.data->width;
	if (c->ray.axis == 0 && c->ray.dir.x > 0)
		texture.x = texture.data->width - texture.x - 1;
	if (c->ray.axis == 1 && c->ray.dir.y < 0)
		texture.x = texture.data->width - texture.x - 1;
	texture.step = 1.0 * texture.data->height / c->ray.height;
	texture.pos = (c->render.p1.y - c->cam.pitch - half_img + half_w);
	texture.pos *= texture.step;
	return (texture);
}

static void	draw_walls(t_cub *c, int x, t_texture t)
{
	int		y;

	y = c->render.p1.y;
	t.el = WALLS;
	while (y < c->render.p2.y)
	{
		t.y = (int)t.pos & (t.data->height - 1);
		t.pos += t.step;
		t.f = 1 / c->ray.dist;
		draw(c, x, y, t);
		y++;
	}
}

void	render(t_cub *c, int x)
{
	int			half;
	t_texture	t;

	c->ray.dist = c->ray.side.y - c->ray.delta.y;
	if (c->ray.axis == 0)
		c->ray.dist = c->ray.side.x - c->ray.delta.x;
	c->ray.height = H / c->ray.dist;
	half = c->ray.height / 2;
	c->render.p1 = (t_v2i){x, -half + H / 2. + c->cam.pitch};
	c->render.p2 = (t_v2i){x, half + H / 2. + c->cam.pitch};
	if (c->render.p1.y < 0)
		c->render.p1.y = 0;
	if (c->render.p2.y >= H)
		c->render.p2.y = H - 1;
	t = textures(c);
	t.data = c->tx[c->wall].data;
	draw_walls(c, x, t);
	vertical(c, x, t);
}
