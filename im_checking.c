/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:41:01 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/21 21:19:21 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checking_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (size > i)
	{
		j = i + 1;
		while (size > j)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	skip_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long long	ft_atoi(char *str)
{
	long long	result;
	long long	temp;
	int			i;
	int			sign;

	result = 0;
	i = 0;
	sign = skip_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = result;
		result = result * 10 + (str[i] - '0');
		if (temp > result)
		{
			if (sign == -1)
				return (2147483648);
			return (2147483648);
		}
		i++;
	}
	return (result * sign);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	im_checking(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		if (!str[i])
			break ;
		if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (0);
			if (i > 0 && str[i - 1] != ' ')
				return (0);
			i++;
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
