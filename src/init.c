/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:47:24 by agirona           #+#    #+#             */
/*   Updated: 2021/10/20 20:47:41 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_data *data, int argc, char **argv)
{
	int		tmp;

	data->sated = -1;
	data->population = ft_atoi_check(argv[1], &tmp);
	data->die = ft_atoi_check(argv[2], &tmp);
	data->eat = ft_atoi_check(argv[3], &tmp);
	data->sleep = ft_atoi_check(argv[4], &tmp);
	if (argc == 6)
		data->sated = ft_atoi_check(argv[5], &tmp);
}
