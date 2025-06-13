/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:43:31 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/13 15:57:56 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

# include "push_swap.h"

/**
 * Solves push swap by separating the "in order" elements from the "out of
 * order" elements. Elements out of order are moved to the right and split
 * up and down using a pivot (their median). Then, elements on the right are
 * "insertion sorted" into the left, taking into account the least amount of
 * moves required for each one to go into its sorted position. Finally, the
 * smallest number is put on top of the left stack.
 */
bool	split_then_insert(t_push_swap *ps);

#endif
