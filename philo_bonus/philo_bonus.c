/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:50:46 by aouanni           #+#    #+#             */
/*   Updated: 2025/06/15 00:05:07 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	death_process(t_data *data, t_philo *philos)
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
		kill(philos[i].pid, SIGKILL);
		waitpid(philos[i].pid, NULL, 0);
		i++;
	}
}

int	main(int c, char **v)
{
	t_philo		*philos;
	t_data	data;

philos = NULL;
	if (!valid_args(c, v) || !valid_limit(v))
		return (error_message(ARG_ERROR_NUM), 1);
	if (!init_all(&data, &philos, v))
		return (cleanup(philos, &data), error_message(ERROR), 1);
	if (!manage_process(&data, philos))
		return (cleanup(philos, &data), error_message(ERROR), 1);
	death_process(&data, philos);
	cleanup(philos, &data);
}
