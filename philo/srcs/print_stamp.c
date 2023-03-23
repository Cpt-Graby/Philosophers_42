/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:17:21 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/23 20:02:10 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_putstamp(long int number)
{
	char	c;

	if (number < 0)
	{
		ft_putstamp(number);
		ft_putstr_fd("-", 1);
	}
	else if (number > 9)
	{
		ft_putstamp(number / 10);
		ft_putstamp(number % 10);
	}
	else
	{
		c = number + '0';
		write(1, &c, 1);
	}
}

void	print_stamp(long int time, char *msg_action, int num)
{
	ft_putstamp(time);
	ft_putstr_fd(": Philosopher ", 1);
	ft_putstamp(num);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(msg_action, 1);
	return ;
}
