/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:48 by msabr             #+#    #+#             */
/*   Updated: 2025/05/18 16:26:06 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	error_message(char *message)
{
	ft_putstr_fd(2, "\033[31mError: ");
	ft_putstr_fd(2, message);
	ft_putstr_fd(2, " \033[0m\n");
}

void	test(void)
{
	write(1, "\033[32m==================\033[0m\n", 30);
}

void free_all(t_data *data, t_philo **philo_tab, pthread_t **philo_thread)
{
	destroy_mutex(data);
	free(*philo_tab);
	free(*philo_thread);

}
