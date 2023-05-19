/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:35:55 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/19 15:13:58 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current->next != head)
	{
		if (current->val > current->next->val)
			return (INCORRECT);
		current = current->next;
	}
	return (CORRECT);
}

/*  -- Old dumb sort algo -- */
static void	ft_dumb_sort(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		moves;
	int		max;

	max = ft_max(*b);
	current = *b;
	moves = ft_fewer_steps(*b, max);
	while ((*b)->prev->val < max)
	{
		if (moves < 0 )
			ft_reverse(b, "rrb");
		else
			ft_rotate(b, "rb");
	}
	if (ft_list_count(*b) > 1)
		ft_reverse(b, "rrb");
	ft_push(b, a, "pa");
}

static void	ft_move_sort(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		max;

	if (!(*b))
		ft_push(a, b, "pb");
	else
	{
		max = ft_max(*b);
		ft_push(a, b, "pb");
		current = *b;
		while (current->val < max)
		{
			ft_rotate(b, "rb");
			current = current->next;
		}
	}
}

/*static void	ft_move_back(t_stack **a, t_stack **b)
{
	int		max;

	max = ft_max(*a);
	ft_push(b, a, "pa");
	if (ft_fewer_steps(*a, max) < 0)
		while ((*a)->prev->val < max)
			ft_rotate(a, "ra");
	else
		while ((*a)->prev->val < max)
			ft_reverse(a, "rra");
}*/

void	ft_sort(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *a;
	if (ft_check_sort(*a))
	{
		return ;
	}
	while (ft_list_count(*a) != 0)
		ft_move_sort(a, b);
	while (ft_list_count(*b) != 0)
		ft_dumb_sort(a, b);
}
