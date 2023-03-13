/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:13 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/13 16:21:06 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philosophers.h"

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

void	*routine(void *arg)
{
	t_philo	*philo;
	int		status;

	philo = (t_philo *)arg;
	printf("Hello from philo %d\n", philo->id);
	printf("I have to eat with the forks:\n");
	printf("fork1: %p\n", philo->self_fork);
	printf("fork2: %p\n", philo->left_fork);
	pthread_mutex_lock(&philo->self_fork->lock);
	printf("lock mutex fork1: %d\n", &philo->self_fork->lock);
	return (NULL);
}
