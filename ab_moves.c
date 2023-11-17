/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:57:55 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/07 21:09:14 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_node;

	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		temp_node->next = (*stack_a)->next;
		(*stack_a)->next = temp_node;
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp_node = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_node->next = (*stack_b)->next;
		(*stack_b)->next = temp_node;
	}
}

void	rotate_rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_node;

	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_last(*stack_a)->next = temp_node;
		temp_node->next = NULL;
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp_node = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_node->next = NULL;
		ft_last(*stack_b)->next = temp_node;
	}
}

void	reverse_rotate_rrr(t_node **stack_a, t_node **stack_b)
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
	temp_node = ft_last(*stack_b);
	aux = *stack_b;
	while (aux->next != temp_node)
		aux = aux->next;
	aux->next = NULL;
	temp_node->next = *stack_b;
	(*stack_b) = temp_node;
}
