/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _main.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 15:23:13 by tmercier      #+#    #+#                 */
/*   Updated: 2023/07/06 12:21:15 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>

static void	cleanup(t_cub *c)
{
	size_t	i;

	i = 0;
	mlx_terminate(c->mlx);
	while (i < c->map.data->len)
	{
		vdestroy(*(t_v **)vget(c->map.data, i++));
	}
	vdestroy(c->map.data);
	free(c->map.east);
	free(c->map.north);
	free(c->map.west);
	free(c->map.south);
	free(c->map.floort);
	free(c->map.ceilingt);
}

static void	k_hook(mlx_key_data_t keydata, void *param)
{
	t_cub	*cub;

	cub = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(cub->mlx);
}

static void	loop(void *cub)
{
	t_cub	*c;
	int		x;

	x = 0;
	c = cub;
	horizontal(c);
	while (x < W)
	{
		if (!walls(c, x))
			continue ;
		render(c, x);
		x++;
	}
	keyhooks(c);
	minimap(c);
}

void	f(void)
{
	system("leaks cub3d");
}

int	main(int ac, char **av)
{
	t_cub	cub;
	int		fd;
	size_t	l;

	cub = (t_cub){0};
	if (ac != 2)
		exiterr("usage: ./cub3d map.cub\n");
	l = ft_strlen(av[1]);
	if (ft_strnstr(av[1], ".cub", l) != av[1] + l - 4)
		exiterr("map file needs .cub extension");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exiterr("invalid map file");
	cub.map = parse(fd);
	close(fd);
	gameinit(&cub);
	mlx_loop_hook(cub.mlx, (void *)loop, &cub);
	mlx_key_hook(cub.mlx, k_hook, &cub);
	mlx_loop(cub.mlx);
	cleanup(&cub);
}
