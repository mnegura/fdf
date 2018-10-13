/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:45:25 by mnegura           #+#    #+#             */
/*   Updated: 2017/02/09 21:20:50 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			verific(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	return (-1);
}

int			verific2(int x, int y)
{
	if (x > y)
		return (x);
	return (-y);
}

double		distance(t_fdf fdf)
{
	return (sqrt((fdf.cor.x2 - fdf.cor.x1) * (fdf.cor.x2 - fdf.cor.x1)
				+ (fdf.cor.y2 - fdf.cor.y1) * (fdf.cor.y2 - fdf.cor.y1)));
}

int			ft_count_col(char *str)
{
	int	i;
	int	col;

	i = -1;
	col = 0;
	while (str[++i] != '\0')
		if (str[i] == ' ' && str[i - 1] != ' ')
			col++;
	return (col);
}

t_shine		*ft_gatsby(char **cute, int col)
{
	int		i;
	t_shine	*shine;

	i = -1;
	shine = (t_shine*)malloc(sizeof(t_shine) * col);
	while (++i < col)
		shine[i].z = ft_atoi(cute[i]);
	return (shine);
}
