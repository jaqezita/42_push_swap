/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:57:17 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/13 18:15:03 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_node;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	temp_node = *stack_b;
	*stack_b = (*stack_b)->next;
	temp_node->next = *stack_a;
	*stack_a = temp_node;
	ft_printf("pa\n");
}

void	swap_a(t_node **stack_a)
{
	t_node	*temp_node;

	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		temp_node->next = (*stack_a)->next;
		(*stack_a)->next = temp_node;
	}
	ft_printf("sa\n");
}

void	rotate_a(t_node **stack_a)
{
	t_node	*temp_node;

	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_last(*stack_a)->next = temp_node;
		temp_node->next = NULL;
	}
	ft_printf("ra\n");
}

void	reverse_rotate_a(t_node **stack_a)
{
	t_node	*temp_node;
	t_node	*aux;

	temp_node = ft_last(*stack_a);
	aux = *stack_a;
	while (aux->next != temp_node)
		aux = aux->next;
	aux->next = NULL;
	temp_node->next = *stack_a;
	(*stack_a) = temp_node;
	ft_printf("rra\n");
}
