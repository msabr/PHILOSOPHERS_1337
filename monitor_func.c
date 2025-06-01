/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:45:31 by msabr             #+#    #+#             */
/*   Updated: 2025/05/31 18:08:08 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_death(t_philo *philo_tab, t_data *data)
{
	int	i;

	i = 0;
	if (!continue_routine(philo_tab))
		return (false);
	while (i < data->number_of_philos)
	{
		pthread_mutex_lock(&data->meal_check_mutex);
		if (((get_time_now(data->start_time) - philo_tab[i].last_meal_time)
				> data->time_to_die))
		{
			pthread_mutex_unlock(&data->meal_check_mutex);
			print_is_died(&philo_tab[i], philo_tab->id);
			pthread_mutex_lock(&data->death_mutex);
			data->someone_died = true;
			pthread_mutex_unlock(&data->death_mutex);
			return (true);
		}
		pthread_mutex_unlock(&data->meal_check_mutex);
		i++;
	}
	return (false);
}

static void	all_ate_enough(t_philo *philo_tab, t_data *data)
{
	int	i;

	i = 0;
	if (data->meals_num == -1)
		return ;
	pthread_mutex_lock(&data->meal_check_mutex);
	while (i < data->number_of_philos)
	{
		if (philo_tab[i].number_of_meals_eaten < data->meals_num)
		{
			pthread_mutex_unlock(&data->meal_check_mutex);
			return ;
		}
		i++;
	}
	data->all_ate_enough = true;
	pthread_mutex_unlock(&data->meal_check_mutex);
}

void	monitor(t_philo *philo_tab)
{
	t_data	*data;

	data = ((t_philo *)philo_tab)->shared_data;
	if (data->number_of_philos == 1)
		return ;
	while (continue_routine(philo_tab))
	{
		if (is_death(philo_tab, data))
			break ;
		ft_usleep(1, philo_tab);
		all_ate_enough(philo_tab, data);
	}
}
