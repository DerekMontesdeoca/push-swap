/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:52:10 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 02:52:23 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include "intlist.h"
# include "map.h"

typedef enum e_op
{
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RRA,
	OP_RB,
	OP_RRB,
	OP_RR,
	OP_RRR,
	OP_SA,
	OP_SB,
	OP_SS,
}	t_op;

const char	*op_to_string(t_op op);

bool		op_from_string(t_op *op, char *str);

typedef struct s_op_vector
{
	t_op	*data;
	size_t	len;
	size_t	cap;
} t_op_vector;

bool	op_vector_push(t_op_vector *v, t_op op);

t_op	op_vector_at(t_op_vector *v, size_t index);

size_t	op_vector_len(t_op_vector *v);

size_t	op_vector_cap(t_op_vector *v);

void	op_vector_destroy_contents(t_op_vector *v);

typedef struct s_push_swap
{
	t_intlist		a;
	t_intlist		b;
	t_op_vector 	ops;
	int				*sorted_numbers;
	t_map			indices;
	t_intlist_node	*nodes;
	size_t			n_numbers;
}	t_push_swap;

bool	push_swap_make(t_push_swap *ps, int	*numbers, size_t size);

void	push_swap_destroy_contents(t_push_swap *ps);

bool	push_swap_print(t_push_swap *ps);

bool	push_swap_print_ops(t_push_swap *ps);

bool	push_swap_pa(t_push_swap *ps);

bool	push_swap_pb(t_push_swap *ps);

bool	push_swap_sa(t_push_swap *ps);

bool	push_swap_sb(t_push_swap *ps);

bool	push_swap_ss(t_push_swap *ps);

bool	push_swap_ra(t_push_swap *ps);

bool	push_swap_rb(t_push_swap *ps);

bool	push_swap_rr(t_push_swap *ps);

bool	push_swap_rra(t_push_swap *ps);

bool	push_swap_rrb(t_push_swap *ps);

bool	push_swap_rrr(t_push_swap *ps);

bool	push_swap_run_op(t_push_swap *ps, t_op op);

/**
 * Parse an array of int32_t from an array of string.
 */
int32_t	*parse_numbers(char **strs, size_t size);

#endif
