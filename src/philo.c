/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:59:41 by agirona           #+#    #+#             */
/*   Updated: 2021/10/22 19:31:01 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

void	*someone_theres(void *ptr)
{
	t_data	*data;
	int		i;

	data = ptr;
	i = 0;
	while (data->rip == 0)
	{
		if (i >= data->population)
			i = 0;
		pthread_mutex_lock(&data->mutex[0]);
		if (data->philo[i].alive == 0)
		{
			printf("%lli %i died\n", get_time(), i);
			data->rip = 1;
		}
		pthread_mutex_unlock(&data->mutex[0]);
		i++;
	}
	return (NULL);
}

void	*lets_feast(void *ptr)
{
	t_philo		*philo;
	long long	start_time;
	long long 	time;

	philo = ptr;
	start_time = get_time();
	while (philo->alive == 1)
	{
		pthread_mutex_lock(philo->mutex);
		time = get_time();
		if (time >= start_time + philo->time_die)
			philo->alive = 0;
		if (philo->alive == 0 || *philo->rip == 1)
		{
			pthread_mutex_unlock(philo->mutex);
			return (NULL);
		}
		if (philo->thinking == 1)
			printf("%lli %i is thinking\n", time, philo->number);
		pthread_mutex_unlock(philo->mutex);
	}
	return (NULL);
}

int		philo(t_data *data)
{
	int		i;
	int		ret;

	i = 0;
	while (i < 5)
	{
		ret = pthread_create(&data->thread[i], NULL, lets_feast, &data->philo[i]);
		if (ret != 0)
			return (0);
		i++;
	}
	ret = pthread_create(&data->thread[i], NULL, someone_theres, data);
	pthread_join(data->thread[i], NULL);
	if (ret != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	(void)argv;
	if (argc < 5 || argc > 6)
		return (error(&data, USAGE_ERROR, 0, 0));
	if (verif_arg(argc, argv) == 0)
		return (0);
	if (init_struct(&data, argc, argv) == 0)
		return (error(&data, MALLOC_ERROR, 0, 1));
	if (init_mutex(&data) == 0)
		return (error(&data, MUTEX_ERROR, 0, 2));
	if (init_philo(&data) == 0)
		return (error(&data, MALLOC_ERROR, 0, 3));
	if (philo(&data) == 0)
		return (error(&data, THREAD_ERROR, 0, 4));
	return (1);
}

/*static void *task_a(void *p_data)
{
   ft_putstr("Hello world A\n");

   (void) p_data;
   return NULL;
}

static void *task_b(void *p_data)
{
   ft_putstr("Hello world B\n");

   (void) p_data;
   return NULL;
}

int main (void)
{
   pthread_t ta;
   pthread_t tb;

   ft_putstr("main init\n");

   pthread_create(&ta, NULL, task_a, NULL);
   pthread_create(&tb, NULL, task_b, NULL);

   pthread_join (ta, NULL);
   pthread_join (tb, NULL);
   ft_putstr("main end\n");

   return 0;
}*/

