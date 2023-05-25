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

static long	ft_atol(char *src)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while (src[i] && (src[i] == 32 || (src[i] >= 9 && src[i] <= 13)))
		i++;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
			neg *= -1;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		res *= 10;
		res += (src[i] - '0');
		i++;
	}
	return (neg * res);
}

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
	int		i;
	long	nb;

	i = 0;
	if (!src)
		return (INCORRECT);
	nb = ft_atol(src);
	if (nb < INT_MIN || nb > INT_MAX)
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
