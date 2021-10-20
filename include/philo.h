/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:01:00 by agirona           #+#    #+#             */
/*   Updated: 2021/10/20 20:47:57 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>

typedef enum e_error
{
	USAGE_ERROR = 1,
	EMPTY_ERROR = 2,
	DIGIT_ERROR = 3,
	OVER_ERROR = 4
}				t_error;

typedef struct s_data
{
	int		population;
	int		die;
	int		eat;
	int		sleep;
	int		sated;
}				t_data;

//print

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

//error

int		error(int output, int ret);

//atoi_check

int		ft_atoi_check(const char *str, int *isint);

//parsing

int		verif_arg(int argc, char **argv);

//init

void	init_struct(t_data *data, int argc, char **argv);

#endif
