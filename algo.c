/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:35:55 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/23 16:10:20 by brheaume         ###   ########.fr       */
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
	int		moves;
	int		max_i;
	int		max;

	max = ft_max(*b);
	max_i = ft_max_i(*b);
	moves = ft_fewer_steps(*b, max);
	while ((*b)->prev->i < max_i)
	{
		if (moves < 0)
			ft_reverse(b, "rrb");
		else
			ft_rotate(b, "rb");
	}
	if (ft_list_count(*b) > 1)
		ft_reverse(b, "rrb");
	ft_push(b, a, "pa");
}

static void	ft_move_sort(t_stack **a, t_stack **b, int *moves, int len)
{
	if ((*a)->i < len / 2)
		ft_push(a, b, "pb");
	else
		ft_rotate(a, "ra");
	(*moves)++;
}

static void	ft_sort_back(t_stack **a)
{
	int		max;

	max = ft_max(*a);
	if (ft_fewer_steps(*a, max) < 0)
		while ((*a)->i > 0)
			ft_rotate(a, "ra");
	else
		while ((*a)->i < 0)
			ft_reverse(a, "rra");
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	init_len;
	int		moves;

	moves = 0;
	init_len = ft_list_count(*a);
	if (ft_check_sort(*a))
		return ;
	while (ft_list_count(*a) != 3 && moves < init_len)
		ft_move_sort(a, b, &moves, init_len);
	while (ft_list_count(*a) != 3)
	{
		if ((*a)->i < init_len - 3)
			ft_push(a, b, "pb");
		else
			ft_rotate(a, "ra");
	}
	ft_small_sort(a);
	while (ft_list_count(*b) != 0)
		ft_dumb_sort(a, b);
	if (!ft_check_sort(*a))
		ft_sort_back(a);
}
