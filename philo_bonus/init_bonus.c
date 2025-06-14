/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:49:37 by aouanni           #+#    #+#             */
/*   Updated: 2025/06/15 00:30:47 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
static bool	init_data(t_data *data, char **av)
{
	data = memset(data, 0, sizeof(t_data));
	data->number_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->meals_num = ft_atoi(av[5]);
	else
		data->meals_num = -1;
	data->start_time = get_time_ms();
	sem_unlink("/print");
	sem_unlink("/death");
	sem_unlink("/forks");
	data->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	data->death = sem_open("/death", O_CREAT | O_EXCL, 0644, 0);
	data->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, data->number_of_philos);
	if (data->print == SEM_FAILED || data->death == SEM_FAILED
		|| data->forks == SEM_FAILED)
		return (false);
	return (true);
}

static bool	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = 0;
		philos[i].should_break = false;
		philos[i].shared_data = data;
		philos[i].pid = -1;
		i++;
	}
	return (true);
}

bool	init_all(t_data *data, t_philo **philos, char **av)
{
	
	if (!init_data(data, av))
		return (false);
	*philos = (t_philo *)malloc(sizeof(t_philo) * data->number_of_philos);
	if (!*philos)
		return (false);
	if (!init_philos(data, *philos))
		return (free(*philos), false);
	return (true);
}