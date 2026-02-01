/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:18:39 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/19 16:02:06 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_list **Node)
{
	t_list	*current;
	t_list	*temp;
	t_list	*new;

	if (!Node || !*Node || !(*Node)->next)
		return ;
	temp = *Node;
	current = *Node;
	new = *Node;
	while (new->next)
		new = new->next;
	while (current->next->next)
		current = current->next;
	current->next = NULL;
	*Node = new;
	new->next = temp;
	write(1, "rra\n", 4);
}

void	reverse_b(t_list **Node)
{
	t_list	*current;
	t_list	*temp;
	t_list	*new;

	if (!Node || !*Node || !(*Node)->next)
		return ;
	temp = *Node;
	current = *Node;
	new = *Node;
	while (new->next)
		new = new->next;
	while (current->next->next)
		current = current->next;
	current->next = NULL;
	*Node = new;
	new->next = temp;
	write(1, "rrb\n", 4);
}
