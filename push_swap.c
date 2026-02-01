/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:14:21 by abdesala          #+#    #+#             */
/*   Updated: 2026/02/01 10:34:10 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_numbers(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 5)
		sort_5(stack_a, stack_b);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 2)
		swap_a(stack_a);
}

static int	check_spaces(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argc > i)
	{
		j = 0;
		while ((argv[i][j] == ' ') || (argv[i][j] >= '\t'
				&& argv[i][j] <= '\r'))
			j++;
		if (!argv[i][j])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_spaces(argc, argv))
		error();
	if (!lets_parse(argv, &stack_a))
		error();
	size = ft_lstsize(stack_a);
	if (size <= 5)
	{
		small_numbers(&stack_a, &stack_b, size);
		free_stack(&stack_a);
		return (0);
	}
	im_chunking(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
