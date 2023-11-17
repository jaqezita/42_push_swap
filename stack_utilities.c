/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:31:43 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/13 19:32:06 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_nodes(t_node **stack_a)
{
	unsigned int	index;
	t_node			*current;
	t_node			*aux;

	current = *stack_a;
	index = 0;
	while (current)
	{
		aux = *stack_a;
		while (aux)
		{
			if (current->content > aux->content)
				current->index++;
			aux = aux->next;
		}
		current = current->next;
	}
}

int	number_bits(int argc)
{
	unsigned int	number_bits;
	int				number;

	number = argc - 2;
	number_bits = 0;
	while (number > 0)
	{
		number_bits++;
		number = number / 2;
	}
	return (number_bits);
}

void	handle_top_lt_middle(t_node **stack_a, int top, int middle, int last)
{
	if (top < last && middle > last)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (top > last && middle > last)
	{
		reverse_rotate_a(stack_a);
	}
}

void	handle_top_gt_middle(t_node **stack_a, int top, int middle, int last)
{
	if (top < last && middle < last)
	{
		swap_a(stack_a);
	}
	else if (top > last && middle < last)
	{
		rotate_a(stack_a);
	}
	else if (top > last && middle > last)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
}

void	process_half_stack(t_node **stack_a, t_node **stack_b, int pos)
{
	int		len;

	len = ft_size(*stack_a);
	if (pos <= len / 2)
	{
		while (pos > 0)
		{
			rotate_a(stack_a);
			pos--;
		}
		push_b(stack_a, stack_b);
	}
	else
	{
		while (pos < len)
		{
			reverse_rotate_a(stack_a);
			pos++;
		}
		push_b(stack_a, stack_b);
	}
}
