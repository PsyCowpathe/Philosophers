/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:22:44 by agirona           #+#    #+#             */
/*   Updated: 2021/11/15 12:35:14 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

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
	int				final;
	char			*tmp;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && *isint == 1)
		res = res * 10 + str[i++] - 48;
	final = res * neg;
	tmp = ft_itoa(final);
	if (tmp == NULL)
	{
		*isint = 0;
		return (0);
	}
	if (ft_strcmp((char *)str, tmp) != 0)
		*isint = 0;
	free(tmp);
	return (res);
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
