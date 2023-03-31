/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:13 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 13:32:17 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philosophers.h"

int	fork_action(t_philo *philo, int action)
{
	if (!action)
	{
		if (pthread_mutex_lock(&philo->left_fork->lock))
			return (-1);
		if (pthread_mutex_lock(&philo->right_fork->lock))
			return (-1);
	}
	else
	{
		if (pthread_mutex_unlock(&philo->left_fork->lock))
			return (-1);
		if (pthread_mutex_unlock(&philo->right_fork->lock))
			return (-1);
	}
	return (0);
}

int	philo_eat_action(t_philo *philo)
{
	long int	tmp_time;

	if (fork_action(philo, 0) == -1)
		return (-1);
	tmp_time = get_time();
	if (tmp_time == -1)
		return (-1);
	if (safe_lvar_change(&(philo->t_last_meal), &philo->mut_last,
			tmp_time) == -1)
		return (-1);
	print_stamp(philo->t_last_meal, "has taken the left fork\n", philo);
	print_stamp(philo->t_last_meal, "has taken the right fork\n", philo);
	print_stamp(philo->t_last_meal, "is eating\n", philo);
	if (safe_var_change(&philo->eat_count, &philo->mut_count,
			philo->eat_count + 1) == -1)
		return (-1);
	custom_sleep(philo->t_last_meal + philo->info_tab->time_to[TIME_TO_EAT],
		philo->info_tab);
	if (fork_action(philo, 1) == -1)
		return (-1);
	return (0);
}

int	start_philo_routine(t_info *info)
{
	int		i;
	int		status;
	t_philo	*philo;

	philo = info->all_philo;
	i = 0;
	while (i < info->time_to[QTY_PHILO])
	{
		status = pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]);
		if (status)
		{
			perror("init_philo_routine, thread create");
			return (status);
		}
		i++;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	long int	time;
	t_info		*info;

	philo = (t_philo *)arg;
	info = philo->info_tab;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!safe_var_check(&info->end_routine, &info->safe_end))
	{
		if (philo_eat_action(philo) == -1)
			break ;
		if (safe_var_check(&info->end_routine, &info->safe_end))
			break ;
		time = get_time();
		if (time == -1)
			break ;
		print_stamp(time, "is sleeping\n", philo);
		custom_sleep(time + info->time_to[TIME_TO_SLEEP], info);
		time = get_time();
		if (time == -1)
			break ;
		print_stamp(time, "is thinking\n", philo);
	}
	return (NULL);
}
