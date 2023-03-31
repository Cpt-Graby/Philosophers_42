/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:17:48 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 15:23:11 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philosophers.h"

static int	destroy_all_philo(t_philo *philo, int qty_philo)
{
	int		i;
	int		exit_status;

	i = 0;
	while (i < qty_philo)
	{
		exit_status = pthread_join(philo[i].thread_id, NULL);
		if (exit_status)
			return (errno);
		i++;
	}
	exit_status = pthread_mutex_destroy(&philo->mut_last);
	if (exit_status)
		return (errno);
	exit_status = pthread_mutex_destroy(&philo->mut_count);
	if (exit_status)
		return (errno);
	free(philo);
	return (0);
}

static int	destroy_fork(t_fork *pointer, int number_of_fork)
{
	int	i;
	int	status;

	i = 0;
	while (i < number_of_fork)
	{
		status = pthread_mutex_destroy(&pointer[i].lock);
		if (status)
		{
			perror("_destroy_fork, mutex destroy");
			return (errno);
		}
		i++;
	}
	free(pointer);
	return (0);
}

static int	destroy_part_info(t_info *info)
{
	int	status;

	status = pthread_mutex_destroy(&info->write);
	if (status)
	{
		perror("_destroy_fork, mutex destroy");
		return (errno);
	}
	status = pthread_mutex_destroy(&info->safe_end);
	if (status)
	{
		perror("_destroy_fork, mutex destroy");
		return (errno);
	}
	return (0);
}

int	destroy_all(t_info *info)
{
	int	status;

	status = destroy_fork(info->all_fork, info->time_to[QTY_PHILO]);
	if (status)
		return (status);
	status = destroy_all_philo(info->all_philo, info->time_to[QTY_PHILO]);
	if (status)
		return (status);
	status = destroy_part_info(info);
	if (status)
		return (status);
	return (0);
}
