/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:13:40 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/21 21:44:42 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	to_array(t_list **Node, int *arr)
{
	int		i;
	t_list	*current;

	current = *Node;
	i = 0;
	while (current)
	{
		arr[i] = current->content;
		i++;
		current = current->next;
	}
}

static void	ft_sort(int *arr, int count)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (count - 1 > i)
	{
		j = i + 1;
		while (count > j)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_index(int *arr, t_list **Node, int count)
{
	t_list	*current;
	int		i;

	current = *Node;
	while (current)
	{
		i = 0;
		while (count > i)
		{
			if (current->content == arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

t_list	**indexing(t_list **Node)
{
	int	count;
	int	*arr;

	count = ft_lstsize(*Node);
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	to_array(Node, arr);
	ft_sort(arr, count);
	assign_index(arr, Node, count);
	free(arr);
	return (Node);
}
