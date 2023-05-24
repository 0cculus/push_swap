/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:14:54 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/23 16:18:39 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_i(t_stack *head)
{
	int		max;
	t_stack	*current;

	current = head;
	max = current->i;
	while (current->next != head)
	{
		if (max < current->i)
			max = current->i;
		current = current->next;
	}
	if (max < current->i)
		max = current->i;
	return (max);
}

int	ft_max(t_stack *head)
{
	int		max;
	t_stack	*current;

	current = head;
	max = current->val;
	while (current->next != head)
	{
		if (max < current->val)
			max = current->val;
		current = current->next;
	}
	if (max < current->val)
		max = current->val;
	return (max);
}

int	ft_min(t_stack *head)
{
	int		min;
	t_stack	*current;

	current = head;
	min = current->val;
	while (current->next != head)
	{
		if (min > current->val)
			min = current->val;
		current = current->next;
	}
	if (min > current->val)
		min = current->val;
	return (min);
}

int	ft_min_i(t_stack *head)
{
	int		min;
	t_stack	*current;

	current = head;
	min = current->i;
	while (current->next != head)
	{
		if (min > current->i)
			min = current->i;
		current = current->next;
	}
	if (min < current->i)
		min = current->i;
	return (min);
}
