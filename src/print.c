/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:17:06 by agirona           #+#    #+#             */
/*   Updated: 2021/11/15 16:19:16 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(long long nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(214748364);
		ft_putchar(8 + 48);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

void	print_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->funeral == 1)
	{
		pthread_mutex_unlock(&philo->data->write);
		return ;
	}
	ft_putnbr(get_time() - philo->data->first);
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
	if (action == 2 && philo->data->tsleep == 0)
		accurate_sleep(1);
}
