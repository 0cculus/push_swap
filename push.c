/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:35:28 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/12 12:56:03 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **from, t_stack **to, char *move)
{
	t_stack	*new_tail;
	int		length_a;

	if (*from)
	{
		length_a = ft_list_count(*from);
		new_tail = *from;
		*from = (*from)->next;
		(*from)->prev = new_tail->prev;
		(*from)->prev->next = *from;
		if (length_a == 1)
			*from = NULL;
		if (!*to)
		{
			*to = new_tail;
			(*to)->next = *to;
			(*to)->prev = *to;
		}
		else
			ft_move_node(to, new_tail);
		if (move)
			ft_putendl_fd(move, TERM_OUTPUT);
	}
}
