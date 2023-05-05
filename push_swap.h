/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:39:23 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/05 16:26:03 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define TERM_OUTPUT 1
# define ERROR_OUTPUT 2
# define NODE 1

typedef struct	s_stack
{
	int				i;
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		ft_list_count(t_stack *head);

void	ft_swap(t_stack **head);
void	ft_rotate(t_stack **head);
void	ft_reverse(t_stack **head);
void	ft_error_simple(char *message);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_create(t_stack **head, int value);

t_stack	*ft_init_list(int value);

#endif
