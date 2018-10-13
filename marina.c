/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marina.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:00:53 by mnegura           #+#    #+#             */
/*   Updated: 2017/02/09 21:05:18 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	ft_pinok_pod_zad(char *you)
{
	int		fd;
	char	*line;
	t_fdf	fdf;

	line = NULL;
	fd = open(you, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("oops\nsmth went wrong\n");
		exit(69);
	}
	get_next_line(fd, &line);
	fdf.zad.col = ft_count_col(line);
	fdf.zad.row = 1;
	while (get_next_line(fd, &line) == 1)
		fdf.zad.row++;
	fdf.zad.space = 0.75 * (WIDTH / (fdf.zad.row * 0.5 + fdf.zad.col * 0.86));
	close(fd);
	return (fdf);
}

t_fdf	ft_lets_go(char *you)
{
	int		fd;
	char	**cute;
	t_fdf	fdf;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	fdf = ft_pinok_pod_zad(you);
	fd = open(you, O_RDONLY);
	if (fd < 0)
		ft_putstr("oops\nsmth went wrong\n");
	fdf.shine = (t_shine**)malloc(sizeof(t_shine*) * (fdf.zad.row));
	while (get_next_line(fd, &line) == 1)
	{
		cute = ft_strsplit(line, ' ');
		fdf.shine[i] = ft_gatsby(cute, fdf.zad.col);
		i++;
	}
	close(fd);
	return (fdf);
}

int		next_step(t_fdf *fdf)
{
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->str = mlx_get_data_addr(fdf->img, &fdf->bpp,
		&fdf->sline, &fdf->endian);
	print(*fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img);
	return (0);
}

void	ft_start(t_fdf fdf)
{
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "Cute_Fdf");
	omgosh(&fdf);
	init_colors(&fdf);
	mlx_expose_hook(fdf.win, next_step, &fdf);
	mlx_key_hook(fdf.win, key_hook, &fdf);
	mlx_loop(fdf.mlx);
}

int		main(int ac, char **ag)
{
	t_fdf	fdf;

	if (ac == 2)
	{
		menu();
		fdf = ft_lets_go(ag[1]);
		ft_start(fdf);
	}
	else
		ft_putstr("usage: ./fdf mapneme\n");
	return (0);
}
