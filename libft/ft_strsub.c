/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 14:41:54 by mnegura           #+#    #+#             */
/*   Updated: 2016/10/24 19:36:56 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*meh;
	size_t	i;

	if (!s)
		return (NULL);
	meh = (char *)malloc((len + 1) * sizeof(char));
	if (meh == NULL)
		return (NULL);
	i = start;
	while (i < start + len)
	{
		meh[i - start] = s[i];
		i++;
	}
	meh[len] = '\0';
	return (meh);
}
