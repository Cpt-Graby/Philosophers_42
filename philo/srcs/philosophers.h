/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:20:34 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/23 20:01:00 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H	
# define PHILOSOPHERS_H	

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <errno.h>
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
	long int		t_last_meal;
	int				meal_count;
	struct s_table	*table_info;
	t_fork			*left_fork;
	t_fork			*self_fork;
}	t_philo;

typedef struct s_table{
	int			qty_philo;
	t_fork		*all_fork;
	t_philo		*all_philo;
	int			t_to_die;
	int			t_to_eat;
	int			t_to_sleep;
	int			qty_meal;
	int			death_philo;
	long int	time_start;
}	t_table;

//main.c
void		*start_philosopher(void);
int			main_philosopher(int num_arg, char **function_arg);
int			argv_checker(int user_ac, char **new_argv);

//init_all.c
int			init_all_struct(int num_arg, char **ascii_arg, t_table *info);
int			init_table(int num_arg, char **ascii_arg, t_table *info);
t_fork		*init_fork(int number_of_fork);
t_philo		*init_philo(int number_of_philo, t_table *info);

//destroy_all.c
int			destroy_fork(t_fork *pointer, int nomber_of_fork);
int			destroy_all_philo(t_table *info);

//philo_routine.c
int			start_philo_routine(t_table *info);
void		*routine(void *arg);

//time_utils.c
long int	get_time(void);

//one_philo.c
int			one_philosopher(int time_to_die);

//utils.c
int			ft_strlen(char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);

//check_arg.c
int			ft_ascii_in_int(char *num_string);
int			ft_ascii_is_number(char *str);
int			argv_checker(int user_ac, char **new_argv);

//print_stamp.c
void		print_stamp(long int time, char *msg_action, int num);

#endif
