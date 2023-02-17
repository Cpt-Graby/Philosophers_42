/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:49:32 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/17 15:03:08 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/libft.h"
#include "philosophers.h"

/*
void	*start_philosopher(void)
{
	printf("Hello, I am a philosopher\n");
	return (NULL);
}

void	init_philosopher()
{
}
*/
int	main_philosopher(int num_arg, char **function_arg)
{
	struct timeval	tv;
	float			timestamp;
	//pthread_t		philo1;

	(void) function_arg;
	(void) num_arg;
	//pthread_create(&philo1, NULL, &start_philosopher, NULL);
	//pthread_join(philo1, NULL);
	timestamp = init_timer(&tv);
	if (timestamp == -1)
		exit (-1);
	usleep(10);
	printf("Timeflow: +%2.f\n", get_time_diff_from_start(timestamp, &tv));
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
			printf("Invalid arguments");
			exit(-1);
		}
	}
	else
	{
		errno = EINVAL;
		printf("Too many arguments\n");
	}
	return (0);
}
