/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:46:24 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/29 03:32:45 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	print_header(void);
static void	print_footer(void);
static void	print_a(t_intlist_node **ptr_a, size_t n_elem, size_t a_size);
static void	print_b(t_intlist_node **ptr_b, size_t n_elem, size_t b_size);

void	push_swap_print(t_push_swap *ps)
{
	size_t			i;
	t_intlist_node	*ptr_a;
	t_intlist_node	*ptr_b;

	print_header();
	i = 0;
	ptr_a = ps->a.head;
	ptr_b = ps->b.head;
	while (i < ps->a.len || i < ps->a.len)
	{
		print_a(&ptr_a, i, ps->a.len);
		print_b(&ptr_b, i, ps->b.len);
		++i;
	}
	print_footer();
}

static void	print_a(t_intlist_node **ptr_a, size_t n_elem, size_t a_size)
{
	if (n_elem < a_size)
	{
		ft_printf("%11d | %11d ", n_elem, (*ptr_a)->data);
		*ptr_a = (*ptr_a)->next;
	}
	else
		ft_printf("%11d |             ", n_elem);
}

static void	print_b(t_intlist_node **ptr_b, size_t n_elem, size_t b_size)
{
	if (n_elem < b_size)
	{
		ft_printf("| %11d |\n", (*ptr_b)->data);
		*ptr_b = (*ptr_b)->next;
	}
	else
		ft_printf("|             |\n");
}

static void	print_footer(void)
{
	ft_printf("            |-------------|-------------|\n");
	ft_printf("\n");
}

static void	print_header(void)
{
	ft_printf("\n");
	ft_printf("            |-------------|-------------|\n");
	ft_printf("            | %s | %s |\n", "     A     ", "     B     ");
	ft_printf("            |-------------|-------------|\n");
}
