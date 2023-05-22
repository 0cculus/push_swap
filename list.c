/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:14:52 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/19 15:32:34 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_index(t_stack *head)
{
	t_stack	*current;
	t_stack	*top;
	int		value;
	int		len;

	len = ft_list_count(head) - 1;
	while (len > 0)
	{
		value = INT_MIN;
		current = head;
		top = NULL;
		while (current->next != head)
			ft_check_val(&current, &head, &top, &value);
		ft_check_val(&current, &head, &top, &value);
		if (top != NULL)
			top->i = len;
		len--;
	}
}

void	ft_move_node(t_stack **head, t_stack *node)
{
	t_stack	*prev_head;

	prev_head = *head;
	*head = node;
	(*head)->next = prev_head;
	(*head)->prev = prev_head->prev;
	prev_head->prev->next = *head;
	prev_head->prev = node;
}

void	ft_create_node(t_stack **head, int val)
{
	t_stack	*new_tail;
	t_stack	*prev_tail;

	new_tail = ft_calloc(NODE, sizeof(t_stack));
	if (!new_tail)
		return ;
	new_tail->val = val;
	prev_tail = (*head)->prev;
	new_tail->prev = prev_tail;
	new_tail->next = *head;
	(*head)->prev = new_tail;
	prev_tail->next = new_tail;
}

t_stack	*ft_init_list(int val)
{
	t_stack	*res;

	res = ft_calloc(NODE, sizeof(t_stack));
	if (!res)
		return (NULL);
	res->val = val;
	res->next = res;
	res->prev = res;
	return (res);
}

int	ft_list_count(t_stack *head)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = head;
	if (head)
	{
		while (current->next != head)
		{
			current = current->next;
			i++;
		}
		i++;
	}
	return (i);
}
