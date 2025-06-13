/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:46:24 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/13 16:10:47 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "push_swap.h"

static bool	print_a(t_intlist_node **ptr_a, size_t n_elem, size_t a_size)
{
	bool	ok;

	if (n_elem < a_size)
	{
		ok = ft_printf("%11d | %11d ", n_elem, (*ptr_a)->data) >= 0;
		*ptr_a = (*ptr_a)->next;
	}
	else
		ok = ft_printf("%11d |             ", n_elem) >= 0;
	return (ok);
}

static bool	print_b(t_intlist_node **ptr_b, size_t n_elem, size_t b_size)
{
	bool	ok;

	if (n_elem < b_size)
	{
		ok = ft_printf("| %11d |\n", (*ptr_b)->data) >= 0;
		*ptr_b = (*ptr_b)->next;
	}
	else
		ok = ft_printf("|             |\n") >= 0;
	return (ok);
}

static bool	print_footer(void)
{
	bool	ok;

	ok = true;
	ok &= ft_printf("            |-------------|-------------|\n") >= 0;
	ok &= ft_printf("\n") >= 0;
	return (ok);
}

static bool	print_header(void)
{
	bool	ok;

	ok = true;
	ok &= ft_printf("\n") >= 0;
	ok &= ft_printf("            |-------------|-------------|\n") >= 0;
	ok &= ft_printf(
		"            | %s | %s |\n", "     A     ", "     B     "
	) >= 0;
	ok &= ft_printf("            |-------------|-------------|\n") >= 0;
	return (ok);
}

[[nodiscard]] bool	push_swap_print(t_push_swap *ps)
{
	size_t			i;
	t_intlist_node	*ptr_a;
	t_intlist_node	*ptr_b;
	bool			ok;

	ok = true;
	ok &= print_header();
	i = 0;
	ptr_a = ps->a.head;
	ptr_b = ps->b.head;
	while (i < ps->a.len || i < ps->b.len)
	{
		ok &= print_a(&ptr_a, i, ps->a.len);
		ok &= print_b(&ptr_b, i, ps->b.len);
		++i;
	}
	ok &= print_footer();
	if (!ok)
		ft_fprintf(STDERR_FILENO, "print error\n");
	return (ok);
}

