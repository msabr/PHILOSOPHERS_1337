/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:45:31 by msabr             #+#    #+#             */
/*   Updated: 2025/06/16 16:56:05 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *args)
{
	t_philo	*philo_tab;
	time_t	current_time;

	philo_tab = (t_philo *)args;
	while (!philo_tab->should_break)
	{
		current_time = get_time_now(philo_tab->shared_data->start_time);
		if ((current_time - philo_tab->last_meal_time)
			>= (philo_tab->shared_data->time_to_die))
		{
			print_is_died(philo_tab, philo_tab->id);
			philo_tab->should_break = true;
			sem_post(philo_tab->shared_data->death);
			exit(1);
		}
		ft_usleep(1);
	}
	return (NULL);
}
