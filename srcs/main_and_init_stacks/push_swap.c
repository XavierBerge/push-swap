/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:19:20 by xberger           #+#    #+#             */
/*   Updated: 2023/12/29 17:40:23 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = false;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = ft_last(*stack);
		last_node->next = node;
	}
}

void	init_stack_a_split(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax(argv[i]))
			free_all(a, argv);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_all(a, argv);
		}
		if (duplicate(*a, (int)n))
		{
			free_all(a, argv);
		}
		append_node(a, (int)n);
		i++;
	}
}

void	init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_errors(a);
		}
		if (duplicate(*a, (int)n))
		{
			free_errors(a);
		}
		append_node(a, (int)n);
		i++;
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (!already_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			main_sort(&a, &b);
	}
	free_stack(&a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc > 1)
		argv++;
	if (argc > 2)
		init_stack_a(&a, argv);
	else if (argc == 2)
	{
		argv = ft_split(*argv, ' ');
		init_stack_a_split(&a, argv);
		free_argv(argv);
	}
	sort(a, b);
}
