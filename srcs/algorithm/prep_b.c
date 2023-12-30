/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:05:07 by xberger           #+#    #+#             */
/*   Updated: 2023/12/29 16:34:30 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	int		best_target;

	while (b)
	{
		best_target = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_target)
			{
				best_target = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_target == INT_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	prep_b_nodes(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_b(a, b);
}
