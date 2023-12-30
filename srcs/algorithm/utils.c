/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:50:31 by xberger           #+#    #+#             */
/*   Updated: 2023/12/29 17:35:46 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	node_on_top(t_stack **stack, t_stack *top_node, char stack_id)
{
	while (*stack != top_node)
	{
		if (stack_id == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_id == 'b')
		{
			if (top_node ->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

t_stack	*get_cheapest(t_stack *a)
{
	while (a != NULL)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}

void	min_top_stack(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
