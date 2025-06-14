/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:59:18 by aouanni           #+#    #+#             */
/*   Updated: 2025/06/15 00:31:39 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdatomic.h>

# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>


# define RED "\033[31m"
# define GREEN   "\033[32m"
# define RESET "\033[0m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define MAGENTA "\033[35m"

# define ARG_ERROR_NUM "Warning: Invalide number of arguments found"
# define ARG_ERROR_ARG "Warning: Invalide argument found"
# define ERROR "Warning: Error happend"
# define FORK_NOTIF "has taken a fork"
# define DEAD_NOTIF "is died"
# define EAT_NOTIF "is eating"
# define SLEEP_NOTIF "is sleeping"
# define THINK_NOTIF "is thinking"

typedef struct s_data
{
	long		number_of_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		meals_num;
	time_t		start_time;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*death;
}	t_data;

typedef struct s_philo
{
	pid_t					pid;
	long					id;
	atomic_long				meals_eaten;
	atomic_llong			last_meal_time;
	atomic_bool				should_break;
	pthread_t				thread;
	t_data				*shared_data;
}	t_philo;

time_t	get_time_ms(void);
time_t	get_time_now(time_t start_time);
void		cleanup(t_philo *philos, t_data *data);
void		error_message(char *msg);
void		philo_routine(t_philo *philos);
int			manage_process(t_data *data, t_philo *philos);

bool		init_all(t_data *data, t_philo **philos, char **av);
bool		valid_args(int ac, char **av);
bool		valid_limit(char **av);

int		ft_strlen(char *str);
int		is_digit(int c);
int		is_space(int c);
int		ft_atoi(char *str);
void	ft_putstr_fd(int fd, char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_usleep(time_t time_ms);

void		print_taken_a_fork(t_philo *philo_tab, int id);
void		print_is_eating(t_philo *philo_tab, int id);
void		print_is_sleeping(t_philo *philo_tab, int id);
void		print_is_thinking(t_philo *philo_tab, int id);
void		print_is_died(t_philo *philo_tab, int id);

#endif
