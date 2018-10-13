/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:17:51 by mnegura           #+#    #+#             */
/*   Updated: 2017/02/09 21:19:09 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(long n, int base, char *str, int *i)
{
	if (n == 0)
		return ;
	rec(n / base, base, str, i);
	str[(*i)++] = "0123456789ABCDEF"[n % base * (1 - 2 * (n < 0))];
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 64);
	if (value == 0)
		str[i++] = '0';
	if (value < 0 && base == 10)
		str[i++] = '-';
	rec(value, base, str, &i);
	str[i] = '\0';
	return (0);
}
