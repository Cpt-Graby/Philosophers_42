/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:14:32 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/28 18:48:19 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/libft.h"
#include "philosophers.h"

static int	_init_table(int num_arg, char **ascii_arg, t_table *info)
{
	info->qty_philo = ft_atoi(ascii_arg[0]);
	info->death_philo = 0;
	info->t_to_die = ft_atoi(ascii_arg[1]);
	info->t_to_eat = ft_atoi(ascii_arg[2]);
	info->t_to_sleep = ft_atoi(ascii_arg[3]);
	if (num_arg == 5)
		info->qty_meal = ft_atoi(ascii_arg[4]);
	return (0);
}

static t_fork	*_init_fork(int	number_of_fork)
{
	return (NULL);
}

int	main_philosopher(int num_arg, char **function_arg)
{
	struct timeval	tv;
	t_table			table_info;
	float			timestamp;

	if (_init_table(num_arg, function_arg, &table_info))
		return (1);
	table_info.all_fork = _init_fork(table_info.qty_philo);
	if (table_info.all_fork == NULL)
		return (-1);
	timestamp = init_timer(&tv);
	if (timestamp == -1)
		exit (-1);
	usleep(10);
	printf("Timeflow: +%2.f\n", get_time_diff_from_start(timestamp, &tv));
	return (0);
}
