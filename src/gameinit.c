/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gameinit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 12:59:42 by root_         #+#    #+#                 */
/*   Updated: 2023/12/12 01:05:47 by timothee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t	*image(t_cub *c, int element, char *s)
{
	mlx_texture_t	*t;
	mlx_image_t		*i;

	t = mlx_load_png(s);
	if (!t)
	{
		fprintf(stderr, "file: %s\n", s);
		exit(1);
	}
	i = mlx_texture_to_image(c->mlx, t);
	c->tx[element].data = i;
	mlx_delete_texture(t);
	return (i);
}

mlx_image_t	*colorpng(t_cub *c, int el, t_u32 cl)
{
	mlx_image_t	*i;

	i = mlx_new_image(c->mlx, 2, 2);
	mlx_put_pixel(i, 0, 0, cl);
	mlx_put_pixel(i, 0, 1, cl);
	mlx_put_pixel(i, 1, 0, cl);
	mlx_put_pixel(i, 1, 1, cl);
	c->tx[el].data = i;
	return (i);
}

static void	load_png(t_cub *c)
{
	image(c, NORTH, c->map.north);
	image(c, SOUTH, c->map.south);
	image(c, EAST, c->map.east);
	image(c, WEST, c->map.west);
	if (c->map.floort)
		image(c, FLOOR, c->map.floort);
	else
		colorpng(c, FLOOR, rgba_to_hex(c->map.floor));
	if (c->map.ceilingt)
		image(c, CEILING, c->map.ceilingt);
	else
		colorpng(c, CEILING, rgba_to_hex(c->map.ceiling));
}

static void	cam_set_dir(t_cub *c)
{
	if ((char)c->map.cam.z == 'N')
	{
		c->cam.dir = (t_v2d){0, -1};
		c->cam.fov = (t_v2d){-0.66, 0};
	}
	else if ((char)c->map.cam.z == 'E')
	{
		c->cam.dir = (t_v2d){1, 0};
		c->cam.fov = (t_v2d){0, -0.66};
	}
	else if ((char)c->map.cam.z == 'S')
	{
		c->cam.dir = (t_v2d){0, 1};
		c->cam.fov = (t_v2d){0.66, 0};
	}
	else if ((char)c->map.cam.z == 'W')
	{
		c->cam.dir = (t_v2d){-1, 0};
		c->cam.fov = (t_v2d){0, 0.66};
	}
}

void	gameinit(t_cub *c)
{
	c->mlx = mlx_init(W, H, "CUB3D", 0);
	c->img = mlx_new_image(c->mlx, W, H);
	mlx_set_cursor_mode(c->mlx, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(c->mlx, c->img, 0, 0);
	cam_set_dir(c);
	c->cam.pos = (t_v2d){c->map.cam.x + 0.5, c->map.cam.y + 0.5};
	c->cam.pitch = 0;
	load_png(c);
}
