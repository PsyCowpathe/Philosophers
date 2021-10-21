/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:59:41 by agirona           #+#    #+#             */
/*   Updated: 2021/10/21 20:56:38 by agirona          ###   ########lyon.fr   */
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
		//mutex
		if (data->philo[i].alive == 0)
			data->rip = 1;
		i++;
	}
	return (NULL);
}

void	*lets_feast(void *ptr)
{
	t_philo		*philo;

	philo = ptr;
	if (philo->thinking == 1)
		printf("%lli %i is thinking\n", get_time(), philo->number);
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
	if (init_philo(&data) == 0)
		return (error(&data, MALLOC_ERROR, 0, 2));
	if (philo(&data) == 0)
		return (error(&data, THREAD_ERROR, 0, 3));
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

