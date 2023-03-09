/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:13 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/09 19:38:17 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int status;

	philo = (t_philo *)arg;
	printf("Hello from philo %d\n", philo->id);
	printf("I have to eat with the forks:\n");
	printf("fork1: %p\n", philo->self_fork);
	printf("fork2: %p\n", philo->left_fork);
	pthread_mutex_lock(&philo->self_fork->lock);
	printf("lock mutex fork1: %d\n", &philo->self_fork->lock);
	return (NULL);
}
