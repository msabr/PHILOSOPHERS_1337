/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:33:05 by msabr             #+#    #+#             */
/*   Updated: 2025/05/15 04:35:02 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	valid_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 5 || ac > 6)
		return (false);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]) && av[i][0] != '+' && !is_space(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	valid_limit(char **av)
{
	int	i;

	(void)av;
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > 200)
		return (false);
	i = 2;
	while (av[i])
	{
		if ((ft_atoi(av[i]) < 60 && i < 5)
			|| ft_atoi(av[i]) <= 0
			|| ft_atoi(av[i]) > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}
