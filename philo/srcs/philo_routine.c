/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:13 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/23 13:10:16 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philosophers.h"

int	start_philo_routine(t_table *info)
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
			return (status);
		}
		usleep(5);
		i++;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Hello from philo %d\n", philo->id);
	while (1 && philo->table_info->death_philo)
	{
	}
	return (NULL);
}
