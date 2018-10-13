/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:55:51 by mnegura           #+#    #+#             */
/*   Updated: 2016/10/23 15:00:15 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *aux;

	aux = (unsigned char*)s;
	while (n--)
		if (*aux != (unsigned char)c)
			aux++;
		else
			return (aux);
	return (0);
}
