/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:01:00 by agirona           #+#    #+#             */
/*   Updated: 2021/10/22 19:31:03 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef enum e_error
{
	USAGE_ERROR = 1,
	EMPTY_ERROR = 2,
	DIGIT_ERROR = 3,
	OVER_ERROR = 4,
	MALLOC_ERROR = 5,
	THREAD_ERROR = 6,
	MUTEX_ERROR = 7
}				t_error;

typedef struct s_philo
{
	int					number;
	int					alive;
	int					eating;
	int					fork;
	int					sleeping;
	int					thinking;
	int					time_die;
	pthread_mutex_t		*mutex;
	int					*rip;
}				t_philo;

typedef struct s_data
{
	t_philo				*philo;
	pthread_t			*thread;
	int					*total_fork;
	int					population;
	int					die;
	int					eat;
	int					sleep;
	int					sated;
	int					rip;
	pthread_mutex_t		*mutex;
}				t_data;

//print

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

//error

int		error(t_data *data, int output, int ret, int phase);

//atoi_check

int		ft_atoi_check(const char *str, int *isint);

//parsing

int		verif_arg(int argc, char **argv);

//init

int		init_struct(t_data *data, int argc, char **argv);
int		init_philo(t_data *data);
int		init_thread(t_data *data);
int		init_mutex(t_data *data);

#endif
