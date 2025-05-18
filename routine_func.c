/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 04:48:24 by msabr             #+#    #+#             */
/*   Updated: 2025/05/16 18:36:04 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_take_forks(t_philo *philo_tab)
{
	int	l_fork;
	int	r_fork;

	l_fork = philo_tab->left_fork;
	r_fork = philo_tab->right_fork;
	if (philo_tab->id % 2 == 0)
	{
		pthread_mutex_lock(&philo_tab->shared_data->forks[r_fork]);
		print_taken_a_fork(philo_tab, continue_routine(philo_tab));
		pthread_mutex_unlock(&philo_tab->shared_data->forks[r_fork]);
		pthread_mutex_lock(&philo_tab->shared_data->forks[l_fork]);
		print_taken_a_fork(philo_tab, continue_routine(philo_tab));
		pthread_mutex_unlock(&philo_tab->shared_data->forks[l_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo_tab->shared_data->forks[l_fork]);
		print_taken_a_fork(philo_tab, continue_routine(philo_tab));
		pthread_mutex_unlock(&philo_tab->shared_data->forks[l_fork]);
		pthread_mutex_lock(&philo_tab->shared_data->forks[r_fork]);
		print_taken_a_fork(philo_tab, continue_routine(philo_tab));
		pthread_mutex_unlock(&philo_tab->shared_data->forks[r_fork]);
	}
}

static void	philo_is_eating(t_philo *philo_tab)
{
	philo_tab->last_meal_time = get_time_now
		(philo_tab->shared_data->start_time);
	pthread_mutex_lock(&philo_tab->shared_data->meal_check_mutex);
	philo_tab->number_of_meals_eaten++;
	pthread_mutex_unlock(&philo_tab->shared_data->meal_check_mutex);
	print_is_eating(philo_tab, continue_routine(philo_tab));
	ft_usleep(philo_tab->shared_data->time_to_eat, continue_routine(philo_tab),
		philo_tab);
}

static void	philo_is_sleeping(t_philo *philo_tab)
{
	print_is_sleeping(philo_tab, continue_routine(philo_tab));
	ft_usleep(philo_tab->shared_data->time_to_sleep,
		continue_routine(philo_tab), philo_tab);
}

static void	routine_one_philo(t_philo *philo_tab)
{
	pthread_mutex_lock(&philo_tab->shared_data->forks[philo_tab->left_fork]);
	print_taken_a_fork(philo_tab, continue_routine(philo_tab));
	pthread_mutex_unlock(&philo_tab->shared_data->forks[philo_tab->left_fork]);
	ft_usleep(philo_tab->shared_data->time_to_die, continue_routine(philo_tab),
		philo_tab);
	print_is_died(philo_tab, continue_routine(philo_tab));
	pthread_mutex_lock(&philo_tab->shared_data->death_mutex);
	philo_tab->shared_data->someone_died = true;
	pthread_mutex_unlock(&philo_tab->shared_data->death_mutex);
}

void	*routine(void *args)
{
	t_philo	*philo_tab;

	philo_tab = (t_philo *)args;
	if (philo_tab->shared_data->number_of_philos == 1)
	{
		routine_one_philo(philo_tab);
		return (NULL);
	}
	if (philo_tab->id % 2 == 0)
		ft_usleep(1, continue_routine(philo_tab), philo_tab);
	while (continue_routine(philo_tab))
	{
		philo_take_forks(philo_tab);
		philo_is_eating(philo_tab);
		philo_is_sleeping(philo_tab);
		print_is_thinking(philo_tab, continue_routine(philo_tab));
	}
	return (NULL);
}
