/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:36:33 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/25 14:53:23 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verify_dup(t_stack *head)
{
	t_stack	*current;
	t_stack	*check;
	int		len;

	check = head;
	current = head;
	len = ft_list_count(head);
	while (len > 0)
	{
		while (current->next != head)
		{
			if (current->val == check->val && current != check)
				return (INCORRECT);
			current = current->next;
		}
		if (current->val == check->val && current != check)
			return (INCORRECT);
		check = check->next;
		len--;
	}
	return (CORRECT);
}

int	ft_verify_arg(char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (INCORRECT);
	if (src[i] == '-')
		i++;
	while (src[i])
	{
		if (ft_isdigit(src[i]))
			i++;
		else
			return (INCORRECT);
	}
	return (CORRECT);
}
