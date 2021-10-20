/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:22:44 by agirona           #+#    #+#             */
/*   Updated: 2021/10/20 17:25:38 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_ischar(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	conv_check(const char *str, int i, int neg, int *isint)
{
	unsigned int	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && *isint == 1)
	{
		res = res * 10 + str[i] - 48;
		i++;
		if (neg == 1 && res >= 214748364 && str[i] - 48 > 7)
			*isint = 0;
		else if (neg == -1 && res >= 214748364 && str[i] - 48 > 8)
			*isint = 0;
		if (res >= 2147483647 && str[i] != '\0')
			*isint = 0;
	}
	return (res * neg);
}

int	ft_atoi_check(const char *str, int *isint)
{
	int		i;
	int		neg;

	i = 0;
	*isint = 1;
	while (ft_ischar("\r\n\v\t\f ", str[i]) == 1)
		i++;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (conv_check(str, i, neg, isint));
}
