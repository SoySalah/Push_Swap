/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:15:49 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/21 17:21:47 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *Node)
{
	t_list	*current;
	int		i;

	if (Node == NULL)
	{
		return (0);
	}
	i = 0;
	current = Node;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
