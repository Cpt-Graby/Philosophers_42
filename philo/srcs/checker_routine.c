/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:47:00 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 15:04:15 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_all_eaten(t_info *info)
{
	int			i;
	t_philo		*p;

	i = 0;
	while (i < info->time_to[QTY_PHILO])
	{
		p = &info->all_philo[i];
		if (safe_var_check(&p->eat_count, &p->mut_count)
			< info->time_to[QTY_MEAL])
			return ;
		i++;
	}
	if (!safe_var_check(&info->end_routine, &info->safe_end))
		safe_var_change(&info->end_routine, &info->safe_end, 1);
}

void	check_for_dead(t_info *info)
{
	int			i;
	long int	time;
	long int	safe_time;
	long int	time_to_die;
	t_philo		*p;

	time_to_die = (long int) info->time_to[TIME_TO_DIE];
	i = 0;
	while (i < info->time_to[QTY_PHILO])
	{
		p = &info->all_philo[i];
		time = get_time();
		safe_time = safe_lvar_check(&p->t_last_meal, &p->mut_last);
		if (time - safe_time >= time_to_die
			&& !safe_var_check(&info->end_routine, &info->safe_end))
		{
			time -= info->time_start;
			pthread_mutex_lock(&info->safe_end);
			info->end_routine += 1;
			pthread_mutex_unlock(&info->safe_end);
			printf("%ld: philosopher %d - %s", time, p->id, "is dead \n");
		}
		i++;
	}
}

void	check_end(t_info *info)
{
	if (info->time_to[QTY_MEAL] != -1)
	{
		while (!safe_var_check(&info->end_routine, &info->safe_end))
		{
			check_for_dead(info);
			check_all_eaten(info);
		}
	}
	else
	{
		while (!safe_var_check(&info->end_routine, &info->safe_end))
			check_for_dead(info);
	}
	usleep(WAIT_TIME +(info->time_to[QTY_PHILO] + info->time_to[TIME_TO_DIE]));
	return ;
}
