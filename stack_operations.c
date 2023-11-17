/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:44:34 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/13 19:31:03 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*populate_stack(int argc, char *argv[])
{
	int		index;
	t_node	*stack_a;
	t_node	*new_node;

	stack_a = NULL;
	index = 1;
	while (index < argc)
	{
		new_node = ft_new(ft_atoi(argv[index]));
		ft_add_back(&stack_a, new_node);
		index++;
	}
	return (stack_a);
}

void	print_stack(t_node **stack_a)
{
	t_node	*current;

	current = *stack_a;
	while (current)
	{
		ft_printf("%d : index %d \n", (current->content), current->index);
		current = current->next;
	}
}

void	radix_sort_binary(t_node **stack_a, t_node **stack_b, int bits)
{
	unsigned int	index;
	unsigned int	len_a;
	int				i;

	i = 0;
	len_a = ft_size(*stack_a);
	while (i < bits)
	{
		index = 0;
		while (index < len_a)
		{
			if (((*stack_a)->index >> i) % 2 == 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			index++;
		}
		push_back(stack_a, stack_b);
		i++;
	}
}

void	push_back(t_node **stack_a, t_node **stack_b)
{
	unsigned int	index;
	unsigned int	len_b;

	index = 0;
	len_b = ft_size(*stack_b);
	while (index < len_b)
	{
		push_a(stack_a, stack_b);
		index++;
	}
}

void	small_stack_sort_handler(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = ft_size(*stack_a);
	if (len_a == 2)
		handle_two_number_stack(stack_a);
	else if (len_a == 3)
		handle_three_number_stack(stack_a);
	else if (len_a == 4 || len_a == 5)
		handle_five_number_stack(stack_a, stack_b);
}
