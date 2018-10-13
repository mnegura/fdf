/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:48:00 by mnegura           #+#    #+#             */
/*   Updated: 2017/02/10 19:16:34 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(int x, int y, t_fdf fdf)
{
	int			offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = x * 4;
	offset += y * fdf.sline;
	*(int*)(fdf.str + offset) = fdf.aux_color;
}

t_fdf	iso(t_fdf fdf)
{
	int		i;
	int		j;
	double	cos_a;
	double	sin_a;

	cos_a = cos(fdf.cos * M_PI / 180);
	sin_a = sin(fdf.sin * M_PI / 180);
	i = 0;
	fdf.zad.space *= fdf.zoom;
	while (i < fdf.zad.row)
	{
		j = 0;
		while (j < fdf.zad.col)
		{
			fdf.shine[i][j].x = (i - fdf.zad.row / 2) * fdf.zad.space * -cos_a +
			(j - fdf.zad.col / 2) * fdf.zad.space * cos_a + WIDTH / 2 + fdf.mvx;
			fdf.shine[i][j].y = (i - fdf.zad.row / 2) * fdf.zad.space *
				sin_a - (j - fdf.zad.col / 2) * fdf.zad.space * -sin_a
				- fdf.shine[i][j].z * fdf.honey * fdf.zad.space + HEIGHT / 2
				+ fdf.mvy;
			j++;
		}
		i++;
	}
	return (fdf);
}

t_draw	hpl(t_draw *d, t_fdf fdf)
{
	d->dx = abs(fdf.cor.x2 - fdf.cor.x1);
	d->dy = abs(fdf.cor.y2 - fdf.cor.y1);
	d->sx = verific(fdf.cor.x1, fdf.cor.x2);
	d->sy = verific(fdf.cor.y1, fdf.cor.y2);
	d->err = verific2(d->dx, d->dy) / 2;
	d->mimimi = distance(fdf);
	return (*d);
}

void	print_line(t_fdf fdf)
{
	t_draw	d;

	d = hpl(&d, fdf);
	fdf.aux_color = fdf.colors[0];
	while (1)
	{
		put_pixel(fdf.cor.x1, fdf.cor.y1, fdf);
		if (fdf.cor.x1 == fdf.cor.x2 && fdf.cor.y1 == fdf.cor.y2)
			break ;
		d.e2 = d.err;
		if (d.e2 > -d.dx)
		{
			d.err -= d.dy;
			fdf.cor.x1 += d.sx;
		}
		if (d.e2 < d.dy)
		{
			d.err += d.dx;
			fdf.cor.y1 += d.sy;
		}
		d.mimi = distance(fdf);
		if (!fdf.yes && (int)d.mimi != 0)
			fdf.aux_color =
			fdf.colors[(int)fmod(d.mimi / 100, d.mimimi / 15) % 15];
	}
}

void	print(t_fdf fdf)
{
	int		i;
	int		j;

	i = 0;
	fdf = iso(fdf);
	while (i < fdf.zad.row)
	{
		j = 0;
		while (j < fdf.zad.col)
		{
			if (i < fdf.zad.row - 1)
			{
				fdf = init_coord(fdf, i, j, 1);
				print_line(fdf);
			}
			if (j < fdf.zad.col - 1)
			{
				fdf = init_coord(fdf, i, j, 2);
				print_line(fdf);
			}
			j++;
		}
		i++;
	}
}
