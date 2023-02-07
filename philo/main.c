/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:49:32 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/06 15:19:47 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib42/libft.h"
#include <pthread.h>

void	*start_philosopher(void)
{
	printf("Hello i'mm philo");
	return (NULL);
}

int	main_philosopher(int num_arg, char **function_arg)
{
	pthread_t	philo1;

	(void) function_arg;
	(void) num_arg;
	pthread_create(&philo1, NULL, &start_philosopher, NULL);
	pthread_join(philo1, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	int	user_argc;

	user_argc = argc - 1;
	argv++;
	if (user_argc < 4)
	{
		errno = EINVAL;
		printf("Too few arguments\n");
	}
	else if (user_argc == 4 || user_argc == 5)
		main_philosopher(user_argc, argv);
	else
	{
		errno = EINVAL;
		printf("Too many arguments\n");
	}
	return (0);
}
