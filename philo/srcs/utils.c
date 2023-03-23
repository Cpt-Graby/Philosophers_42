/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:54:51 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/23 16:10:12 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

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
