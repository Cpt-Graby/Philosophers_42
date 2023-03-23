/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:13 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/23 20:15:44 by agonelle         ###   ########.fr       */
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
	t_philo		*philo;
	long int	time;
	long int	time_death;

	philo = (t_philo *)arg;
	printf("Hello from philo %d\n", philo->id);
	time_death = philo->table_info->t_to_die + philo->table_info->time_start;
	printf("%ld \n", time_death);
	while (1 && !philo->table_info->death_philo)
	{
		print_stamp(time, "is thinking\n", philo->id);
		time = get_time();
		if (time > time_death)
		{
			philo->table_info->death_philo = 1;
			print_stamp(time - philo->table_info->time_start, " just died\n", philo->id);
		}
	}
	return (NULL);
}
