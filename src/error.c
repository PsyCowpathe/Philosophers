/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:10:42 by agirona           #+#    #+#             */
/*   Updated: 2021/10/20 20:07:06 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(int output, int ret)
{
	if (ret == 0 && output != 1)
		ft_putstr("Error\n");
	if (output == 1)
	{	
		ft_putstr("Usage :\n./philo [number_of_philosophers] [time_to_die] ");
		ft_putstr("[time_to_eat] [time_to_sleep] [number_of_times_each_phi");
		ft_putstr("losopher_must_eat]\n./philo [number_of_philosophers] [t");
		ft_putstr("ime_to_die] [time_to_eat] [time_to_sleep]");
	}
	else if (output == 2)
		ft_putstr("Some arguments are empty.");
	else if (output == 3)
		ft_putstr("Some arguments contain non-numeric character.");
	else if (output == 4)
		ft_putstr("Some argument are overflowing integer limit.");
	return (ret);
}
