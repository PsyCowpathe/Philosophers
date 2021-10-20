/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:59:41 by agirona           #+#    #+#             */
/*   Updated: 2021/10/20 20:48:44 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	(void)argv;
	if (argc < 5 || argc > 6)
		return (error(USAGE_ERROR, 0));
	if (verif_arg(argc, argv) == 0)
		return (0);
	init_struct(&data, argc, argv);
	ft_putnbr(data.population);
	ft_putchar('\n');
	ft_putnbr(data.die);
	ft_putchar('\n');
	ft_putnbr(data.eat);
	ft_putchar('\n');
	ft_putnbr(data.sleep);
	ft_putchar('\n');
	ft_putnbr(data.sated);
	return (1);
}
