/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftex.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/04 14:32:18 by asaijers      #+#    #+#                 */
/*   Updated: 2023/07/04 14:32:19 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTEX_H
# define LIBFTEX_H

# include "libft.h"
# include "unistd.h"
# include <pthread.h>
# include <stdint.h>

typedef uint64_t	t_u64;
typedef uint32_t	t_u32;
typedef uint16_t	t_u16;
typedef uint8_t		t_u8;
typedef int64_t		t_i64;
typedef int32_t		t_i32;
typedef int16_t		t_i16;
typedef int8_t		t_i8;
typedef float		t_f32;
typedef double		t_f64;
typedef struct s_l	t_l;
typedef struct s_v	t_v;

struct				s_v
{
	void			*dat;
	size_t			len;
	size_t			cap;
	size_t			esz;
};

struct				s_l
{
	void			*dat;
	t_l				*nxt;
	t_l				*prv;
};

typedef struct s_q
{
	t_l				*l;
	size_t			s;
	pthread_mutex_t	m;
}					t_q;

typedef struct s_v3d
{
	double			x;
	double			y;
	double			z;
}					t_v3d;

typedef struct s_v2i
{
	int				x;
	int				y;
}					t_v2i;

typedef struct s_v3i
{
	int				x;
	int				y;
	int				z;
}					t_v3i;

typedef struct s_v2d
{
	t_f64			x;
	t_f64			y;
}					t_v2d;

typedef struct s_args
{
	int				ac;
	char			**av;

}					t_args;

typedef int			(*t_f_compare)(void *a, void *b);
typedef void		(*t_f_dtor)(void *x);

t_v					*vcreate(size_t esz);
void				vgrow(t_v *v, size_t n);
void				*vpush(t_v *v, void *el);
void				*vpop(t_v *v);
void				vswap(t_v *v, int a, int b);
t_v					*vcopy(t_v *v);
void				*vget(t_v *v, ssize_t i);
ssize_t				vindexof(t_v *v, void *e, t_f_compare cmp);
void				vdestroy(t_v *v);
void				vconcat(t_v *v, void *d, size_t n);
void				*vdelfast(t_v *v, size_t i);
void				*vset(t_v *v, size_t i, void *el);
void				*vshift(t_v *v);
void				*vunshift(t_v *v, void *a);
void				*vpopc(t_v *v);
void				vquicksort(t_v *v, t_f_compare cmp);
int					vis_sorted(t_v *v, t_f_compare cmp);
void				*vmin(t_v *v, t_f_compare cmp);
void				*vmax(t_v *v, t_f_compare cmp);
void				vfill(t_v *v, void *e);
void				vclear(t_v *v, t_f_dtor f);
void				vtrunc(t_v *v, t_f_dtor f, size_t n);

void				qadd(t_q *q, void *e);
void				*qtake(t_q *q);
int					qempty(t_q *q);
t_q					*qcreate(size_t esz);
void				qdestroy(t_q *q);
void				qclear(t_q *q, t_f_dtor f);

char				*get_next_line(int fd);
int					ft_printf(const char *fmt, ...);
int					ft_fprintf(int fd, const char *fmt, ...);
int					ft_vfprintf(int fd, const char *fmt, t_list v);
int					ft_isint(char *s);
int					ft_isintn(char *s, size_t n);
int					ft_isucharn(char *s, size_t n);
int					ft_isuchar(char *s);

t_l					*lctor(void *dat);
void				ldestroy(t_l *l, void (*f)(void *));
void				ldtor(t_l *l);
void				leach(t_l *l, void (*f)(t_l *));
void				lpush(t_l **h, t_l *t);
t_l					*lshift(t_l **h);

t_args				get_args(int ac, char **av);
char				*argf_str(t_args a, char *k);
char				*argn_str(t_args a, int n);
t_f64				argn_f64(t_args a, int n, t_f64 d);
t_i64				argn_i64(t_args a, int n, t_i64 d);
t_f64				argf_f64(t_args a, char *k, t_f64 d);
t_i64				argf_i64(t_args a, char *k, t_i64 d);
t_u64				argf_u64(t_args a, char *k, t_u64 d);
/*get one char from e at pos n*/
char				argn_char_enum(t_args a, int n, char *e);

uint64_t			getts(void);
int					min(int a, int b);
int					max(int a, int b);
#endif
