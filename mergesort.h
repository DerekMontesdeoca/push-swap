/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:42:16 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/28 19:05:41 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGESORT_H
# define MERGESORT_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>

bool	mergesort(int32_t *src, int32_t *dest, size_t size);

#endif
