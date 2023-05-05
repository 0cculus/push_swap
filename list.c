/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:14:52 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/05 16:14:37 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create(t_stack **head, int value)
{
	t_stack *tail;
	t_stack *res;

	res = ft_calloc(NODE, sizeof(t_stack));
	if (!res)
		return ;
	tail = (*head)->prev;
	res->val = value;
	res->next = *head;
	res->prev = tail;
}

t_stack	*ft_init_list(int value)
{
	t_stack *res;

	res = ft_calloc(NODE, sizeof(t_stack));
	if (!res)
		return (NULL);
	res->val = value;
	res->next = res;
	res->prev = res;
	return (res);
}

int	ft_list_count(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
