/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 17:11:50 by mnegura           #+#    #+#             */
/*   Updated: 2016/10/24 19:37:31 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	else
	{
		ft_bzero(ptr, size + 1);
		return (ptr);
	}
}
