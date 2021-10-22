/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:47:24 by agirona           #+#    #+#             */
/*   Updated: 2021/10/22 19:31:02 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_mutex(t_data *data)
{
	int		i;

	data->mutex = malloc(sizeof(data->mutex) * data->population + 1);
	if (data->mutex == NULL)
		return (0);
	i = 0;
	while (i < data->population + 1)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0) //dont forget destroy
			return (0);
		i++;
	}
	return (1);
}

int		init_philo(t_data *data)
{
	int		i;

	i = 0;
	data->philo = NULL;
	ft_putstr("ici\n");
	data->philo = malloc(sizeof(t_philo) * data->population);
	ft_putstr("la\n");
	if (data->philo == NULL)
		return (0);
	while (i < data->population)
	{
		data->philo[i].number = i + 1;
		data->philo[i].alive = 1;
		data->philo[i].eating = 0;
		data->philo[i].fork = 0;
		data->philo[i].sleeping = 0;
		data->philo[i].thinking = 1;
		data->philo[i].mutex = &data->mutex[0];
		data->philo[i].time_die = data->die;
		data->philo[i].rip = &data->rip;
		i++;
	}
	return (1);
}

int	init_struct(t_data *data, int argc, char **argv)
{
	int		tmp;

	data->total_fork = NULL;
	data->thread = NULL;
	data->sated = -1;
	data->rip = 0;
	data->population = ft_atoi_check(argv[1], &tmp);
	data->die = ft_atoi_check(argv[2], &tmp);
	data->eat = ft_atoi_check(argv[3], &tmp);
	data->sleep = ft_atoi_check(argv[4], &tmp);
	if (argc == 6)
		data->sated = ft_atoi_check(argv[5], &tmp);
	data->total_fork = malloc(sizeof(int) * data->population);
	if (data->total_fork == NULL)
		return (0);
	data->thread = malloc(sizeof(data->thread) * data->population + 1);
	if (data->thread == NULL)
		return (0);
	return (1);
}
