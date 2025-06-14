/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:58:49 by aouanni           #+#    #+#             */
/*   Updated: 2025/06/15 00:03:01 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup(t_philo *philos, t_data *data)
{
	if (philos)
		free(philos);
	if (data->forks != SEM_FAILED)
	{
		sem_close(data->forks);
		sem_unlink("/forks");
	}
	if (data->print != SEM_FAILED)
	{
		sem_close(data->print);
		sem_unlink("/print");
	}
	if (data->death != SEM_FAILED)
	{
		sem_close(data->death);
		sem_unlink("/death");
	}
}
