/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:20:34 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/14 15:07:17 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#ifndef PHILOSOPHERS_H	
# define PHILOSOPHERS_H	

typedef struct s_philosopher
{
	pthread_t	num;
	int			index;
	float		last_time;
}	t_philo;

//main.c
void	*start_philosopher(void);
int		main_philosopher(int num_arg, char **function_arg);

#endif
