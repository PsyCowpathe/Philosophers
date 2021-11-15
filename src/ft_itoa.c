/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:32:56 by agirona           #+#    #+#             */
/*   Updated: 2021/11/15 12:33:57 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	new_malloc(void **dst, int type, int len)
{
	*dst = malloc(type * len);
	if (*dst == NULL)
		return (0);
	return (1);
}

char	*ft_itoa(long long n)
{
	int		len;
	int		neg;
	long	nbr;
	char	*res;

	len = 1;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (n < 0)
		n = n * -1;
	nbr = n;
	while (nbr >= 10 && ++len)
		nbr /= 10;
	if (new_malloc((void *)&res, sizeof(char), len + neg + 1) == 0)
		return (NULL);
	if (neg == 1)
		res[0] = '-';
	res[len + neg--] = '\0';
	while (len != 0)
	{
		res[len-- + neg] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
