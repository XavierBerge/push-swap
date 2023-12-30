/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:29:17 by xberger           #+#    #+#             */
/*   Updated: 2023/12/29 17:45:21 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node != NULL)
	{
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rotate_both(a, b, cheapest_node);
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
			reverse_rotate_both(a, b, cheapest_node);
		node_on_top(a, cheapest_node, 'a');
		node_on_top(b, cheapest_node->target_node, 'b');
		pb(b, a);
	}
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	node_on_top(a, (*b)->target_node, 'a');
	pa(a, b);
}

t_stack	*ft_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	sort_three(t_stack **a)
{
	t_stack	*max_node;

	max_node = find_max(*a);
	if (max_node == *a)
		ra(a);
	else if ((*a)-> next == max_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	main_sort(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !already_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !already_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !already_sorted(*a))
	{
		prep_a_nodes(*a,*b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prep_b_nodes(*a, *b);
		push_b_to_a(a, b);
	}
	current_index(*a);
	min_top_stack(a);
}
