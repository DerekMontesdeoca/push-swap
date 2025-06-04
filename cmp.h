/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:24:17 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/03 03:15:33 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMP_H
# define CMP_H

# include <stdint.h>
# include <stddef.h>

typedef int	(*t_cmp_func)(void *, void *);

int		int32_t_cmp(void *a, void *b);

int		size_t_cmp(void *a, void *b);

void	*max(void *arr, size_t nmemb, size_t size, t_cmp_func cmp);

void	*min(void *arr, size_t nmemb, size_t size, t_cmp_func cmp);

size_t	min_index(void *arr, size_t nmemb, size_t size, t_cmp_func cmp);

#endif
