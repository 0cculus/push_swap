/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:36:33 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/19 09:28:53 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verify_dup(t_stack *head)
{
	t_stack	*current;

	current = head;
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
