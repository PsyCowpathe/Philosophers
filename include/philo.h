/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:01:00 by agirona           #+#    #+#             */
/*   Updated: 2021/11/14 19:12:27 by agirona          ###   ########lyon.fr   */
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
	pthread_mutex_t		*rfork;
	pthread_mutex_t		*lfork;
	int					fork;
	long long			last;
	pthread_mutex_t		meal;
	int					count;
	int					satied;
	struct s_data		*data;
}				t_philo;

typedef struct s_data
{
	int					population;
	int					tdeath;
	int					teat;
	int					tsleep;
	int					max_eat;
	int					funeral;
	int					rdy;
	int					satied;
	long long			first;
	t_philo				*philo;
	pthread_t			*thread;
	pthread_mutex_t		write;
	pthread_mutex_t		*mutex;
}				t_data;

//print

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(long long nb);

//error

int		error(t_data *data, int output, int ret, int phase);

//atoi_check

int		ft_atoi_check(const char *str, int *isint);

//parsing

int		verif_arg(int argc, char **argv);

//init

void	init_struct(t_data *data, int argc, char **argv);
int		malloc_struct(t_data *data);
int		init_mutex(t_data *data);
void	init_philo(t_data *data);

//utility

long long	get_time(void);
void		accurate_sleep(long long time);
void		free_all(t_data *data);
void		print_action(t_philo *philo, int action);

#endif
