/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:46:36 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/22 15:43:40 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_table(int num_arg, char **ascii_arg, t_table *info)
{
	info->qty_philo = ft_atoi(ascii_arg[0]);
	info->t_to_die = ft_atoi(ascii_arg[1]);
	info->t_to_eat = ft_atoi(ascii_arg[2]);
	info->t_to_sleep = ft_atoi(ascii_arg[3]);
	info->qty_meal = 0;
	info->death_philo = 0;
	if (info->qty_philo <= 0 || info->t_to_die <= 0 || info->t_to_eat <= 0
		|| info->t_to_sleep <= 0)
	{
		errno = EINVAL;
		ft_putstr_fd("Input error", 2);
		return (2);
	}
	if (num_arg == 5)
		info->qty_meal = ft_atoi(ascii_arg[4]);
	if (info->qty_philo != 1)
	{
		info->all_fork = init_fork(info->qty_philo);
		if (info->all_fork == NULL)
			return (-1);
		info->all_philo = init_philo(info->qty_philo, info);
		if (info->all_philo == NULL)
			return (-1);
	}
	return (0);
}

t_fork	*init_fork(int number_of_fork)
{
	t_fork	*pointer;
	int		i;
	int		status;

	i = 0;
	pointer = malloc(sizeof(*pointer) * number_of_fork);
	if (!pointer)
		return (NULL);
	while (i < number_of_fork)
	{
		status = pthread_mutex_init(&pointer[i].lock, NULL);
		if (status)
		{
			ft_putstr_fd("_init_fork, mutex creation", 2);
			return (NULL);
		}
		pointer[i].taken = 0;
		i++;
	}
	return (pointer);
}

t_philo	*init_philo(int number_of_philo, t_table *info)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(*philos) * number_of_philo);
	if (!philos)
		return (NULL);
	while (i < number_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].alive = 1;
		philos[i].last_meal = 0;
		philos[i].meal_count = 0;
		philos[i].table_info = info;
		philos[i].self_fork = &info->all_fork[i];
		if (i == number_of_philo - 1)
			philos[i].left_fork = &info->all_fork[0];
		else
			philos[i].left_fork = &info->all_fork[i + 1];
		i++;
	}
	return (philos);
}
