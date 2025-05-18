/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:56:09 by msabr             #+#    #+#             */
/*   Updated: 2025/05/18 15:55:43 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	continue_routine(t_philo *philo_tab)
{
	pthread_mutex_lock(&philo_tab->shared_data->death_mutex);
	pthread_mutex_lock(&philo_tab->shared_data->meal_check_mutex);
	if (philo_tab->shared_data->someone_died
		|| philo_tab->shared_data->all_ate_enough)
	{
		pthread_mutex_unlock(&philo_tab->shared_data->meal_check_mutex);
		pthread_mutex_unlock(&philo_tab->shared_data->death_mutex);
		return (false);
	}
	pthread_mutex_unlock(&philo_tab->shared_data->meal_check_mutex);
	pthread_mutex_unlock(&philo_tab->shared_data->death_mutex);
	return (true);
}

void	ft_usleep(time_t time, t_philo *philo_tab)
{
	time_t	start;
	
	// if (!continue_routine(philo_tab))
	// 	return ;
	start = get_time_ms();
	while (get_time_now(start) < time)
	{
		usleep(500);
		if (!continue_routine(philo_tab))
			break;
	}
}

void destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->meal_check_mutex);
	while (i < data->number_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}
