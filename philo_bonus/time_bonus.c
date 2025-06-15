/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:16:02 by msabr             #+#    #+#             */
/*   Updated: 2025/06/15 01:53:42 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

time_t	get_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error_message("gettimeofday");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

time_t	get_time_now(time_t start_time)
{
	return (get_time_ms() - start_time);
}

void	ft_usleep(time_t time_ms)
{
	time_t	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < time_ms)
		usleep(100);
}
