/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:17:48 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/13 16:18:23 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philosophers.h"

void	destroy_fork(t_fork *pointer, int number_of_fork)
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
			exit(status);
		}
		i++;
	}
	free(pointer);
}

void	destroy_all_philo(t_table *info)
{
	int		i;
	int		exit_status;
	t_philo	*philo;

	philo = info->all_philo;
	i = 0;
	while (i < info->qty_philo)
	{
		exit_status = pthread_join(philo[i].thread_id, NULL);
		if (exit_status)
		{
			perror("end_philo_rouotine, thread destroy");
			exit(exit_status);
		}
		i++;
	}
}
