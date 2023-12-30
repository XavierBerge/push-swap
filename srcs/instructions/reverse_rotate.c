/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:53:36 by xberger           #+#    #+#             */
/*   Updated: 2023/12/30 09:48:01 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	while (second_node->next)
	{
		first_node = second_node;
		second_node = second_node->next;
	}
	second_node->next = *stack;
	first_node->next = NULL;
	*stack = second_node;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
