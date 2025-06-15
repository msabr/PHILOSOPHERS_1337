/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 04:48:24 by msabr             #+#    #+#             */
/*   Updated: 2025/06/15 02:30:06 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static bool	all_ate_enough(t_philo *philo_tab)
{
	if (philo_tab->shared_data->meals_num == -1)
		return (false);
	if (philo_tab->meals_eaten >= philo_tab->shared_data->meals_num)
	{
		philo_tab->should_break = true;
		sem_post(philo_tab->shared_data->death);
		return (true);
	}
	return (false);
}

static void	routine_one_philo(t_philo *philo_tab)
{
	sem_wait(philo_tab->shared_data->forks);
	print_taken_a_fork(philo_tab, philo_tab->id);
	ft_usleep(philo_tab->shared_data->time_to_die);
	print_is_died(philo_tab, philo_tab->id);
	sem_post(philo_tab->shared_data->forks);
	sem_post(philo_tab->shared_data->death);
}

static void	philo_take_forks(t_philo *philo_tab)
{
	sem_wait(philo_tab->shared_data->forks);
	print_taken_a_fork(philo_tab, philo_tab->id);
	sem_wait(philo_tab->shared_data->forks);
	print_taken_a_fork(philo_tab, philo_tab->id);
}

static void	philo_is_eating(t_philo *philo_tab)
{
	philo_tab->last_meal_time = get_time_now
		(philo_tab->shared_data->start_time);
	print_is_eating(philo_tab, philo_tab->id);
	philo_tab->meals_eaten++;
	ft_usleep(philo_tab->shared_data->time_to_eat);
	sem_post(philo_tab->shared_data->forks);
	sem_post(philo_tab->shared_data->forks);
}

void	routine(t_philo	*philo_tab)
{
	if (philo_tab->shared_data->number_of_philos == 1)
	{
		routine_one_philo(philo_tab);
		return ;
	}
	if (philo_tab->id % 2 == 0)
		ft_usleep(1);
	while (!philo_tab->should_break)
	{
		if (all_ate_enough(philo_tab))
			return ;
		philo_take_forks(philo_tab);
		philo_is_eating(philo_tab);
		print_is_sleeping(philo_tab, philo_tab->id);
		ft_usleep(philo_tab->shared_data->time_to_sleep);
		if (philo_tab->should_break || all_ate_enough(philo_tab))
			return ;
		print_is_thinking(philo_tab, philo_tab->id);
	}
}
