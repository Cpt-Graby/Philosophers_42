/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:58:45 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 15:10:50 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info_table;

	argc -= 1;
	argv++;
	if (argc < 4)
	{
		ft_putstr_fd("Too few arguments\n", 2);
		errno = EINVAL;
	}
	else if (argc == 4 || argc == 5)
		main_philosopher(argc, argv, &info_table);
	else
	{
		ft_putstr_fd("Too many arguments\n", 2);
		errno = EINVAL;
	}
	return (0);
}

int	main_philosopher(int argc, char **argv, t_info *info_table)
{
	int	status;

	if (!argv_checker(argc, argv)
		|| !put_argv_in_tab(argc, argv, info_table->time_to))
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		errno = EINVAL;
	}
	if (info_table->time_to[QTY_PHILO] == 1)
	{
		status = one_philosopher(info_table->time_to[TIME_TO_DIE]);
		return (status);
	}
	if (init_all_struct(info_table))
		return (errno);
	start_philo_routine(info_table);
	check_end(info_table);
	status = destroy_all(info_table);
	if (status)
		return (status);
	return (0);
}
