/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:51:34 by mnegura           #+#    #+#             */
/*   Updated: 2017/02/09 21:20:12 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	help_key1(int key, t_fdf *fdf)
{
	if (key == KEY_R)
	{
		omgosh(fdf);
		next_step(fdf);
	}
	if (key == ARROW_R)
	{
		fdf->cos += 13;
		next_step(fdf);
	}
	if (key == ARROW_L)
	{
		fdf->cos -= 13;
		next_step(fdf);
	}
	if (key == KEY_MAX)
	{
		fdf->sin += 13;
		next_step(fdf);
	}
	if (key == KEY_MIN)
	{
		fdf->sin -= 13;
		next_step(fdf);
	}
}

void	help_key(int key, t_fdf *fdf)
{
	if (key == KEY_W)
	{
		fdf->mvy -= 13;
		next_step(fdf);
	}
	if (key == KEY_S)
	{
		fdf->mvy += 13;
		next_step(fdf);
	}
	if (key == KEY_A)
	{
		fdf->mvx -= 13;
		next_step(fdf);
	}
	if (key == KEY_D)
	{
		fdf->mvx += 13;
		next_step(fdf);
	}
 }

int		key_hook(int key, t_fdf *fdf)
{
	if (key == 65307)
		exit(1);
	if (key == ARROW_UP)
	{
		fdf->honey += 0.105;
		next_step(fdf);
	}
	if (key == ARROW_DOWN)
	{
		fdf->honey -= 0.105;
		next_step(fdf);
	}
	if (key == PLUS)
	{
		fdf->zoom *= 1.1;
		next_step(fdf);
	}
	if (key == MINUS)
	{
		fdf->zoom /= 1.1;
		next_step(fdf);
	}
	help_key(key, fdf);
	help_key1(key, fdf);
	return (0);
}

void	menu(void)
{
	ft_putstr("\n\n\n------------------------------\n\n");
	ft_putstr("Hello ;3 \nW = Up\nS = Down\n");
	ft_putstr("A = Left\nD = Right\n\n");
	ft_putstr("ARROW UP = + Height\n");
	ft_putstr("ARROW DOWN = - Height\n\n");
	ft_putstr("ARROW LEFT & ARROW RIGHT");
	ft_putstr(" = rotate by cos\nLESS-THAN SIGN ");
	ft_putstr("& GREATER-THAN SIGN = rotate");
	ft_putstr(" by sin\n\n+ = zoom\n- = unzoom\n\nfor exit ESC");
	ft_putstr("\n\n------------------------------\n");
}
