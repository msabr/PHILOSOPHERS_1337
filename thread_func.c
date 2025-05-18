/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:35:32 by msabr             #+#    #+#             */
/*   Updated: 2025/05/16 00:35:41 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_thread_tab(t_philo *philo_tab, pthread_t *philo_thread)
{
	int	i;

	i = 0;
	philo_tab->shared_data->start_time = get_time_ms();
	while (i < philo_tab->shared_data->number_of_philos)
	{
		philo_tab[i].last_meal_time = philo_tab->shared_data->start_time;
		if (pthread_create(&philo_thread[i], NULL, routine, &philo_tab[i]))
			return (0);
		i++;
	}
	return (1);
}

bool	join_thread_tab(t_philo *philo_tab, pthread_t *philo_thread)
{
	int	i;

	i = 0;
	while (i < philo_tab->shared_data->number_of_philos)
	{
		if (pthread_join(philo_thread[i], NULL))
			return (0);
		i++;
	}
	return (1);
}
