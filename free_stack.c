/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:55:47 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/19 10:07:25 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **Stack_a)
{
	t_list	*current;
	t_list	*temp;

	current = *Stack_a;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*Stack_a = NULL;
}
