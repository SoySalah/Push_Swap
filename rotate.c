/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:17:18 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/21 21:18:05 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **Node)
{
	t_list	*temp;
	t_list	*current;

	if (!Node || !*Node || !(*Node)->next)
		return ;
	temp = *Node;
	current = *Node;
	*Node = temp->next;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **Node)
{
	t_list	*temp;
	t_list	*current;

	if (!Node || !*Node || !(*Node)->next)
		return ;
	temp = *Node;
	current = *Node;
	*Node = temp->next;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}
