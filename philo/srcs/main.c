/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:49:32 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/14 15:08:43 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/libft.h"
#include <pthread.h>
#include <sys/time.h>

void	*start_philosopher()
{
	printf("Hello, I am a philosopher\n");
	return (NULL);
}

int	main_philosopher(int num_arg, char **function_arg)
{
	time_t	timer = 0;
	pthread_t	philo1;

	(void) function_arg;
	(void) num_arg;
	printf("%ld\n", timer);
	pthread_create(&philo1, NULL, &start_philosopher, NULL);
	pthread_join(philo1, NULL);
	usleep(10);
	printf("%ld\n", timer);
	return (0);
}

int	main(int argc, char **argv)
{
	int		user_argc;

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
