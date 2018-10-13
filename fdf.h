/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:07:12 by mnegura           #+#    #+#             */
/*   Updated: 2017/02/09 20:52:30 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

# define PINK 0xffe6ff
# define PINK1 0xffccff
# define PINK2 0xffb3ff
# define PINK3 0xff99ff
# define PINK4 0xff80ff
# define PINK5 0xff66ff
# define PINK6 0xff4dff
# define PINK7 0xff33ff
# define PINK8 0xff1aff
# define PINK9 0xff00ff
# define PINK10 0xe600e6
# define PINK11 0xcc00cc
# define PINK12 0xb300b3
# define PINK13 0x990099
# define PINK14 0x800080

# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_R 65361
# define ARROW_L 65363
# define KEY_MIN 44
# define KEY_MAX 46
# define KEY_R 114
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define PLUS 61
# define MINUS 45

typedef struct	s_shine
{
	int			x;
	int			y;
	int			z;
}				t_shine;

typedef struct	s_zad
{
	int			row;
	int			col;
	double		space;
}				t_zad;

typedef struct	s_coor
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
}				t_coor;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*str;
	int			bpp;
	int			endian;
	int			sline;
	double		honey;
	double		zoom;
	int			colors[15];
	int			aux_color;
	int			yes;
	int			cos;
	int			sin;
	int			mvx;
	int			mvy;
	t_zad		zad;
	t_shine		**shine;
	t_coor		cor;
}				t_fdf;

typedef	struct	s_draw
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			e2;
	int			err;
	double		mimi;
	double		mimimi;
}				t_draw;

int				verific(int x1, int x2);
int				verific2(int x, int y);
double			distance(t_fdf fdf);
void			menu(void);
int				ft_count_col(char *str);
t_shine			*ft_gatsby(char **cute, int col);
t_fdf			init_coord(t_fdf fdf, int i, int j, int ok);
void			omgosh(t_fdf *fdf);
void			init_colors(t_fdf *fdf);
void			put_pixel(int x, int y, t_fdf fdf);
t_fdf			iso(t_fdf fdf);
void			print_line(t_fdf fdf);
void			print(t_fdf fdf);
void			help_key1(int key, t_fdf *fdf);
void			help_key(int key, t_fdf *fdf);
int				key_hook(int key, t_fdf *fdf);
t_fdf			ft_pinok_pod_zad(char *you);
t_fdf			ft_lets_go(char *you);
int				next_step(t_fdf *fdf);
void			ft_start(t_fdf fdf);

#endif
