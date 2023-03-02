/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:20:34 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/28 18:43:33 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H	
# define PHILOSOPHERS_H	

# include <pthread.h>

typedef struct s_philosopher
{
	pthread_t	philo_id;
	int			alive;
}	t_philo;

typedef struct s_fork{
	int				taken;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_table{
	int		qty_philo;
	t_fork	*all_fork;
	t_philo	*all_philo;
	float	t_to_die;
	float	t_to_eat;
	float	t_to_sleep;
	int		qty_meal;
	int		death_philo;
}	t_table;

//main.c
void	*start_philosopher(void);

//main_philosopher.c
int		main_philosopher(int num_arg, char **function_arg);

//time_utils.c
float	get_time_diff_from_start(float start, struct timeval *tv);
float	init_timer(struct timeval *tv);

#endif
