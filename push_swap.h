/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:39:23 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/25 13:15:27 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define NODE 1
# define TERM_OUTPUT 1
# define ERROR_OUTPUT 2
# define CORRECT 1
# define INCORRECT 0
# define DUP 2

typedef struct s_stack
{
	int				i;
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	long	last_val;
	long	val;
	int		len;
	int		i;
}	t_data;

int		ft_max(t_stack *head);
int		ft_min(t_stack *head);
int		ft_max_i(t_stack *head);
int		ft_min_i(t_stack *head);
int		ft_verify_arg(char *src);
int		ft_verify_dup(t_stack *head);
int		ft_list_count(t_stack *head);
int		ft_check_sort(t_stack *head);
int		ft_fewer_steps(t_stack *head, int goal);

void	ft_add_index(t_stack *head);
void	ft_small_sort(t_stack **head);
void	ft_pass_through(t_stack *head);
void	ft_error_simple(char *message);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a, t_stack **b);
void	ft_radix(t_stack **a, t_stack **b);
void	ft_swap(t_stack **head, char *move);
void	ft_free_all(t_stack **a, t_stack **b);
void	ft_rotate(t_stack **head, char *move);
void	ft_reverse(t_stack **head, char *move);
void	ft_med_sort(t_stack **head, t_stack **to);
void	ft_create_node(t_stack **head, int value);
void	ft_move_node(t_stack **head, t_stack *node);
void	ft_push(t_stack **from, t_stack **to, char *move);
void	ft_check_val(t_stack **node, t_stack **head, t_stack **top, int *val);

t_stack	*ft_init_list(int value);
t_stack	*ft_get_lowest_value_node(t_stack *head, t_data nb);

#endif
