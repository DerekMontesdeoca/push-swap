/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 03:40:14 by dmontesd          #+#    #+#             */
/*   Updated: 2025/04/30 03:51:25 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void pop_push(t_intlist **to_pop, t_intlist **to_push)
{
	t_intlist *node;
	node = pop(to_pop);
	if (node == NULL)
		return ;
	push(to_push, node);
}

