/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:20:34 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/17 13:18:50 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H	
# define PHILOSOPHERS_H	

# include <pthread.h>

typedef struct s_philosopher
{
	pthread_t	num;
	int			index;
	float		time_to_eat;
	float		time_to_sleap;
	float		time_to_die;
	int			fork_quantity;
}	t_philo;

//main.c
void	*start_philosopher(void);
int		main_philosopher(int num_arg, char **function_arg);

//time_utils.c
float	get_time_diff_from_start(float start, struct timeval *tv);
float	init_timer(struct timeval *tv);

#endif
