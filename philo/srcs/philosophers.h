/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:20:34 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/09 18:56:25 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H	
# define PHILOSOPHERS_H	

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_fork{
	int				taken;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philosopher
{
	pthread_t		thread_id;
	int				id;
	int				alive;
	int				last_meal;
	int				meal_count;
	struct s_table	*table_info;
	t_fork			*left_fork;
	t_fork			*self_fork;
}	t_philo;

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

//fork.c
t_fork	*init_fork(int nomber_of_fork);
void	destroy_fork(t_fork *pointer, int nomber_of_fork);

//time_utils.c
float	get_time_diff_from_start(float start, struct timeval *tv);
float	init_timer(struct timeval *tv);

//philo_thread.c

void	end_philo_routine(t_table *info);
void	start_philo_routine(t_table *info);
void	*routine(void *arg);

#endif
