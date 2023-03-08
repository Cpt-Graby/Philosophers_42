/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:11:17 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/08 17:46:04 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <stdlib.h>

void	end_philo_routine(t_table *info)
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

void	start_philo_routine(t_table *info)
{
	int		i;
	int		status;
	t_philo	*philo;

	philo = info->all_philo;
	i = 0;
	while (i < info->qty_philo)
	{
		status = pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]);
		if (status)
		{
			perror("init_philo_routine, thread create");
			exit(status);
		}
		i++;
	}
}
