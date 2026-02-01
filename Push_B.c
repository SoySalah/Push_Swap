/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:31:39 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/19 15:57:36 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **Node1, t_list **Node2)
{
	int		size;
	t_list	*current;

	size = ft_lstsize(*Node1);
	if (size == 0)
		return ;
	current = *Node1;
	*Node1 = current->next;
	current->next = *Node2;
	*Node2 = current;
	write(1, "pb\n", 3);
}
