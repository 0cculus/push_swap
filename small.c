/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:37:32 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/23 16:13:49 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_sort(t_stack **head)
{
	int	max;

	max = ft_max(*head);
	if (ft_check_sort(*head))
		return ;
	if ((*head)->val == max)
		ft_rotate(head, "ra");
	else if ((*head)->next->val == max)
		ft_reverse(head, "rra");
	if ((*head)->val > (*head)->next->val)
		ft_swap(head, "sa");
}

void	ft_med_sort(t_stack **head, t_stack **to)
{
	int		min;
	int		moves;

	min = ft_min(*head);
	moves = ft_fewer_steps(*head, min);
	if ((*head)->val != min)
	{
		while ((*head)->val != min)
		{
			if (moves < 0)
				ft_reverse(head, "rra");
			else
				ft_rotate(head, "ra");
		}
	}
	ft_push(head, to, "pb");
	ft_small_sort(head);
	ft_push(to, head, "pa");
}
