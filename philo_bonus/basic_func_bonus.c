/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:51:54 by msabr             #+#    #+#             */
/*   Updated: 2025/06/15 01:50:25 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	long	nbr;

	nbr = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && is_digit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (nbr > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)nbr);
}

void	ft_putstr_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
