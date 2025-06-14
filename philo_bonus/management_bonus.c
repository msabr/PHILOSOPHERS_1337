/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:52:18 by aouanni           #+#    #+#             */
/*   Updated: 2025/06/15 00:31:32 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitoring(void *args)
{
	t_philo	*philos;
	t_data	*data;
	time_t	current;

	philos = (t_philo *)args;
	data = philos->shared_data;
	while (!philos->should_break)
	{
		current = get_time_now(data->start_time);
		if (current - philos->last_meal_time >= data->time_to_die)
		{
			philos->should_break = true;
			print_is_died(philos, philos->id);
			sem_post(data->death);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}


int	handle_fail(t_philo *philos, int i)
{
	if (philos[i].pid < 0)
	{
		while (i > 0)
		{
			i--;
			kill(philos[i].pid, SIGKILL);
			waitpid(philos[i].pid, NULL, 0);
		}
		return (1);
	}
	return (0);
}

int	manage_process(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	data->start_time = get_time_ms();
	while (i < data->number_of_philos)
	{
		philos[i].pid = fork();
		if (handle_fail(philos, i))
			return (0);
		philos[i].last_meal_time = data->start_time;
		if (philos[i].pid == 0)
		{
			pthread_create(&philos[i].thread, NULL, monitoring, &philos[i]);
			philo_routine(&philos[i]);
			pthread_join(philos[i].thread, NULL);
			exit(0);
		}
		i++;
		usleep(100);
	}
	return (1);
}
