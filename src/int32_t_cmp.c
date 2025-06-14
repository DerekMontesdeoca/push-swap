/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int32_t_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:16:58 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/07 00:21:01 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int	int32_t_lt(int32_t a, int32_t b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return (0);
}

int	int32_t_cmp(void *a, void *b)
{
	int32_t	int32_a;
	int32_t	int32_b;

	int32_a = *(int32_t *)a;
	int32_b = *(int32_t *)b;
	if (int32_a > int32_b)
		return (1);
	if (int32_a < int32_b)
		return (-1);
	else
		return (0);
}
