/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:05:41 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/19 15:57:32 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **Node1, t_list **Node2)
{
	int		size;
	t_list	*current;

	size = ft_lstsize(*Node2);
	if (size == 0)
		return ;
	current = *Node2;
	*Node2 = current->next;
	current->next = *Node1;
	*Node1 = current;
	write(1, "pa\n", 3);
}
