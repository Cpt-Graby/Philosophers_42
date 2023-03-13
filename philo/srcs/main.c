/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:49:32 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/13 16:16:16 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/libft.h"
#include "philosophers.h"

int	main(int argc, char **argv)
{
	int		user_ac;

	user_ac = argc - 1;
	argv++;
	if (user_ac < 4)
	{
		errno = EINVAL;
		printf("Too few arguments\n");
	}
	else if (user_ac == 4 || user_ac == 5)
	{
		if (argv_checker(user_ac, argv))
			main_philosopher(user_ac, argv);
		else
		{
			errno = EINVAL;
			printf("Invalid arguments");
		}
	}
	else
	{
		errno = EINVAL;
		printf("Too many arguments\n");
	}
	return (0);
}

int	main_philosopher(int num_arg, char **function_arg)
{
	struct timeval	tv;
	t_table			table_info;
	float			timestamp;

	if (init_table(num_arg, function_arg, &table_info))
		return (0);
	start_philo_routine(&table_info);
	/*
	timestamp = init_timer(&tv);
	if (timestamp == -1)
		exit (-1);
	usleep(10);
	printf("Timeflow: +%2.f\n", get_time_diff_from_start(timestamp, &tv));
	*/
	destroy_all_philo(&table_info);
	destroy_fork(table_info.all_fork, table_info.qty_philo);
	return (0);
}

int	argv_checker(int user_ac, char **new_argv)
{
	int	i;

	i = 0;
	while (i < user_ac)
	{
		if (ft_ascii_is_number(new_argv[i]) == 0)
			return (0);
		if (ft_ascii_in_int(new_argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
