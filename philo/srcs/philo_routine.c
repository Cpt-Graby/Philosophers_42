/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:13 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/08 18:08:01 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Hello from philo %d", philo->id);
	return (NULL);
}
