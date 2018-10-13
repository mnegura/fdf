/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 15:00:26 by mnegura           #+#    #+#             */
/*   Updated: 2016/10/23 15:31:39 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	len2;

	if (src < dst)
	{
		len2 = len;
		while (len2 > 0)
		{
			len2--;
			((char *)dst)[len2] = ((char *)src)[len2];
		}
	}
	else
	{
		len2 = 0;
		while (len2 < len)
		{
			((char *)dst)[len2] = ((char *)src)[len2];
			len2++;
		}
	}
	return (dst);
}
