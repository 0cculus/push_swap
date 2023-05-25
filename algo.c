/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:35:55 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/25 13:52:19 by brheaume         ###   ########.fr       */
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

static void	ft_shake_sort(t_stack **a, t_stack **b)
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

static void	ft_move_sort(t_stack **a, t_stack **b, int len)
{
	int	moves;

	moves = 0;
	while (ft_list_count(*a) != 3 && moves < len)
	{
		if ((*a)->i < len / 2)
			ft_push(a, b, "pb");
		else
			ft_rotate(a, "ra");
		moves++;
	}
	while (ft_list_count(*a) != 3)
	{
		if ((*a)->i < len - 3)
			ft_push(a, b, "pb");
		else
			ft_rotate(a, "ra");
	}
}

void	ft_radix(t_stack **a, t_stack **b)
{
	int		j;
	int		i;

	j = 0;
	while (!ft_check_sort(*a))
	{
		i = 0;
		while (i++ < ft_list_count(*a) + ft_list_count(*b))
		{
			if (((*a)->val >> j) & 1)
				ft_rotate(a, "ra");
			else
				ft_push(a, b, "pb");
		}
		j++;
		while (ft_list_count(*b) != 0)
			ft_push(b, a, "pa");
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	init_len;

	init_len = ft_list_count(*a);
	if (ft_check_sort(*a))
		return ;
	if (init_len <= 3)
		ft_small_sort(a);
	else if (init_len < 5)
		ft_med_sort(a, b);
	else if (init_len < 100)
	{
		ft_move_sort(a, b, init_len);
		ft_small_sort(a);
		while (ft_list_count(*b) != 0)
			ft_shake_sort(a, b);
	}
	else
		ft_radix(a, b);
}
