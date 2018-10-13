/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:51:18 by mnegura           #+#    #+#             */
/*   Updated: 2016/10/27 16:52:09 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t count)
{
	size_t i;

	i = 0;
	while (i < count && *str1 == *str2 && *str1 != 0)
	{
		str1++;
		str2++;
		i++;
	}
	if (count == i)
		return (0);
	else
		return (*(unsigned char*)str1 - *(unsigned char*)str2);
}
