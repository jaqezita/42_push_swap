/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:17:01 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/09 20:20:19 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_node **lst, void (*del)(void *))
{
	t_node	*aux;
	t_node	*current;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{	
		aux = current->next;
		free(current);
		current = aux;
	}
	*lst = NULL;
}

int	ft_size(t_node *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_node	*ft_last(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_last(*lst);
		last->next = new;
	}
}

t_node	*ft_new(int content)
{
	t_node	*ptr;

	ptr = malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->index = 0;
	ptr->next = NULL;
	return (ptr);
}
