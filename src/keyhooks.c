/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyhooks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 15:27:50 by tmercier      #+#    #+#                 */
/*   Updated: 2023/07/06 12:06:14 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	look_up_down(t_cub *c, double speed)
{
	if (mlx_is_key_down(c->mlx, MLX_KEY_DOWN))
	{
		c->cam.pitch -= (400 * speed);
		if (c->cam.pitch < -200)
			c->cam.pitch = -200;
	}
	if (mlx_is_key_down(c->mlx, MLX_KEY_UP))
	{
		c->cam.pitch += (400 * speed);
		if (c->cam.pitch > 200)
			c->cam.pitch = 200;
	}
	if (c->cam.pitch > 0)
		c->cam.pitch = max(0, c->cam.pitch - 100 * speed);
	if (c->cam.pitch < 0)
		c->cam.pitch = min(0, c->cam.pitch + 100 * speed);
}

static void	rotate(t_cub *c, double speed)
{
	double	dir_x;
	double	fov_x;

	if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
	{
		dir_x = c->cam.dir.x;
		c->cam.dir.x = c->cam.dir.x * cos(-speed) - c->cam.dir.y * sin(-speed);
		c->cam.dir.y = dir_x * sin(-speed) + c->cam.dir.y * cos(-speed);
		fov_x = c->cam.fov.x;
		c->cam.fov.x = c->cam.fov.x * cos(-speed) - c->cam.fov.y * sin(-speed);
		c->cam.fov.y = fov_x * sin(-speed) + c->cam.fov.y * cos(-speed);
	}
	else if (mlx_is_key_down(c->mlx, MLX_KEY_LEFT))
	{
		dir_x = c->cam.dir.x;
		c->cam.dir.x = c->cam.dir.x * cos(speed) - c->cam.dir.y * sin(speed);
		c->cam.dir.y = dir_x * sin(speed) + c->cam.dir.y * cos(speed);
		fov_x = c->cam.fov.x;
		c->cam.fov.x = c->cam.fov.x * cos(speed) - c->cam.fov.y * sin(speed);
		c->cam.fov.y = fov_x * sin(speed) + c->cam.fov.y * cos(speed);
	}
}

static void	left_right(t_cub *c, double speed)
{
	t_v2d	npos;

	if (mlx_is_key_down(c->mlx, MLX_KEY_A))
	{
		npos.x = c->cam.pos.x - c->cam.dir.y * speed;
		npos.y = c->cam.pos.y + c->cam.dir.x * speed;
		if (mapget(c->map, (t_v2i){npos.x, npos.y}) != '1')
			c->cam.pos = (t_v2d){npos.x, npos.y};
	}
	else if (mlx_is_key_down(c->mlx, MLX_KEY_D))
	{
		npos.x = c->cam.pos.x + c->cam.dir.y * speed;
		npos.y = c->cam.pos.y - c->cam.dir.x * speed;
		if (mapget(c->map, (t_v2i){npos.x, npos.y}) != '1')
			c->cam.pos = (t_v2d){npos.x, npos.y};
	}
}

static void	front_back(t_cub *c, double speed)
{
	t_v2d	npos;

	if (mlx_is_key_down(c->mlx, MLX_KEY_W))
	{
		npos.x = c->cam.pos.x + c->cam.dir.x * speed;
		npos.y = c->cam.pos.y + c->cam.dir.y * speed;
		if (mapget(c->map, (t_v2i){npos.x, npos.y}) != '1')
			c->cam.pos = (t_v2d){npos.x, npos.y};
	}
	else if (mlx_is_key_down(c->mlx, MLX_KEY_S))
	{
		npos.x = c->cam.pos.x - c->cam.dir.x * speed;
		npos.y = c->cam.pos.y - c->cam.dir.y * speed;
		if (mapget(c->map, (t_v2i){npos.x, npos.y}) != '1')
			c->cam.pos = (t_v2d){npos.x, npos.y};
	}
}

void	keyhooks(t_cub *c)
{
	static double	ts;
	double			ots;
	double			ft;
	t_v2d			speed;

	if (!ts)
		ts = getts();
	ots = ts;
	ts = getts();
	ft = (ts - ots) / 1000;
	speed = (t_v2d){ft * 3.5, ft * 2};
	rotate(c, speed.y);
	front_back(c, speed.x);
	left_right(c, speed.x);
	look_up_down(c, speed.x);
}
