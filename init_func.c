/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:37:56 by msabr             #+#    #+#             */
/*   Updated: 2025/05/31 18:08:29 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_data(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->number_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->meals_num = ft_atoi(av[5]);
	else
		data->meals_num = -1;
	data->all_ate_enough = false;
	data->someone_died = false;
	data->start_time = get_time_ms();
	if (pthread_mutex_init(&data->death_mutex, NULL)
		|| pthread_mutex_init(&data->print_mutex, NULL)
		|| pthread_mutex_init(&data->meal_check_mutex, NULL))
		return (false);
	return (true);
}

static bool	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	if (!data->forks)
		return (false);
	while (i < data->number_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (false);
		i++;
	}
	i = 0;
	while (i < data->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].number_of_meals_eaten = 0;
		philos[i].left_fork = i;
		philos[i].right_fork = (i + 1) % data->number_of_philos;
		philos[i].shared_data = data;
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
		return (destroy_mutex(data), free(*philos), false);
	return (true);
}
