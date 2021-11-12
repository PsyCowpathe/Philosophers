/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:59:41 by agirona           #+#    #+#             */
/*   Updated: 2021/11/12 19:55:31 by agirona          ###   ########lyon.fr   */
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
	long long current;

	current = get_time();
	while (get_time() - current < time)
		usleep(50);
}

void	print_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->funeral == 1)
	{
		pthread_mutex_unlock(&philo->data->write);
		return ;
	}
	ft_putnbr(get_time() - philo->data->first_meal);
	ft_putchar(' ');
	ft_putnbr(philo->number);
	if (action == 0)
		ft_putstr(" is eating\n");
	else if (action == 1)
		ft_putstr(" is sleeping\n");
	else if (action == 2)
		ft_putstr(" is thinking\n");
	else if (action == 3)
		ft_putstr(" died\n");
	else if (action == 4)
		ft_putstr(" has taken a fork\n");
	pthread_mutex_unlock(&philo->data->write);
}

void	pick_a_fork(t_philo *philo)
{
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
	while (philo->data->funeral == 0)
	{
		pick_a_fork(philo);
		if (philo->fork == 2)
		{
			pthread_mutex_lock(&philo->meal);
			philo->last_meal = get_time();
			pthread_mutex_unlock(&philo->meal);
			print_action(philo, 0);
			accurate_sleep(philo->data->time_eat);
			pthread_mutex_unlock(philo->rfork);
			pthread_mutex_unlock(philo->lfork);
			philo->fork = 0;
		}
		print_action(philo, 1);
		accurate_sleep(philo->data->time_sleep);
		print_action(philo, 2);
	}
	return (NULL);
}

int	philo(t_data *data)
{
	int		i;
	int		ret;

	i = 0;
	while (i < data->population)
	{
		ret = 0;
		ret = pthread_create(&data->thread[i], NULL, lets_feast, &data->philo[i]);
		if (ret != 0)
			return (0);
		i++;
	}
	data->first_meal = get_time();
	data->rdy = 1;
	i = 0;
	while (i < data->population)
	{
		data->philo[i].last_meal = data->first_meal;
		i++;
	}
	i = 0;
	while (data->funeral == 0)
	{
		pthread_mutex_lock(&data->philo[i].meal);
		if (get_time() > data->philo[i].last_meal + data->time_death)
		{
			pthread_mutex_unlock(&data->philo[i].meal);
			print_action(&data->philo[i], 3);
			data->funeral = 1;
			return (1);
		}
		pthread_mutex_unlock(&data->philo[i].meal);
		if (i + 1 == data->population)
			i = 0;
		else
			i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (error(&data, USAGE_ERROR, 0, 0)); //attentions aux nouvelles phases d'erreur
	if (verif_arg(argc, argv) == 0)
		return (0);
	init_struct(&data, argc, argv);
	if (malloc_struct(&data) == 0)
		return (error(&data, MALLOC_ERROR, 0, 0)); //attention
	if (init_mutex(&data) == 0)
		return (error(&data, MUTEX_ERROR, 0, 0)); //attention
	init_philo(&data);
	if (philo(&data) == 0)
		return (error(&data, THREAD_ERROR, 0, 0)); //attention
	while (i < data.population)
	{
		pthread_join(data.thread[i], NULL);	
		i++;
	}
	return (1);
}
