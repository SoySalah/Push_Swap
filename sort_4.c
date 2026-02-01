/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:02:33 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/19 16:07:28 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_list **Node1, t_list **Node2)
{
	t_list	*current;
	t_list	*min;

	current = *Node1;
	min = current;
	while (current->next)
	{
		if (current->next->content < min->content)
			min = current->next;
		current = current->next;
	}
	current = *Node1;
	while (current->content != min->content)
	{
		current = current->next;
		rotate_a(Node1);
	}
	push_b(Node1, Node2);
	sort_3(Node1);
	push_a(Node1, Node2);
}
