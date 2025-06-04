/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:19:11 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/30 20:51:51 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include "map.h"

typedef struct	s_int_array
{
	int32_t	*arr;
	size_t	size;
}	t_int_array;

bool int_array_diff(
		t_int_array *minuend,
		t_int_array *subtrahend,
		t_map *out
		);

#endif
