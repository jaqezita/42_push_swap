/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_specific_size_handlers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:34:01 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/13 19:29:48 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_two_number_stack(t_node **stack_a)
{
	swap_a(stack_a);
}

void	handle_three_number_stack(t_node **stack_a)
{
	t_node	*current;
	int		top;
	int		middle;
	int		last;

	current = *stack_a;
	last = ft_last(current)->index;
	top = current->index;
	middle = current->next->index;
	if (top < middle)
		handle_top_lt_middle(stack_a, top, middle, last);
	else if (top > middle)
		handle_top_gt_middle(stack_a, top, middle, last);
}

void	handle_five_number_stack(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = ft_size(*stack_a);
	while (len_a > 3)
	{
		smallest_to_stack_b(stack_a, stack_b);
		len_a--;
	}
	handle_three_number_stack(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	smallest_to_stack_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	t_node	*min_node;
	int		pos;

	current = *stack_a;
	min_node = current;
	pos = find_min_node(stack_a);
	process_half_stack(stack_a, stack_b, pos);
}

int	find_min_node(t_node **stack_a)
{
	t_node	*current;
	t_node	*min_node;
	int		len;
	int		i;
	int		pos;

	len = ft_size(*stack_a);
	current = *stack_a;
	min_node = current;
	i = 0;
	pos = 0;
	while (i < len)
	{
		if (current->content < min_node->content)
		{	
			min_node = current;
			pos = i;
		}
		i++;
		current = current->next;
	}
	return (pos);
}
