/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/04 10:37:32 by tmercier      #+#    #+#                 */
/*   Updated: 2023/07/06 12:32:37 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	tern_int(int condition, int _true, int _false)
{
	if (condition)
		return (_true);
	return (_false);
}

static void	_narrow(t_bresenham *p, t_v2i *_0, t_v2i _1)
{
	if (p->e2 >= p->d.y && _0->x != _1.x)
	{
		p->e += p->d.y;
		_0->x += p->s.x;
	}
	if (p->e2 <= p->d.x && _0->y != _1.y)
	{
		p->e += p->d.x;
		_0->y += p->s.y;
	}
}

static void	_init_s_d(t_v2i _0, t_v2i _1, t_bresenham *p)
{
	p->d.x = abs(_1.x - _0.x);
	p->s.x = tern_int(_0.x < _1.x, 1, -1);
	p->d.y = -abs(_1.y - _0.y);
	p->s.y = tern_int(_0.y < _1.y, 1, -1);
	p->e = ((p->d.x + p->d.y));
}

void	line(mlx_image_t *img, t_v2i _0, t_v2i _1, uint32_t c)
{
	t_bresenham	p;
	int			c1;
	int			c2;

	p = (t_bresenham){};
	_init_s_d(_0, _1, &p);
	while (1)
	{
		c1 = (t_u32)_0.x >= 0 && (t_u32)_0.x < img->width;
		c2 = (t_u32)_0.y >= 0 && (t_u32)_0.y < img->height;
		if (c1 && c2)
			mlx_put_pixel(img, (_0.x), (_0.y), c);
		if (_0.x == _1.x && _0.y == _1.y)
			break ;
		p.e2 = p.e;
		_narrow(&p, &_0, _1);
	}
}
