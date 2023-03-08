/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:49:32 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/08 17:49:16 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/libft.h"
#include "philosophers.h"

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
