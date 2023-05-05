/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:50:52 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/05 15:33:54 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int	i;
	t_stack *a;
	t_stack *b;

	(void) b;
	if (ac < 1)
	{
		i = 0;
		a = ft_init_list(ft_atoi(av[i++]));
		while (av[i])
		{
			if (ft_isstrdigit(av[i]))
				ft_create(&a, ft_atoi(av[i]));
			else
				ft_error_simple("Bad arguments");
			i++;
		}
	}
}
