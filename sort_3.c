/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:49:00 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/20 15:56:04 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **Stack_a)
{
	t_list	*current;
	t_list	*max;

	current = *Stack_a;
	max = current;
	while (current->next)
	{
		if (current->next->content > max->content)
			max = current->next;
		current = current->next;
	}
	current = *Stack_a;
	if (current->content == max->content)
		rotate_a(Stack_a);
	else if (current->next->content == max->content)
		reverse_a(Stack_a);
	current = *Stack_a;
	if (current->content > current->next->content)
		swap_a(Stack_a);
}
