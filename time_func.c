/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:16:02 by msabr             #+#    #+#             */
/*   Updated: 2025/05/16 01:03:33 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
