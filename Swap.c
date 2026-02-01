/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:26:01 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/25 15:18:49 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **Node)
{
	t_list	*current;
	t_list	*temp;

	if (!Node || !*Node || !(*Node)->next)
		return ;
	current = *Node;
	temp = current;
	(*Node) = current->next;
	temp->next = current->next->next;
	(*Node)->next = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **Node)
{
	t_list	*current;
	t_list	*temp;

	if (!Node || !*Node || !(*Node)->next)
		return ;
	current = *Node;
	temp = current;
	(*Node) = current->next;
	temp->next = current->next->next;
	(*Node)->next = temp;
	write(1, "sb\n", 3);
}
