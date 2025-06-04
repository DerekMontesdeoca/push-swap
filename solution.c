/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:29:40 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/31 16:34:36 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include "array.h"
#include "push_swap.h"
#include "split_insert.h"

bool	split_then_insert(t_push_swap *ps)
{
	t_split_insert	split_insert;
	bool			ok;

	ok = false;
	if (split_insert_make(&split_insert, ps))
	{
		if (split_insert.lis.size != split_insert.numbers.size)
		{
			push_non_lis_to_b_and_pivot_split(&split_insert);
			insert_sort_to_a(&split_insert);
		}
		split_insert_destroy(&split_insert);
		ok = true;
	}
	return (ok);
}
