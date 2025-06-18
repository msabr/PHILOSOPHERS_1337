/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:37:56 by msabr             #+#    #+#             */
/*   Updated: 2025/06/18 20:48:03 by msabr            ###   ########.fr       */
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
	data->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644,
			data->number_of_philos);
	if (data->print == SEM_FAILED || data->death == SEM_FAILED
		|| data->forks == SEM_FAILED)
		return (false);
	return (true);
}

static void	init_philos(t_data *data, t_philo *philo_tab)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		philo_tab[i].id = i + 1;
		philo_tab[i].meals_eaten = 0;
		philo_tab[i].last_meal_time = 0;
		philo_tab[i].should_break = false;
		philo_tab[i].shared_data = data;
		philo_tab[i].pid = -1;
		i++;
	}
}

bool	init_all(t_data *data, t_philo **philo_tab, char **av)
{
	if (!init_data(data, av))
		return (false);
	*philo_tab = (t_philo *)malloc(sizeof(t_philo) * data->number_of_philos);
	if (!*philo_tab)
		return (false);
	init_philos(data, *philo_tab);
	return (true);
}
