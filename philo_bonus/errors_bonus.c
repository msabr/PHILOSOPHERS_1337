/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:48 by msabr             #+#    #+#             */
/*   Updated: 2025/06/15 01:50:59 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	error_message(char *msg)
{
	ft_putstr_fd(2, "\033[31mError:");
	ft_putstr_fd(2, msg);
	ft_putstr_fd(2, " \033[0m\n");
}

void	destroy_simulation(t_data *data, t_philo *philo_tab)
{
	if (philo_tab)
	{
		free(philo_tab);
		philo_tab = NULL;
	}
	if (data->forks)
	{
		sem_close(data->forks);
		sem_unlink("/forks");
	}
	if (data->print)
	{
		sem_close(data->print);
		sem_unlink("/print");
	}
	if (data->death)
	{
		sem_close(data->death);
		sem_unlink("/death");
	}
}
