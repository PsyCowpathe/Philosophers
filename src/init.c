/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:47:24 by agirona           #+#    #+#             */
/*   Updated: 2021/11/15 16:19:17 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->population)
	{
		data->philo[i].number = i + 1;
		data->philo[i].alive = 1;
		data->philo[i].rfork = &data->mutex[i];
		data->philo[i].fork = 0;
		data->philo[i].count = 0;
		data->philo[i].satied = 0;
		if (i + 1 == data->population)
			data->philo[i].lfork = &data->mutex[0];
		else
			data->philo[i].lfork = &data->mutex[i + 1];
		data->philo[i].data = data;
		i++;
	}
}

int	init_philo_mutex(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->population)
	{
		if (pthread_mutex_init(&data->philo[i].meal, NULL) != 0)
		{	
			while (--i >= 0)
				pthread_mutex_destroy(&data->philo[i].meal);
			i = 0;
			while (i < data->population)
			{
				pthread_mutex_destroy(&data->mutex[i]);
				i++;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_mutex(t_data *data)
{
	int		i;

	i = 0;
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (0);
	while (i < data->population)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->mutex[i]);
			return (0);
		}
		i++;
	}
	return (init_philo_mutex(data));
}

int	malloc_struct(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->population);
	if (data->philo == NULL)
		return (0);
	data->thread = malloc(sizeof(pthread_t) * data->population);
	if (data->thread == NULL)
		return (0);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->population);
	if (data->mutex == NULL)
		return (0);
	return (1);
}

void	init_struct(t_data *data, int argc, char **argv)
{
	int		tmp;

	data->philo = NULL;
	data->thread = NULL;
	data->mutex = NULL;
	data->population = ft_atoi_check(argv[1], &tmp);
	data->tdeath = ft_atoi_check(argv[2], &tmp);
	data->teat = ft_atoi_check(argv[3], &tmp);
	data->tsleep = ft_atoi_check(argv[4], &tmp);
	data->max_eat = -1;
	data->satied = 0;
	if (argc == 6)
		data->max_eat = ft_atoi_check(argv[5], &tmp);
	data->funeral = 0;
	data->rdy = 0;
}
