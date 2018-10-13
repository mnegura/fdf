/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 20:29:37 by mnegura           #+#    #+#             */
/*   Updated: 2016/10/24 14:44:15 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*mdea;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	mdea = ft_strnew(ft_strlen(s));
	if (mdea == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mdea[i] = f(s[i]);
		i++;
	}
	return (mdea);
}
