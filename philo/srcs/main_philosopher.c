/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:14:32 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/03 14:44:45 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/libft.h"
#include "philosophers.h"

static t_philo	*_init_philo(int number_of_philo)
{
	t_philo	*philos;;
	int		i;
	int		status;

	i = 0;
	philos = malloc(sizeof(*philos) * number_of_philo);
	if (!philos)
		return (NULL);
	while (i < number_of_philo)
	{
		philos[i].last_meal = 0;
		philos[i].alive = 1;
		status = pthread_create(&philos->thread_id, NULL, NULL, NULL);
		if (status)
		{
			perror("init_philo, thread creation");
			exit(status);
		}
		i++;
	}
	return (philos);
}

static void	_one_philo(t_table info)
{
	(void) info;
}

static int	_init_table(int num_arg, char **ascii_arg, t_table *info)
{
	info->qty_philo = ft_atoi(ascii_arg[0]);
	info->death_philo = 1;
	info->t_to_die = ft_atoi(ascii_arg[1]);
	info->t_to_eat = ft_atoi(ascii_arg[2]);
	info->t_to_sleep = ft_atoi(ascii_arg[3]);
	if (num_arg == 5)
		info->qty_meal = ft_atoi(ascii_arg[4]);
	if (info->qty_philo == 1)
	{
		_one_philo(*info);
		return (1);
	}
	info->all_fork = init_fork(info->qty_philo);
	if (info->all_fork == NULL)
		exit(-1);
	return (0);
}

int	main_philosopher(int num_arg, char **function_arg)
{
	struct timeval	tv;
	t_table			table_info;
	float			timestamp;

	if (_init_table(num_arg, function_arg, &table_info))
		return (0);
	table_info.all_philo = _init_philo(table_info.qty_philo);
	if (table_info.all_philo == NULL)
		exit(-1);
	timestamp = init_timer(&tv);
	if (timestamp == -1)
		exit (-1);
	usleep(10);
	printf("Timeflow: +%2.f\n", get_time_diff_from_start(timestamp, &tv));
	destroy_fork(table_info.all_fork, table_info.qty_philo);
	return (0);
}
