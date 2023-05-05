/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:25:18 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/05 15:29:01 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_simple(char *message)
{
	ft_putendl_fd("Error:", ERROR_OUTPUT);
	ft_putendl_fd(message, ERROR_OUTPUT);
	exit(EXIT_FAILURE);
}


