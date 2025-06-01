/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:25:34 by msabr             #+#    #+#             */
/*   Updated: 2025/06/01 14:54:14 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo_tab;
	pthread_t	*philo_thread;

	philo_tab = NULL;
	if (!valid_args(ac, av) || !valid_limit(av))
		return (error_message("Invalide arguments"), 1);
	if (!init_all(&data, &philo_tab, av))
		return (error_message("Init failed"), 1);
	philo_thread = malloc(sizeof(pthread_t) * data.number_of_philos);
	if (!philo_thread)
		return (error_message("Memory allocation failed"),
			free_all(&data, &philo_tab, &philo_thread), 1);
	if (!create_thread_tab(philo_tab, philo_thread))
		return (error_message("Thread creation failed"),
			free_all(&data, &philo_tab, &philo_thread), 1);
	monitor(philo_tab);
	if (!join_thread_tab(philo_tab, philo_thread))
		return (error_message("Thread joining failed"),
			free_all(&data, &philo_tab, &philo_thread), 1);
	free_all(&data, &philo_tab, &philo_thread);
	return (0);
}
