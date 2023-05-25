/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:05:38 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/25 13:13:42 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **head, char *move)
{
	int	temp;

	if (ft_list_count(*head) > 1)
	{
		temp = (*head)->val;
		(*head)->val = (*head)->next->val;
		(*head)->next->val = temp;
		temp = (*head)->i;
		(*head)->i = (*head)->next->i;
		(*head)->next->i = temp;
		if (move)
			ft_putendl_fd(move, TERM_OUTPUT);
	}
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a, NULL);
	ft_swap(b, NULL);
	ft_putendl_fd("ss", TERM_OUTPUT);
}
