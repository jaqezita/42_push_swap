/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:57:28 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/13 16:18:01 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_node;

	temp_node = *stack_a;
	*stack_a = (*stack_a)->next;
	temp_node->next = *stack_b;
	*stack_b = temp_node;
	ft_printf("pb\n");
}

void	swap_b(t_node **stack_b)
{
	t_node	*temp_node;

	if (*stack_b && (*stack_b)->next)
	{
		temp_node = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_node->next = (*stack_b)->next;
		(*stack_b)->next = temp_node;
	}
	ft_printf("sb\n");
}

void	rotate_b(t_node **stack_b)
{
	t_node	*temp_node;

	if (*stack_b && (*stack_b)->next)
	{
		temp_node = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_node->next = NULL;
		ft_last(*stack_b)->next = temp_node;
	}
	ft_printf("rb\n");
}

void	reverse_rotate_b(t_node **stack_b)
{
	t_node	*temp_node;
	t_node	*aux;

	temp_node = ft_last(*stack_b);
	aux = *stack_b;
	while (aux->next != temp_node)
		aux = aux->next;
	aux->next = NULL;
	temp_node->next = *stack_b;
	(*stack_b) = temp_node;
	ft_printf("rrb\n");
}
