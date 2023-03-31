/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:27:43 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 12:02:45 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_stamp(long int time, char *msg_action, t_philo *philo)
{
	t_info	*info;

	info = philo->info_tab;
	if (!safe_var_check(&info->end_routine, &info->safe_end))
	{
		if (pthread_mutex_lock(&info->write) == -1)
			return ;
		printf("%ld: philosopher %d - %s", time - info->time_start,
			philo->id, msg_action);
		if (pthread_mutex_unlock(&info->write) == -1)
			return ;
	}
}

void	custom_sleep(long int time, t_info *info)
{
	long int	i;

	while (!safe_var_check(&info->end_routine, &info->safe_end))
	{
		i = get_time();
		if (i == -1)
			return ;
		if (i >= time)
			break ;
		usleep(500);
	}
	return ;
}

long int	get_time(void)
{
	struct timeval	tv;
	long int		time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
	return (time);
}
