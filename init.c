/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:42:05 by mnegura           #+#    #+#             */
/*   Updated: 2017/02/09 20:40:47 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	init_coord(t_fdf fdf, int i, int j, int ok)
{
	fdf.cor.y1 = fdf.shine[i][j].y;
	fdf.cor.x1 = fdf.shine[i][j].x;
	fdf.yes = 0;
	if (ok == 1)
	{
		if (fdf.shine[i + 1][j].z == 0 && fdf.shine[i][j].z == 0)
			fdf.yes = 1;
		fdf.cor.x2 = fdf.shine[i + 1][j].x;
		fdf.cor.y2 = fdf.shine[i + 1][j].y;
	}
	else
	{
		if (fdf.shine[i][j + 1].z == 0 && fdf.shine[i][j].z == 0)
			fdf.yes = 1;
		fdf.cor.x2 = fdf.shine[i][j + 1].x;
		fdf.cor.y2 = fdf.shine[i][j + 1].y;
	}
	return (fdf);
}

void	omgosh(t_fdf *fdf)
{
	fdf->cos = 30;
	fdf->sin = 40;
	fdf->honey = 0.105;
	fdf->zoom = 1;
	fdf->mvx = 0;
	fdf->mvy = 0;
}

void	init_colors(t_fdf *fdf)
{
	fdf->colors[0] = PINK;
	fdf->colors[1] = PINK1;
	fdf->colors[2] = PINK2;
	fdf->colors[3] = PINK3;
	fdf->colors[4] = PINK4;
	fdf->colors[5] = PINK5;
	fdf->colors[6] = PINK6;
	fdf->colors[7] = PINK7;
	fdf->colors[8] = PINK8;
	fdf->colors[9] = PINK9;
	fdf->colors[10] = PINK10;
	fdf->colors[11] = PINK11;
	fdf->colors[12] = PINK12;
	fdf->colors[13] = PINK13;
	fdf->colors[14] = PINK14;
}
