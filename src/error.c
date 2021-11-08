/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:10:42 by agirona           #+#    #+#             */
/*   Updated: 2021/11/08 19:16:12 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(t_data *data, int output, int ret, int phase)
{
	(void)data;
	(void)phase;
	if (ret == 0 && output != 1)
		ft_putstr("Error\n");
	if (output == 1)
	{	
		ft_putstr("Usage :\n./philo [number_of_philosophers] [time_to_die]");
		ft_putstr(" [time_to_eat] [time_to_sleep] [number_of_times_each_ph");
		ft_putstr("ilosopher_must_eat]\n./philo [number_of_philosophers] [");
		ft_putstr("time_to_die] [time_to_eat] [time_to_sleep]");
	}
	else if (output == 2)
		ft_putstr("Some arguments are empty.");
	else if (output == 3)
		ft_putstr("Some arguments contain non-numeric character.");
	else if (output == 4)
		ft_putstr("Some argument are overflowing integer limit.");
	else if (output == 5)
		ft_putstr("Malloc failed !");
	else if (output == 6)
		ft_putstr("Thread creation failed !");
	else if (output == 7)
		ft_putstr("Mutex creation failed !");
	return (ret);
}
