/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:30:30 by msabr             #+#    #+#             */
/*   Updated: 2025/05/31 18:04:20 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_taken_a_fork(t_philo *philo_tab, int id)
{
	time_t	time;

	pthread_mutex_lock(&philo_tab->shared_data->print_mutex);
	time = get_time_now(philo_tab->shared_data->start_time);
	if (!continue_routine(philo_tab))
	{
		pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
		return ;
	}
	printf("\033[36m%ld %d has taken a fork\033[0m\n", time, id);
	pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
}

void	print_is_eating(t_philo *philo_tab, int id)
{
	time_t	time;

	pthread_mutex_lock(&philo_tab->shared_data->print_mutex);
	time = get_time_now(philo_tab->shared_data->start_time);
	if (!continue_routine(philo_tab))
	{
		pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
		return ;
	}
	printf("\033[32m%ld %d is eating\033[0m\n", time, id);
	pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
}

void	print_is_sleeping(t_philo *philo_tab, int id)
{
	time_t	time;

	pthread_mutex_lock(&philo_tab->shared_data->print_mutex);
	time = get_time_now(philo_tab->shared_data->start_time);
	if (!continue_routine(philo_tab))
	{
		pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
		return ;
	}
	printf("\033[33m%ld %d is sleeping\033[0m\n", time, id);
	pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
}

void	print_is_thinking(t_philo *philo_tab, int id)
{
	time_t	time;

	pthread_mutex_lock(&philo_tab->shared_data->print_mutex);
	time = get_time_now(philo_tab->shared_data->start_time);
	if (!continue_routine(philo_tab))
	{
		pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
		return ;
	}
	printf("\033[35m%ld %d is thinking\033[0m\n", time, id);
	pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
}

void	print_is_died(t_philo *philo_tab, int id)
{
	time_t	time;

	pthread_mutex_lock(&philo_tab->shared_data->print_mutex);
	time = get_time_now(philo_tab->shared_data->start_time);
	if (!continue_routine(philo_tab))
	{
		pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
		return ;
	}
	printf("\033[31m%ld %d is died\033[0m\n", time, id);
	pthread_mutex_lock(&philo_tab->shared_data->death_mutex);
	philo_tab->shared_data->someone_died = true;
	pthread_mutex_unlock(&philo_tab->shared_data->death_mutex);
	pthread_mutex_unlock(&philo_tab->shared_data->print_mutex);
}
