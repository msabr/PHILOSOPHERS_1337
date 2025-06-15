/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:18:46 by msabr             #+#    #+#             */
/*   Updated: 2025/06/15 02:26:56 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <signal.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <semaphore.h>
# include <stdatomic.h>

typedef struct s_data
{
	long	number_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_num;
	time_t	start_time;
	sem_t	*forks;
	sem_t	*print;
	sem_t	*death;
}	t_data;

typedef struct s_philo
{
	pid_t			pid;
	long			id;
	atomic_long		meals_eaten;
	atomic_llong	last_meal_time;
	atomic_bool		should_break;
	pthread_t		thread;
	t_data			*shared_data;
}	t_philo;

int		ft_strlen(char *str);
int		is_digit(int c);
int		is_space(int c);
int		ft_atoi(char *str);
void	ft_putstr_fd(int fd, char *str);
void	print_taken_a_fork(t_philo *philo_tab, int id);
void	print_is_eating(t_philo *philo_tab, int id);
void	print_is_sleeping(t_philo *philo_tab, int id);
void	print_is_thinking(t_philo *philo_tab, int id);
void	print_is_died(t_philo *philo_tab, int id);
void	error_message(char *msg);
void	destroy_simulation(t_data *data, t_philo *philo_tab);
bool	init_all(t_data *data, t_philo **philo_tab, char **av);
void	*monitor(void *args);
bool	valid_args(int ac, char **av);
bool	valid_limit(char **av);
bool	launch_processes(t_data *data, t_philo *philo_tab);
void	terminate_processes(t_data *data, t_philo *philo_tab);
void	routine(t_philo *philo_tab);
time_t	get_time_ms(void);
time_t	get_time_now(time_t start_time);
void	ft_usleep(time_t time_ms);

#endif
