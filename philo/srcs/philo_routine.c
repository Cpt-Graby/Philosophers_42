/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:13 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/09 19:00:29 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Hello from philo %d\n", philo->id);
	printf("I have to eat with the forks:\n");
	printf("fork1: %p\n", philo->self_fork);
	printf("fork2: %p\n", philo->left_fork);
	return (NULL);
}
