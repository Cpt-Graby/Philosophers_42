/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:23:19 by agonelle          #+#    #+#             */
/*   Updated: 2023/03/31 12:01:07 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

static int	ft_ascii_in_int(char *num_string)
{
	int	len;

	len = ft_strlen(num_string);
	if (len > 11)
		return (0);
	else if (len == 11 && num_string[0] == '-')
	{
		if (ft_strncmp(num_string, "-2147483648", 12) > 0)
			return (0);
		else
			return (1);
	}
	else if (len > 10 && num_string[0] != '-')
		return (0);
	else if (len == 11 && num_string[0] != '-')
	{
		if (ft_strncmp(num_string, "2147483647", 11) > 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

static int	ft_ascii_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	put_argv_in_tab(int user_ac, char **new_argv, int *arg_tab)
{
	int	i;

	i = 0;
	arg_tab[4] = -1;
	while (i < user_ac)
	{
		arg_tab[i] = ft_atoi(new_argv[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (arg_tab[i] <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	argv_checker(int user_ac, char **new_argv)
{
	int	i;

	i = 0;
	while (i < user_ac)
	{
		if (!ft_ascii_is_number(new_argv[i]) || !ft_ascii_in_int(new_argv[i]))
			return (0);
		i++;
	}
	return (1);
}
