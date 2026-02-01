/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:54:45 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/25 15:17:15 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushing(t_list **Node, int *arr, int i)
{
	while (i > 0)
	{
		i--;
		push_front(Node, arr[i]);
	}
}

static int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (size - 1 > i)
	{
		if (arr[i] >= arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	*get_arr(char **result, int *arr)
{
	long long	n;
	int			i;

	i = 0;
	while (result[i])
	{
		if (!im_checking(result[i]))
			return (NULL);
		n = ft_atoi(result[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (NULL);
		arr[i] = n;
		i++;
	}
	if (!checking_duplicate(arr, i))
		return (NULL);
	return (arr);
}

static void	check_if_sorted(int *arr, char **result, int len)
{
	if (is_sorted(arr, len))
	{
		free(arr);
		free_func(result);
		exit(0);
	}
}

int	lets_parse(char *argv[], t_list **Node)
{
	int		len;
	int		*arr;
	char	**result;

	result = ft_split(argv);
	if (!result)
		return (0);
	len = 0;
	while (result[len])
		len++;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (free_func(result), 0);
	if (!get_arr(result, arr))
	{
		free(arr);
		free_func(result);
		return (0);
	}
	check_if_sorted(arr, result, len);
	pushing(Node, arr, len);
	free(arr);
	free_func(result);
	return (1);
}
