/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:48:13 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/07 15:00:21 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"

static bool	resize_strategy(t_op_vector *v);

bool	op_vector_push(t_op_vector *v, t_op op)
{
	if (v->len == v->cap)
		if (!resize_strategy(v))
			return (false);
	v->data[v->len++] = op;
	return (true);
}

t_op	op_vector_at(t_op_vector *v, size_t index)
{
	return v->data[index];
}

size_t	op_vector_len(t_op_vector *v)
{
	return v->len;
}

size_t	op_vector_cap(t_op_vector *v)
{
	return v->cap;
}

static bool	resize_strategy(t_op_vector *v)
{
	t_op	*new_data;
	size_t	new_size;

	if (v->cap == 0)
		new_size = 1;
	else
		new_size = v->cap *  2;
	new_data = malloc(sizeof(t_op[new_size]));
	if (new_data == NULL)
		return (false);
	ft_memcpy(new_data, v->data, sizeof(t_op[v->len]));
	free(v->data);
	v->data = new_data;
	v->cap = new_size;
	return (true);
}
