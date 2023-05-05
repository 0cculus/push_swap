/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:05:38 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/05 16:21:54 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **head)
{
	t_stack	*current;
	
	if (ft_list_count(*head) > 1)
	{
		current = *head;
		*head = (*head)->next;
		(*head)->next = current;
	}
}

void	ft_ss(t_stack **a, t_stack **b)
{
	if (a)
		ft_swap(a);
	if (b)
		ft_swap(b);
	ft_putendl_fd("ss", TERM_OUTPUT);
}
