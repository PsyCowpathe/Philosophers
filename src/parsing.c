/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:14:01 by agirona           #+#    #+#             */
/*   Updated: 2021/11/08 15:55:45 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_arg(int argc, char **argv)
{
	int		i;
	int		c;
	int		isint;

	i = 1;
	while (i < argc)
	{
		c = 0;
		if (argv[i][0] == '\0')
			return (error(NULL, EMPTY_ERROR, 0, 0));
		ft_atoi_check(argv[i], &isint);
		if (isint == 0)
			return (error(NULL, OVER_ERROR, 0, 0));
		while (argv[i][c])
		{
			if (argv[i][c] < '0' || argv[i][c] > '9')
				return (error(NULL, DIGIT_ERROR, 0, 0));
			c++;
		}
		i++;
	}
	return (1);
}
