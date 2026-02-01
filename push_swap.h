/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:24:43 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/21 21:49:38 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	int				content;
	int				index;
	struct t_list	*next;
}					t_list;

void				free_func(char **arr);
void				free_stack(t_list **Stack_a);
int					ft_lstsize(t_list *Node);
char				**ft_split(char *argv[]);
int					im_checking(char *str);
int					checking_duplicate(int *arr, int size);
long long			ft_atoi(char *str);
void				error(void);
void				im_chunking(t_list **Stack_a, t_list **Stack_b);
t_list				**indexing(t_list **Node);
int					lets_parse(char *argv[], t_list **Node);
void				push_a(t_list **Node1, t_list **Node2);
void				push_b(t_list **Node1, t_list **Node2);
t_list				*push_front(t_list **Node, int content);
void				reverse_a(t_list **Node);
void				reverse_b(t_list **Node);
void				rotate_a(t_list **Node);
void				rotate_b(t_list **Node);
void				swap_a(t_list **Node);
void				swap_b(t_list **Node);
void				rreverse(t_list **Node1, t_list **Node2);
void				rrotate(t_list **Node1, t_list **Node2);
void				sswap(t_list **Node1, t_list **Node2);
void				sort_3(t_list **Node);
void				sort_4(t_list **Node1, t_list **Node2);
void				sort_5(t_list **Node1, t_list **Node2);

#endif