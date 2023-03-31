/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:29:57 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 11:22:41 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	one_philosopher(int time_to_die)
{
	long int		status;
	long int		start;
	long int		end_timer;

	start = 0;
	status = 0;
	start = get_time();
	if (start == -1)
		return (-1);
	end_timer = start + time_to_die;
	ft_putstr_fd("0: Philosopher 1 start to think on the meaning of 42.\n", 1);
	while (1 && status != -1)
	{
		status = get_time();
		if (status != -1 && status >= end_timer)
			break ;
		usleep(2500);
	}
	if (status == -1)
		return (-1);
	printf("%ld, Philosopher 1 died \n", status - start);
	return (0);
}
