/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   horizontal.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 13:38:18 by tmercier      #+#    #+#                 */
/*   Updated: 2023/07/06 12:20:56 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_textures(t_cub *c, t_ray *r, t_v2i m, t_v2i p)
{
	t_texture	fl;
	t_texture	cl;

	cl.data = c->tx[CEILING].data;
	cl.f = -((p.y - H / 2.) / (H / 2.));
	cl.x = (int)(cl.data->width * (r->map.x - m.x)) & (cl.data->width - 1);
	cl.y = (int)(cl.data->height * (r->map.y - m.y)) & (cl.data->height - 1);
	fl.data = c->tx[FLOOR].data;
	fl.f = ((p.y - H / 2.) / (H / 2.));
	fl.x = (int)(fl.data->width * (r->map.x - m.x)) & (fl.data->width - 1);
	fl.y = (int)(fl.data->height * (r->map.y - m.y)) & (fl.data->height - 1);
	draw(c, p.x, p.y, fl);
	draw(c, p.x, p.y, cl);
}

static t_v2d	raycast(t_cub *c, int y)
{
	double	pz;
	t_v2d	r0;
	t_v2d	r1;
	t_v2d	pos;
	int		p;

	r0.x = c->cam.dir.x - c->cam.fov.x;
	r0.y = c->cam.dir.y - c->cam.fov.y;
	r1.x = c->cam.dir.x + c->cam.fov.x;
	r1.y = c->cam.dir.y + c->cam.fov.y;
	p = (y - H / 2 + c->cam.pitch);
	if (c->cam.floor)
		p = (y - H / 2 - c->cam.pitch);
	pz = (double)H * 0.5;
	c->ray.row = pz / p;
	c->ray.step.y = c->ray.row * (r1.y - r0.y) / W;
	c->ray.step.x = c->ray.row * (r1.x - r0.x) / W;
	pos.x = c->cam.pos.x + c->ray.row * r0.x;
	pos.y = c->cam.pos.y + c->ray.row * r0.y;
	return (pos);
}

void	horizontal(t_cub *c)
{
	t_v2i	p;
	t_ray	ray;
	t_v2i	m;

	ray = (t_ray){};
	p.y = 0;
	while (p.y < H)
	{
		c->cam.floor = false;
		if (p.y > H / 2 + c->cam.pitch)
			c->cam.floor = true;
		p.x = 0;
		ray.map = raycast(c, p.y);
		while (p.x < W)
		{
			m = (t_v2i){ray.map.x, ray.map.y};
			draw_textures(c, &ray, m, p);
			ray.map.x += c->ray.step.x;
			ray.map.y += c->ray.step.y;
			p.x++;
		}
		p.y++;
	}
}
