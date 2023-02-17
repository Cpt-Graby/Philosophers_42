/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:08:48 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/17 13:09:56 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

float	init_timer(struct timeval *tv)
{
	if (gettimeofday(tv, NULL) == -1)
		return (-1);
	return (tv->tv_usec);
}

float	get_time_diff_from_start(float start, struct timeval *tv)
{
	if (gettimeofday(tv, NULL) == -1)
		return (-1);
	else
		return (tv->tv_usec - start);
}
