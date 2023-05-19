/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:32:45 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/12 09:13:43 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **head, char *move)
{
	if (*head)
	{
		*head = (*head)->next;
		if (move)
			ft_putendl_fd(move, TERM_OUTPUT);
	}
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, NULL);
	ft_rotate(b, NULL);
	ft_putendl_fd("rr", TERM_OUTPUT);
}
