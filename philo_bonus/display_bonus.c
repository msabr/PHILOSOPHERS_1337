/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:30:30 by msabr             #+#    #+#             */
/*   Updated: 2025/06/18 21:32:06 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_taken_a_fork(t_philo *philo_tab, int id)
{
	time_t	time;

	if (philo_tab->should_break)
		return ;
	sem_wait(philo_tab->shared_data->print);
	time = get_time_now(philo_tab->shared_data->start_time);
	printf("\033[36m%ld %d has taken a fork\033[0m\n", time, id);
	sem_post(philo_tab->shared_data->print);
}

void	print_is_eating(t_philo *philo_tab, int id)
{
	time_t	time;

	if (philo_tab->should_break)
		return ;
	sem_wait(philo_tab->shared_data->print);
	time = get_time_now(philo_tab->shared_data->start_time);
	printf("\033[32m%ld %d is eating\033[0m\n", time, id);
	sem_post(philo_tab->shared_data->print);
}

void	print_is_sleeping(t_philo *philo_tab, int id)
{
	time_t	time;

	if (philo_tab->should_break)
		return ;
	sem_wait(philo_tab->shared_data->print);
	time = get_time_now(philo_tab->shared_data->start_time);
	printf("\033[33m%ld %d is sleeping\033[0m\n", time, id);
	sem_post(philo_tab->shared_data->print);
}

void	print_is_thinking(t_philo *philo_tab, int id)
{
	time_t	time;

	if (philo_tab->should_break)
		return ;
	sem_wait(philo_tab->shared_data->print);
	time = get_time_now(philo_tab->shared_data->start_time);
	printf("\033[35m%ld %d is thinking\033[0m\n", time, id);
	sem_post(philo_tab->shared_data->print);
}

void	print_is_died(t_philo *philo_tab, int id)
{
	time_t	time;

	if (philo_tab->should_break)
		return ;
	sem_wait(philo_tab->shared_data->print);
	time = get_time_now(philo_tab->shared_data->start_time);
	printf("\033[31m%ld %d is died\033[0m\n", time, id);
	philo_tab->should_break = true;
	// sem_post(philo_tab->shared_data->print);
}
