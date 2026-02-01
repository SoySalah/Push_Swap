/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:51:07 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/19 16:07:45 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*found_min(t_list **Node1)
{
	t_list	*min;
	t_list	*current;

	current = *Node1;
	min = current;
	indexing(Node1);
	while (current)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	return (min);
}

static int	im_counting(t_list **Node1, t_list *min)
{
	t_list	*current;
	int		count;

	current = *Node1;
	count = 0;
	while (current->index != min->index)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	sort_5(t_list **Node1, t_list **Node2)
{
	t_list	*min;
	int		size;
	int		count;

	size = ft_lstsize(*Node1);
	indexing(Node1);
	min = found_min(Node1);
	count = im_counting(Node1, min);
	if (size / 2 > count)
	{
		while ((*Node1)->index != min->index)
			rotate_a(Node1);
	}
	else
	{
		while ((*Node1)->index != min->index)
			reverse_a(Node1);
	}
	push_b(Node1, Node2);
	sort_4(Node1, Node2);
	push_a(Node1, Node2);
}
