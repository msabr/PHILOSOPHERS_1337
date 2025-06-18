/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:25:34 by msabr             #+#    #+#             */
/*   Updated: 2025/06/16 16:42:20 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo_tab;

	philo_tab = NULL;
	if (!valid_args(ac, av) || !valid_limit(av))
		return (error_message("Invalide arguments"), 1);
	if (!init_all(&data, &philo_tab, av))
		return (destroy_simulation(&data, philo_tab),
			error_message("Init failed"), 1);
	if (!launch_processes(&data, philo_tab))
		return (destroy_simulation(&data, philo_tab),
			error_message("Fork failed"), 1);
	terminate_processes(&data, philo_tab);
	destroy_simulation(&data, philo_tab);
	return (0);
}
