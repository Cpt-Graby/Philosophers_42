/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:25:56 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/03 12:31:23 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philosophers.h"

t_fork	*init_fork(int number_of_fork)
{
	t_fork	*pointer;
	int		i;
	int		status;

	i = 0;
	pointer = malloc(sizeof(*pointer) * number_of_fork);
	if (!pointer)
		return (NULL);
	while (i < number_of_fork)
	{
		printf("Hello there, lock %d is lock\n", i);
		status = pthread_mutex_init(&pointer[i].lock, NULL);
		if (status)
		{
			perror("_init_fork, mutex creation");
			exit(status);
		}
		pointer[i].taken = 0;
		i++;
	}
	return (pointer);
}

void	destroy_fork(t_fork *pointer, int number_of_fork)
{
	int	i;
	int	status;

	i = 0;
	while (i < number_of_fork)
	{
		status = pthread_mutex_destroy(&pointer[i].lock);
		if (status)
		{
			perror("_destroy_fork, mutex destroy");
			exit(status);
		}
		free(&pointer[i]);
		i++;
	}
	free(pointer);
}
