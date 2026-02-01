/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_chunking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:50:12 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/29 19:04:47 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*im_maxing(t_list **Stack_a)
{
	t_list	*current;
	t_list	*max;

	current = *Stack_a;
	max = current;
	while (current)
	{
		if (current->index > max->index)
			max = current;
		current = current->next;
	}
	return (max);
}

static int	get_count(t_list *Stack_b, t_list *max)
{
	t_list	*current;
	int		count;

	current = Stack_b;
	count = 0;
	while (current && current != max)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static void	im_chunking_back_raah(t_list **Stack_a, t_list **Stack_b)
{
	t_list	*max;
	int		size;
	int		count;

	while (*Stack_b)
	{
		size = ft_lstsize(*Stack_b);
		max = im_maxing(Stack_b);
		count = get_count(*Stack_b, max);
		if (size / 2 >= count)
		{
			while ((*Stack_b)->index != max->index)
				rotate_b(Stack_b);
		}
		else
		{
			while ((*Stack_b)->index != max->index)
				reverse_b(Stack_b);
		}
		push_a(Stack_a, Stack_b);
	}
}

static void	lets_push(t_list **Stack_a, t_list **Stack_b, int chunk_size)
{
	int		count;
	t_list	*current;

	current = *Stack_a;
	count = 0;
	while (*Stack_a)
	{
		current = *Stack_a;
		if (current->index <= count)
		{
			push_b(Stack_a, Stack_b);
			count++;
		}
		else if (current->index <= (count + chunk_size))
		{
			push_b(Stack_a, Stack_b);
			rotate_b(Stack_b);
			count++;
		}
		else
			rotate_a(Stack_a);
	}
}

void	im_chunking(t_list **Stack_a, t_list **Stack_b)
{
	int	size;
	int	chunk_size;

	indexing(Stack_a);
	size = ft_lstsize(*Stack_a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	lets_push(Stack_a, Stack_b, chunk_size);
	im_chunking_back_raah(Stack_a, Stack_b);
}
