/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:24:40 by mnegura           #+#    #+#             */
/*   Updated: 2016/10/25 18:39:25 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t till)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (to_find[0] == '\0')
		return (char*)(str);
	while (str[i] != '\0' && i < till)
	{
		c = 0;
		while (str[i + c] == to_find[c] && to_find[c]
				&& str[i + c] && i + c < till)
		{
			c++;
			if (to_find[c] == '\0')
				return (char*)(&str[i]);
		}
		i++;
	}
	return (0);
}
