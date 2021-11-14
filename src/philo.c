/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:59:41 by agirona           #+#    #+#             */
/*   Updated: 2021/11/14 19:12:29 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_a_fork(t_philo *philo)
{
	if (philo->data->population == 1)
		return ;
	if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(philo->rfork);
		print_action(philo, 4);
		pthread_mutex_lock(philo->lfork);
		print_action(philo, 4);
	}
	else
	{
		pthread_mutex_lock(philo->lfork);
		print_action(philo, 4);
		pthread_mutex_lock(philo->rfork);
		print_action(philo, 4);
	}
	philo->fork = 2;
}

void	*lets_feast(void *ptr)
{
	t_philo		*philo;

	philo = ptr;
	while (philo->data->rdy == 0)
		;
	while (philo->data->funeral == 0 && philo->satied != 1)
	{
		pick_a_fork(philo);
		if (philo->fork == 2)
		{
			pthread_mutex_lock(&philo->meal);
			philo->last = get_time();
			pthread_mutex_unlock(&philo->meal);
			philo->count++;
			print_action(philo, 0);
			accurate_sleep(philo->data->teat);
			pthread_mutex_unlock(philo->rfork);
			pthread_mutex_unlock(philo->lfork);
			philo->fork = 0;
			print_action(philo, 1);
			accurate_sleep(philo->data->tsleep);
			print_action(philo, 2);
		}
	}
	return (NULL);
}

void	check_death(t_data *data)
{
	int		i;

	i = 0;
	while (data->funeral == 0 && data->satied < data->population)
	{
		if (data->philo[i].satied != 1 && data->max_eat != -1
			&& data->philo[i].count >= data->max_eat && ++data->satied)
			data->philo[i].satied = 1;
		accurate_sleep(1);
		pthread_mutex_lock(&data->philo[i].meal);
		if (get_time() > data->philo[i].last + data->tdeath
			&& data->philo[i].satied != 1)
		{
			pthread_mutex_unlock(&data->philo[i].meal);
			print_action(&data->philo[i], 3);
			data->funeral = 1;
			return ;
		}
		pthread_mutex_unlock(&data->philo[i].meal);
		if (i + 1 == data->population)
			i = 0;
		else
			i++;
	}
}

int	philo(t_data *data)
{
	int		i;
	int		ret;

	i = 0;
	while (i < data->population)
	{
		ret = 0;
		ret = pthread_create(&data->thread[i], NULL,
				lets_feast, &data->philo[i]);
		if (ret != 0)
			return (0);
		i++;
	}
	data->first = get_time();
	data->rdy = 1;
	i = 0;
	while (i < data->population)
	{
		data->philo[i].last = data->first;
		i++;
	}
	check_death(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (error(&data, USAGE_ERROR, 0, 0));
	if (verif_arg(argc, argv) == 0)
		return (0);
	init_struct(&data, argc, argv);
	if (malloc_struct(&data) == 0)
		return (error(&data, MALLOC_ERROR, 0, 1));
	if (init_mutex(&data) == 0)
		return (error(&data, MUTEX_ERROR, 0, 2));
	init_philo(&data);
	if (philo(&data) == 0)
		return (error(&data, THREAD_ERROR, 0, 3));
	while (i < data.population)
	{
		pthread_join(data.thread[i], NULL);
		i++;
	}
	free_all(&data);
	return (1);
}
