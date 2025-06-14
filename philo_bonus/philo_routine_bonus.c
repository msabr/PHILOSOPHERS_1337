/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:59:07 by aouanni           #+#    #+#             */
/*   Updated: 2025/06/15 00:32:25 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_full(t_data *data, t_philo *philos)
{
	if (data->meals_num != -1 && philos->meals_eaten >= data->meals_num)
	{
		philos->should_break = 1;
		sem_post(data->death);
		return (1);
	}
	return (0);
}

int	check_one(t_data *data, t_philo *philos)
{
	if (data->number_of_philos == 1)
	{
		ft_usleep(data->time_to_die);
		print_is_died(philos, philos->id);
		sem_post(data->forks);
		sem_post(data->death);
		return (1);
	}
	return (0);
}

void	eat_habit(t_data *data, t_philo *philos)
{
	philos->last_meal_time = get_time_now(data->start_time);
	print_is_eating(philos, philos->id);
	philos->meals_eaten++;
	ft_usleep(data->time_to_eat);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	philo_routine(t_philo *philos)
{
	t_data	*data;

	data = philos->shared_data;
	while (!philos->should_break)
	{
		if (is_full(data, philos))
			return ;
		sem_wait(data->forks);
		print_taken_a_fork(philos, philos->id);
		if (check_one(data, philos))
			return ;
		sem_wait(data->forks);
		print_taken_a_fork(philos, philos->id);
		eat_habit(data, philos);
		if (philos->should_break || is_full(data, philos))
			return ;
		print_is_sleeping(philos, philos->id);
		ft_usleep(data->time_to_sleep);
		if (philos->should_break || is_full(data, philos))
			return ;
		print_is_thinking(philos, philos->id);
	}
}
