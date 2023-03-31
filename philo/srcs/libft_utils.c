/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:54:51 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 11:59:36 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include "philosophers.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	i = 0;
	cp1 = (unsigned char *) s1;
	cp2 = (unsigned char *) s2;
	while (cp1[i] && cp2[i] && cp1[i] == cp2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return (cp1[i] - cp2[i]);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

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
