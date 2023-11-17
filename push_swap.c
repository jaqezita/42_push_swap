/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:34:39 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/13 19:05:29 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		bits;

	stack_a = NULL;
	stack_b = NULL;
	error_check(argc, argv);
	stack_a = populate_stack(argc, argv);
	if (is_stack_sorted(&stack_a))
	{
		ft_clear(&stack_a, free);
		return (0);
	}
	rank_nodes(&stack_a);
	bits = number_bits(argc);
	if (ft_size(stack_a) < 6)
		small_stack_sort_handler(&stack_a, &stack_b);
	else
		radix_sort_binary(&stack_a, &stack_b, bits);
	ft_clear(&stack_a, free);
	ft_clear(&stack_b, free);
	return (0);
}
