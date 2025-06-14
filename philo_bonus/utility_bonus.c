/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:58:40 by aouanni           #+#    #+#             */
/*   Updated: 2025/06/15 00:13:40 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(time_t time_ms)
{
	time_t	start_time;

	start_time = get_time_ms();
	while (get_time_now(start_time) < time_ms)
		usleep(500);
}

void		error_message(char *msg)
{
	ft_putstr_fd(2, "\033[31mError:");
	ft_putstr_fd(2, msg);
	ft_putstr_fd(2, " \033[0m\n");
}

