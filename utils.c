/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:02:15 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/19 15:23:29 by brheaume         ###   ########.fr       */
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

int	ft_max(t_stack *head)
{
	int		max;
	t_stack	*current;

	current = head;
	max = current->val;
	while (current->next != head)
	{
		if (max < current->val)
			max = current->val;
		current = current->next;
	}
	return (max);
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

void ft_check_val(t_stack **current, t_stack **head, t_stack **top, int *val)
{
	if ((*current)->val > *val && (*current)->i == 0)
	{
		*val = (*current)->val;
		*top = *current;
		(*top)->val = (*current)->val;
		*current = *head;
	}
	else
		*current = (*current)->next;
}
