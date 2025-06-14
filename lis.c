/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 06:07:32 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:26:56 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "algo.h"

static void	lis_destroy_contents(t_lis *state)
{
	free(state->tails);
	free(state->indices);
	*state = (t_lis){};
}

static bool	lis_make(t_lis *state, int32_t *data, size_t size)
{
	*state = (t_lis){};
	state->data = data;
	state->tails = malloc(sizeof(size_t[size]));
	state->indices = malloc(sizeof(size_t[size]));
	state->len = 0;
	state->cap = size;
	if (state->tails == NULL || state->indices == NULL)
	{
		lis_destroy_contents(state);
		return (false);
	}
	return (true);
}

static bool	lis_reconstruct(
		t_lis *state,
		int32_t **data_out,
		size_t *size_out
) {
	ssize_t	i;
	size_t	n;

	*data_out = malloc(sizeof(int32_t[state->len]));
	*size_out = state->len;
	if (*data_out == NULL)
		return (false);
	i = state->tails[state->len - 1];
	n = 0;
	while (i != -1)
	{
		(*data_out)[state->len - 1 - n] = state->data[i];
		i = state->indices[i];
		++n;
	}
	return (true);
}

static bool	lis_compute(t_lis *state, int32_t **data_out, size_t *size_out)
{
	size_t	i;
	size_t	insert_index;

	i = 0;
	while (i < state->cap)
	{
		insert_index = lower_bound_idx(state->tails, state->data, state->len,
				state->data[i]) - state->tails;
		state->tails[insert_index] = i;
		if (insert_index == 0)
			state->indices[i] = -1;
		else
			state->indices[i] = state->tails[insert_index - 1];
		if (insert_index == state->len)
			++state->len;
		++i;
	}
	return (lis_reconstruct(state, data_out, size_out));
}

bool	lis(int32_t *arr, size_t size, int32_t **data_out, size_t *size_out)
{
	t_lis	state;
	bool	result;

	if (!lis_make(&state, arr, size))
		return (false);
	result = lis_compute(&state, data_out, size_out);
	free(state.indices);
	free(state.tails);
	return (result);
}
