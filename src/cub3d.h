/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root_ <root_@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 15:22:33 by tmercier      #+#    #+#                 */
/*   Updated: 2023/07/06 12:21:00 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../libft/libftex.h"
# include "string.h"
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/fcntl.h>

# define W 800
# define H 600
# define TILE 10
# define RANGE 5
# define PA 45

typedef struct s_map		t_map;
typedef struct s_rgba		t_rgba;
typedef struct s_ray		t_ray;
typedef struct s_texture	t_texture;
typedef struct s_render		t_render;
typedef struct s_el			t_el;
typedef struct s_cam		t_cam;
typedef struct s_cub		t_cub;
typedef struct s_grid		t_grid;
typedef struct s_bresenham	t_bresenham;
typedef struct s_horizon	t_horizon;

typedef int					(*t_f_compare)(void *a, void *b);

enum						e_tx
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR,
	CEILING,
	N,
	WALLS,
};

enum						e_world
{
	BUNKER,
	MADHOUSE,
	CASTLE,
	BONUS,
};

enum						e_key
{
	KEY_W,
	KEY_S,
	KEY_A,
	KEY_D,
	RIGHT,
	LEFT,
	UP,
	DOWN,
};

struct						s_grid
{
	t_v3i					size;
	t_v2d					cursor;
	t_v2i					p1;
	t_v2i					p2;
	t_v2i					pos;
	int						x;
	int						y;
};

struct						s_rgba
{
	t_u8					r;
	t_u8					g;
	t_u8					b;
	t_u8					a;
};

struct						s_render
{
	int						x;
	int						y;
	t_v2i					p1;
	t_v2i					p2;
};

struct						s_bresenham
{
	t_v2i					d;
	t_v2i					s;
	int						e;
	int						e2;
};

struct						s_cam
{
	t_v2d					fov;
	t_v2d					dir;
	t_v2d					pos;
	double					pitch;
	bool					floor;
};

struct						s_horizon
{
	t_v2d					wall;
	t_v2d					cam;
	t_v2d					curr;
	double					half;
	double					weight;
	double					dist;
	t_v2d					pos;
};

struct						s_ray
{
	t_v2d					p;
	t_v2d					dir;
	t_v2d					delta;
	t_v2d					side;
	t_v2d					step;
	t_v2d					map;
	int						axis;
	int						height;
	double					row;
	double					dist;
	double					x;
	double					y;
	double					wallx;
	double					dark_floor;
	double					dark_ceiling;
};

struct						s_map
{
	t_v						*data;
	char					*north;
	char					*south;
	char					*west;
	char					*east;
	t_rgba					floor;
	t_rgba					ceiling;
	char					*ceilingt;
	char					*floort;
	t_v3i					cam;
};

struct						s_texture
{
	mlx_image_t				*data;
	uint32_t				color;
	t_u32					*px;
	int						x;
	int						y;
	double					step;
	double					pos;
	double					f;
	int						width;
	int						height;
	t_v2d					p;
	enum e_tx				el;
};

struct						s_cub
{
	t_render				render;
	t_ray					ray;
	t_cam					cam;
	t_map					map;
	enum e_tx				wall;
	t_texture				tx[N];
	mlx_image_t				*img;
	mlx_t					*mlx;
};

static inline t_u32	rgba_to_hex(t_rgba c)
{
	return (((int)c.r << 24) | ((int)c.g << 16) | ((int)c.b << 8) | c.a);
}
// check.c
void						check(t_map *m);

// drawline.c
void						line(mlx_image_t *i, t_v2i u, t_v2i v, uint32_t c);

// horizontal.c
void						horizontal(t_cub *c);

// init_game.c
void						gameinit(t_cub *c);

// keyhooks.c
void						keyhooks(t_cub *c);

// minimap.c
void						minimap(t_cub *c);

// parse.c
t_map						parse(int fd);

// raycast.c
int							walls(t_cub *c, int x);

// render.c
void						render(t_cub *c, int x);

// util.c
t_u32						get_color(uint8_t *p, double f);
char						mapget(t_map map, t_v2i pos);
char						*skipws(char *s);
void						exiterr(char *fmt, ...);
void						draw(t_cub *c, int x, int y, t_texture t);

// vertical,c
void						vertical(t_cub *c, int x, t_texture t);

#endif
