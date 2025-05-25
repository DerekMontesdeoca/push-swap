/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:52:10 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/06 03:59:10 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_intlist
{
	int					data;
	struct s_intlist	*next;
}	t_intlist;

typedef struct s_stacks
{
	t_intlist	*a;
	t_intlist	*b;
}	t_stacks;

void		push(t_intlist **stack, t_intlist *new_node);

t_intlist	*pop(t_intlist **stack);

void		rotate(t_intlist **stack);

void		rrotate(t_intlist **stack);

void		swap(t_intlist **stack);

void		pop_push(t_intlist **to_pop, t_intlist **to_push);

bool		make_stacks(int n_nbrs, char **strs, t_intlist *node_arr,
				t_stacks *stacks);

bool	stacks_print(t_intlist **as, t_intlist **bs);

void	f(t_intlist **a, t_intlist **b, int n_elems, bool asc);

#endif
