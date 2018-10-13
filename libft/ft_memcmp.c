/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:48:20 by mnegura           #+#    #+#             */
/*   Updated: 2016/10/23 14:55:22 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*aux1;
	const unsigned char	*aux2;

	aux1 = s1;
	aux2 = s2;
	while (n--)
	{
		if (*aux1 != *aux2)
			return (*aux1 - *aux2);
		else
		{
			aux1++;
			aux2++;
		}
	}
	return (0);
}
