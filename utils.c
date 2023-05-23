/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:02:15 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/23 16:16:33 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*freed;

	current = *a;
	while (current->next != *a)
	{
		freed = current;
		current = current->next;
		freed = ft_xfree(freed);
	}
	ft_xfree(current);
	ft_xfree(*b);
}

void	ft_pass_through(t_stack *head)
{
	t_stack	*current;

	current = head;
	if (head)
	{
		while (current->next != head)
		{
			ft_putendl_fd("Node:", TERM_OUTPUT);
			ft_putnbendl_fd(current->i, TERM_OUTPUT);
			ft_putnbendl_fd(current->val, TERM_OUTPUT);
			current = current->next;
		}
		ft_putendl_fd("Node:", TERM_OUTPUT);
		ft_putnbendl_fd(current->i, TERM_OUTPUT);
		ft_putnbendl_fd(current->val, TERM_OUTPUT);
	}
	else
		ft_putendl_fd("(null)", TERM_OUTPUT);
}

void	ft_check_val(t_stack **node, t_stack **head, t_stack **top, int *val)
{
	if ((*node)->val > *val && (*node)->i == 0)
	{
		*val = (*node)->val;
		*top = *node;
		(*top)->val = (*node)->val;
		*node = *head;
	}
	else
		*node = (*node)->next;
}
