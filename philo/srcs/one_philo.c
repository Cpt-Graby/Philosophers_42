/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:29:57 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/23 20:06:31 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	one_philosopher(int time_to_die)
{
	struct timeval	tv;
	int				status;
	int				start;
	int				end_timer;

	status = gettimeofday(&tv, NULL);
	if (status == -1)
		return (-1);
	start = tv.tv_usec;
	end_timer = tv.tv_usec + time_to_die;
	ft_putstr_fd("0: Philosopher 1 start to thing on the meaning of 42.\n", 1);
	while (1 && status != -1)
	{
		status = gettimeofday(&tv, NULL);
		if (status != -1 && tv.tv_usec >= end_timer)
			break ;
	//	usleep(1);
	}
	if (status == -1)
		return (-1);
	print_stamp(tv.tv_usec - start, ": Philosopher 1 died \n", 1);
	return (0);
}
