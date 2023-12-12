/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 15:25:56 by tmercier      #+#    #+#                 */
/*   Updated: 2023/07/06 00:04:49 by root_         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdint.h>

static void	perform_dda(t_cub *c, t_ray *ray)
{
	if (ray->side.x < ray->side.y)
	{
		ray->side.x += ray->delta.x;
		ray->map.x += ray->step.x;
		ray->axis = 0;
		c->wall = EAST;
		if (ray->step.x == -1)
			c->wall = WEST;
	}
	else
	{
		ray->side.y += ray->delta.y;
		ray->map.y += ray->step.y;
		ray->axis = 1;
		c->wall = SOUTH;
		if (ray->step.y == -1)
			c->wall = NORTH;
	}
}

static t_ray	raycast(t_cub *c, double cam_x)
{
	t_ray	r;

	r.dir.x = c->cam.dir.x + c->cam.fov.x * cam_x;
	r.dir.y = c->cam.dir.y + c->cam.fov.y * cam_x;
	r.map = (t_v2d){(int)c->cam.pos.x, (int)c->cam.pos.y};
	r.delta.x = fabs(1 / r.dir.x);
	r.delta.y = fabs(1 / r.dir.y);
	r.step.x = 1;
	r.side.x = (r.map.x + 1. - c->cam.pos.x) * r.delta.x;
	r.step.y = 1;
	r.side.y = (r.map.y + 1. - c->cam.pos.y) * r.delta.y;
	if (r.dir.x < 0)
	{
		r.step.x = -1;
		r.side.x = (c->cam.pos.x - r.map.x) * r.delta.x;
	}
	if (r.dir.y < 0)
	{
		r.step.y = -1;
		r.side.y = (c->cam.pos.y - r.map.y) * r.delta.y;
	}
	return (r);
}

int	walls(t_cub *c, int x)
{
	double	cam_x;
	int		cell;

	cam_x = 2 * x / (double)(W)-1;
	c->ray = raycast(c, cam_x);
	while (1)
	{
		perform_dda(c, &c->ray);
		cell = mapget(c->map, (t_v2i){c->ray.map.x, c->ray.map.y});
		if (cell == '1' || cell == 0)
			break ;
	}
	return (cell);
}
