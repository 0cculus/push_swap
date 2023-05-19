/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:56:41 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/18 14:04:39 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fewer_steps(t_stack *head, int max)
{
	t_stack	*current;
	int		front;
	int		back;

	back = 0;
	front = 0;
	current = head;
	while (current->val != max)
	{
		front++;
		current = current->next;
	}
	current = head;
	while (current->val != max)
	{
		back--;
		current = current->prev;
	}
	if (ft_absolute(front) < ft_absolute(back))
		return (front);
	else
		return (back);
}
