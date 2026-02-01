/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:15:02 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/21 21:02:25 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_front(t_list **Node, int content)
{
	t_list	*new;

	if (Node == NULL)
	{
		free_stack(Node);
		return (NULL);
	}
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = *Node;
	*Node = new;
	return (new);
}
