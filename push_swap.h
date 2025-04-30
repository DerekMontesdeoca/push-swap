/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:52:10 by dmontesd          #+#    #+#             */
/*   Updated: 2025/04/30 03:49:34 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void push(t_intlist **stack, t_intlist *new_node);

t_intlist	*pop(t_intlist **stack);

void	rotate(t_intlist **stack);

void	rrotate(t_intlist **stack);

void swap(t_intlist **stack);

#endif
