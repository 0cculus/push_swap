/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:50:52 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/19 15:34:54 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *ft_create_list(char **src)
{
	int		i;
	t_stack *head;

	i = 1;
	if (ft_verify_arg(src[i]))
		head = ft_init_list(ft_atoi(src[i++]));
	else
		ft_error_simple("Bad arguments");
	while (src[i])
	{
		if (ft_verify_arg(src[i]))
			ft_create_node(&head, ft_atoi(src[i]));
		else
			ft_error_simple("Bad arguments");
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac > 1)
	{
		a = ft_create_list(av);
		if (!ft_verify_dup(a))
			ft_error_simple("Duplicate");
		ft_add_index(a);
		ft_pass_through(a);
		//ft_sort(&a, &b);
		ft_free_all(&a, &b);
	}
	return (0);
}
