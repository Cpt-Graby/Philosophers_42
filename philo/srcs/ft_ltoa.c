/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:57:06 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/24 11:57:08 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_nbrlen(long int num)
{
	int	count;

	count = 1;
	if (num < 0)
	{
		count++;
		num *= -1;
	}
	while (num > 1000)
	{
		num /= 100;
		count += 2;
	}
	if (num < 10)
		return (count);
	if (num < 100)
		return (count + 1);
	return (count + 2);
}

char	*ft_ltoa(long int n)
{
	int		count;
	int		sign;
	char	*dest;

	count = ft_nbrlen(n);
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	dest = malloc(sizeof(*dest) * (count + 1));
	if (dest == NULL)
		return (NULL);
	dest[count] = '\0';
	while (count)
	{
		dest[--count] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		dest[count] = '-';
	return (dest);
}
