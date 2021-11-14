/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:35:23 by agirona           #+#    #+#             */
/*   Updated: 2021/11/14 19:12:27 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

void	accurate_sleep(long long time)
{
	long long	current;

	current = get_time();
	while (get_time() - current < time)
		usleep(50);
}

void	free_all(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->population)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		pthread_mutex_destroy(&data->philo[i].meal);
		i++;
	}
	pthread_mutex_destroy(&data->write);
	free(data->philo);
	free(data->thread);
	free(data->mutex);
}
