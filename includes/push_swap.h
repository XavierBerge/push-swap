/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:11:10 by xberger           #+#    #+#             */
/*   Updated: 2023/12/30 09:50:08 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}	t_stack;

// Handling errors
long			ft_atol(char *str);
int				syntax(char *str);
int				duplicate(t_stack *a, int n);
void			free_stack(t_stack **node);
void			free_errors(t_stack **a);
void			free_argv(char **argv);
void			free_all(t_stack **a, char **argv);

// Utils functions
t_stack			*ft_last(t_stack *lst);
bool			already_sorted(t_stack *a);
int				stack_len(t_stack *stack);
t_stack			*find_max(t_stack *stack);
t_stack			*find_min(t_stack *stack);
t_stack			*get_cheapest(t_stack *a);

// Instructions
void			swap(t_stack **a);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			rotate(t_stack **stack);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			reverse_rotate(t_stack **stack);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			push(t_stack **dst, t_stack **src);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);

// Algorithm and utils for it 
void			sort_three(t_stack **a);
void			main_sort(t_stack **a, t_stack **b);
void			prep_a_nodes(t_stack *a, t_stack *b);
void			prep_b_nodes(t_stack *a, t_stack *b);
void			current_index(t_stack *stack);
void			target_a(t_stack *a, t_stack *b);
void			target_b(t_stack *a, t_stack *b);
void			cheapest(t_stack *stack);
void			cost_analysis(t_stack *a, t_stack *b);
void			push_a_to_b(t_stack **a, t_stack **b);
void			push_b_to_a(t_stack **a, t_stack **b);
void			node_on_top(t_stack **stack, t_stack *cheapest_node,
					char stack_id);
void			reverse_rotate_both(t_stack **a, t_stack **b,
					t_stack *cheapest_node);
void			rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void			min_top_stack(t_stack **a);
void			sort(t_stack *a, t_stack *b);
#endif
