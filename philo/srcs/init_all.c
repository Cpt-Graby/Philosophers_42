/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:46:36 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 14:50:14 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_all_struct(t_info *info)
{
	if (init_info(info) == -1)
		return (errno);
	info->all_fork = init_fork(info->time_to[QTY_PHILO]);
	if (info->all_fork == NULL)
		return (errno);
	info->all_philo = init_philo(info->time_to[QTY_PHILO], info);
	if (info->all_philo == NULL)
		return (errno);
	return (0);
}

int	init_info(t_info *info)
{
	if (pthread_mutex_init(&(info->write), NULL))
	{
		ft_putstr_fd("_init_fork, mutex creation", 2);
		return (errno);
	}
	if (pthread_mutex_init(&(info->safe_end), NULL))
	{
		ft_putstr_fd("_init_fork, mutex creation", 2);
		return (errno);
	}
	info->end_routine = 0;
	info->time_start = get_time();
	if (info->time_start == -1)
	{
		ft_putstr_fd("init_table_info: get_time error\n", 2);
		return (errno);
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
	{
		ft_putstr_fd("init_fork, malloc_error\n", 2);
		return (NULL);
	}
	while (i < number_of_fork)
	{
		status = pthread_mutex_init(&pointer[i].lock, NULL);
		if (status)
		{
			ft_putstr_fd("_init_fork, mutex creation\n", 2);
			return (NULL);
		}
		pointer[i].taken = 0;
		i++;
	}
	return (pointer);
}

t_philo	*init_philo(int number_of_philo, t_info *info)
{
	t_philo	*phi;
	int		i;

	i = 0;
	phi = malloc(sizeof(*phi) * number_of_philo);
	if (!phi)
		return (NULL);
	while (i < number_of_philo)
	{
		phi[i].id = i + 1;
		phi[i].t_last_meal = get_time();
		if (phi[i].t_last_meal == -1)
			return (NULL);
		phi[i].eat_count = 0;
		if (pthread_mutex_init(&phi[i].mut_count, NULL) == -1
			|| pthread_mutex_init(&phi[i].mut_last, NULL) == -1)
			return (NULL);
		phi[i].info_tab = info;
		phi[i].right_fork = &info->all_fork[i];
		phi[i].left_fork = &info->all_fork[(i + 1) % info->time_to[QTY_PHILO]];
		i++;
	}
	return (phi);
}
