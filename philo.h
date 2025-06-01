/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:18:46 by msabr             #+#    #+#             */
/*   Updated: 2025/06/01 14:31:34 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_num;
	bool			all_ate_enough;
	bool			someone_died;
	time_t			start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_check_mutex;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			number_of_meals_eaten;
	time_t		last_meal_time;
	int			left_fork;
	int			right_fork;
	t_data		*shared_data;
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
void	error_message(char *message);
bool	init_all(t_data *data, t_philo **philo_tab, char **av);
void	monitor(t_philo *philo_tab);
bool	valid_args(int ac, char **av);
bool	valid_limit(char **av);
void	*routine(void *arg);
bool	create_thread_tab(t_philo *philo_tab, pthread_t *philo_thread);
bool	join_thread_tab(t_philo *philo_tab, pthread_t *philo_thread);
time_t	get_time_ms(void);
time_t	get_time_now(time_t start_time);
bool	continue_routine(t_philo *philo_tab);
void	ft_usleep(time_t time_ms, t_philo *philo_tab);
void	destroy_mutex(t_data *data);
void	free_all(t_data *data, t_philo **philo_tab, pthread_t **philo_thread);

#endif
