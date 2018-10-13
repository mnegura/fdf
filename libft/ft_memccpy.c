/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:14:15 by mnegura           #+#    #+#             */
/*   Updated: 2016/10/25 18:29:51 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst,
		const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			dp;

	i = 0;
	dp = (unsigned char)c;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (((unsigned char *)dst)[i] == dp)
			return (&((unsigned char *)dst)[i + 1]);
		i++;
	}
	return (NULL);
}
