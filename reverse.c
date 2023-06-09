/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:35:57 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/12 09:13:46 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack **head, char *move)
{
	if (*head)
	{
		*head = (*head)->prev;
		if (move)
			ft_putendl_fd(move, TERM_OUTPUT);
	}
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse(a, NULL);
	ft_reverse(b, NULL);
	ft_putendl_fd("rrr", TERM_OUTPUT);
}
