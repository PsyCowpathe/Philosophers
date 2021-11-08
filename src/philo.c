/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:59:41 by agirona           #+#    #+#             */
/*   Updated: 2021/11/08 19:16:14 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

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
	return (1);
}
