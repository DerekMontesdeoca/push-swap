/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:29:40 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/06 04:38:36 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

void	f(t_intlist **a, t_intlist **b, int n_elems, bool asc)
{
	if (n_elems <= 1)
		return ;
	if (n_elems <= 2)
	{
		if ((asc && (*a)->data > (*a)->next->data) || (!asc && (*a)->data < (*a)->next->data))
			swap(a);
		return ;
	}
	// split
	int pivot = (*a)->data;
	int pushed = 0;
	int	i;
	i = 1;
	rotate(a);
	while (i < n_elems)
	{
		if ((asc && (*a)->data < pivot) || (!asc && (*a)->data > pivot))
		{
			pop_push(a, b);
			++pushed;
		}
		else
			rotate(a);
		++i;
	}
	int remaining = n_elems - 1 - pushed;
	i = 0;
	while (i < remaining)
	{
		rrotate(a);
		++i;
	}
	f(a, b, remaining, asc);
	rrotate(a);
	f(b, a, pushed, !asc);
	i = 0;
	while (i < pushed)
	{
		pop_push(b, a);
		++i;
	}
}
