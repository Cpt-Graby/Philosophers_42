/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_safe_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:41:49 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 12:31:12 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	safe_var_check(int *var, pthread_mutex_t *safe_end)
{
	int	ret;

	if (pthread_mutex_lock(safe_end))
		return (-1);
	ret = *var;
	if (pthread_mutex_unlock(safe_end))
		return (-1);
	return (ret);
}

int	safe_var_change(int *var, pthread_mutex_t *mutex, int new_war)
{
	if (pthread_mutex_lock(mutex))
		return (-1);
	*var = new_war;
	if (pthread_mutex_unlock(mutex))
		return (-1);
	return (0);
}

int	safe_lvar_change(long int *var, pthread_mutex_t *mutex, long int new_war)
{
	if (pthread_mutex_lock(mutex))
		return (-1);
	*var = new_war;
	if (pthread_mutex_unlock(mutex))
		return (-1);
	return (0);
}

long int	safe_lvar_check(long int *var, pthread_mutex_t *mutex)
{
	long int	ret;

	if (pthread_mutex_lock(mutex))
		return (-1);
	ret = *var;
	if (pthread_mutex_unlock(mutex))
		return (-1);
	return (ret);
}
