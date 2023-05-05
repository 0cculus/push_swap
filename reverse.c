/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:35:57 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/05 16:25:42 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack **head)
{
	if (head)
		*head = (*head)->prev;
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse(a);
	ft_reverse(b);
	ft_putendl_fd("rrr", TERM_OUTPUT);
}
