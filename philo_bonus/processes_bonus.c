/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:13:23 by msabr             #+#    #+#             */
/*   Updated: 2025/06/15 02:27:45 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	rollback_forks(t_philo *philo_tab, int i)
{
	i--;
	while (i > 0)
	{
		kill(philo_tab[i].pid, SIGKILL);
		waitpid(philo_tab[i].pid, NULL, 0);
		i--;
	}
}

bool	launch_processes(t_data *data, t_philo *philo_tab)
{
	int	i;

	i = 0;
	data->start_time = get_time_ms();
	while (i < data->number_of_philos)
	{
		philo_tab[i].pid = fork();
		if (philo_tab[i].pid < 0)
			return (rollback_forks(philo_tab, i), false);
		philo_tab[i].last_meal_time = data->start_time;
		if (philo_tab[i].pid == 0)
		{
			pthread_create(&philo_tab[i].thread, NULL, monitor, &philo_tab[i]);
			routine(&philo_tab[i]);
			pthread_join(philo_tab[i].thread, NULL);
			exit(0);
		}
		ft_usleep(1);
		i++;
	}
	return (true);
}

void	terminate_processes(t_data *data, t_philo *philo_tab)
{
	int	i;

	i = 0;
	if (data->meals_num == -1)
		sem_wait(data->death);
	else
	{
		while (i < data->number_of_philos)
		{
			sem_wait(data->death);
			i++;
		}
	}
	while (i < data->number_of_philos)
	{
		kill(philo_tab[i].pid, SIGKILL);
		waitpid(philo_tab[i].pid, NULL, 0);
		i++;
	}
	sem_post(data->death);
	destroy_simulation(data, philo_tab);
	exit(0);
}
