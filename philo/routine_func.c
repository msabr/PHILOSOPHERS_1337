/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 04:48:24 by msabr             #+#    #+#             */
/*   Updated: 2025/05/31 17:58:20 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_take_forks(t_philo *philo_tab)
{
	int	l_fork;
	int	r_fork;

	l_fork = philo_tab->left_fork;
	r_fork = philo_tab->right_fork;
	pthread_mutex_lock(&philo_tab->shared_data->forks[l_fork]);
	print_taken_a_fork(philo_tab, philo_tab->id);
	pthread_mutex_lock(&philo_tab->shared_data->forks[r_fork]);
	print_taken_a_fork(philo_tab, philo_tab->id);
}

static void	philo_is_eating(t_philo *philo_tab)
{
	philo_tab->number_of_meals_eaten++;
	print_is_eating(philo_tab, philo_tab->id);
	pthread_mutex_lock(&philo_tab->shared_data->meal_check_mutex);
	philo_tab->last_meal_time = get_time_now
		(philo_tab->shared_data->start_time);
	pthread_mutex_unlock(&philo_tab->shared_data->meal_check_mutex);
	ft_usleep(philo_tab->shared_data->time_to_eat, philo_tab);
	pthread_mutex_unlock(&philo_tab->shared_data
		->forks[philo_tab->right_fork]);
	pthread_mutex_unlock(&philo_tab->shared_data
		->forks[philo_tab->left_fork]);
}

static void	philo_is_sleeping(t_philo *philo_tab)
{
	print_is_sleeping(philo_tab, philo_tab->id);
	ft_usleep(philo_tab->shared_data->time_to_sleep, philo_tab);
}

static void	routine_one_philo(t_philo *philo_tab)
{
	pthread_mutex_lock(&philo_tab->shared_data->forks[philo_tab->left_fork]);
	print_taken_a_fork(philo_tab, philo_tab->id);
	pthread_mutex_unlock(&philo_tab->shared_data->forks[philo_tab->left_fork]);
	ft_usleep(philo_tab->shared_data->time_to_die, philo_tab);
	print_is_died(philo_tab, philo_tab->id);
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
		ft_usleep(50, philo_tab);
	while (continue_routine(philo_tab))
	{
		philo_take_forks(philo_tab);
		philo_is_eating(philo_tab);
		philo_is_sleeping(philo_tab);
		print_is_thinking(philo_tab, philo_tab->id);
	}
	return (NULL);
}
