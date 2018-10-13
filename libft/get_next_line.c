/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:17:43 by mnegura           #+#    #+#             */
/*   Updated: 2016/12/28 16:03:00 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_newline(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i] == '\n')
			return (i + 1);
		else
			i++;
	return (0);
}

char	*get_next(char *str, char *ptr)
{
	int j;

	j = ft_newline(str);
	if (j != 0)
		ptr = ft_strsub(str, 0, j);
	else
		ptr = ft_strsub(str, 0, ft_strlen(str));
	return (ptr);
}

void	init(char **str, char **ptr, int *len, int const fd)
{
	*ptr = ft_strnew(BUFF_SIZE);
	*ptr = ft_strjoin(*ptr, *str);
	*str = ft_strnew(BUFF_SIZE);
	*len = read(fd, *str, BUFF_SIZE);
	if (*ptr != NULL)
	{
		*str = ft_strjoin(*ptr, *str);
		*ptr = NULL;
	}
}

int		get_next_line(int const fd, char **line)
{
	int			len;
	static char *str = NULL;
	char		*ptr;

	init(&str, &ptr, &len, fd);
	if (len < 0)
		return (-1);
	else if (len == 0 && (ft_strlen(str) == 0))
		return (0);
	else
	{
		ptr = get_next(str, ptr);
		if ((len == 0) || (ft_newline(ptr) != 0))
		{
			*line = ft_strsub(ptr, 0, ft_strlen(ptr) - (ft_newline(ptr) != 0));
			str = ft_strsub(str, ft_strlen(ptr), ft_strlen(str));
			return (1);
		}
		free(str);
		str = ptr;
		return (get_next_line(fd, line));
	}
}
