/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:32:45 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/05 16:22:19 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **head)
{
	if (head)
		*head = (*head)->next;
}

void	ft_rr(t_stack **a, t_stack **b)
{
	if (a)
		ft_rotate(a);
	if (b)
		ft_rotate(b);
	ft_putendl_fd("rr", TERM_OUTPUT);
}
