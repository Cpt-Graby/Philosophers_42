/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:49:32 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/21 15:04:19 by agonelle         ###   ########.fr       */
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
		ft_putendl_fd("Too few arguments", 2);
		errno = EINVAL;
	}
	else if (user_ac == 4 || user_ac == 5)
	{
		if (argv_checker(user_ac, argv))
			main_philosopher(user_ac, argv);
		else
		{
			ft_putendl_fd("Invalid arguments", 2);
			errno = EINVAL;
		}
	}
	else
	{
		ft_putendl_fd("Too many arguments", 2);
		errno = EINVAL;
	}
	return (0);
}

int	main_philosopher(int num_arg, char **function_arg)
{
	t_table			table_info;

	if (init_table(num_arg, function_arg, &table_info))
		return (2);
	if (table_info.qty_philo == 1)
	{
		if (one_philosopher(table_info.t_to_die) == -1)
		{
			ft_putendl_fd("time_syscall_error", 2);
			return (-1);
		}
		return (0);
	}
	start_philo_routine(&table_info);
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
