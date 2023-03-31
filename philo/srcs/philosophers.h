/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:59:10 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 15:04:19 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H	
# define PHILOSOPHERS_H	

# define WAIT_TIME 50000

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>

enum	e_time_to{
	QTY_PHILO,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	QTY_MEAL
};

typedef struct s_fork{
	int				taken;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philosopher
{
	pthread_t		thread_id;
	int				id;
	pthread_mutex_t	mut_last;
	long int		t_last_meal;
	int				eat_count;
	pthread_mutex_t	mut_count;
	struct s_info	*info_tab;
	t_fork			*left_fork;
	t_fork			*right_fork;
}	t_philo;

typedef struct s_info{
	int				time_to[5];
	t_fork			*all_fork;
	t_philo			*all_philo;
	pthread_mutex_t	write;
	pthread_mutex_t	safe_end;
	int				end_routine;
	long int		time_start;
}	t_info;

//safe_var_check.c
int			safe_var_check(int *var, pthread_mutex_t *safe_end);
int			safe_var_change(int *var, pthread_mutex_t *mutex, int new_war);
long int	safe_lvar_check(long int *var, pthread_mutex_t *safe_end);
int			safe_lvar_change(long int *var, pthread_mutex_t *mutex,
				long int new_war);

//main.c
void		*start_philosopher(void);
int			main_philosopher(int argc, char **argv, t_info *info_table);

//init_all.c
int			init_all_struct(t_info *info);
int			init_info(t_info *info);
t_fork		*init_fork(int number_of_fork);
t_philo		*init_philo(int number_of_philo, t_info *info);

//destroy_all.c
int			destroy_all(t_info *info);

//philo_routine.c
int			start_philo_routine(t_info *info);
void		*routine(void *arg);

//one_philo.c
int			one_philosopher(int time_to_die);

//libft_utils.c
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
char		*ft_ltoa(long int n);

//check_arg.c
int			ft_strlen(char *s);
int			argv_checker(int user_ac, char **new_argv);
int			put_argv_in_tab(int user_ac, char **new_argv, int *arg_tab);

//print_stamp.c
void		print_stamp(long int time, char *msg_action, t_philo *philo);
void		custom_sleep(long int time, t_info *info);
long int	get_time(void);

//checker_routine.c
void		check_end(t_info *info);

#endif
