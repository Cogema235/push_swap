/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:46:34 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:29:57 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_push_swap *push_swap)
{
	sa(push_swap);
}

void	sort_3(t_push_swap *push_swap)
{
	int32_t	min;
	int32_t	max;

	min = push_swap->stack_a[min_a_index(push_swap)];
	max = push_swap->stack_a[max_a_index(push_swap)];
	if (is_sorted(&push_swap->stack_a[1], 2))
	{
		if (push_swap->stack_a[0] != max && push_swap->stack_a[0] != min)
			sa(push_swap);
		else
			ra(push_swap);
	}
	else if (is_sorted(push_swap->stack_a, 2))
	{
		rra(push_swap);
		if (push_swap->stack_a[0] == min)
			sa(push_swap);
	}
	else
	{
		ra(push_swap);
		sa(push_swap);
	}
}

void	selection_sort(t_push_swap *push_swap)
{
	while (push_swap->a_weight > 3
		&& !is_sorted(push_swap->stack_a, push_swap->a_weight))
	{
		set_a(min_a_index(push_swap), push_swap);
		pb(push_swap);
	}
	if (!is_sorted(push_swap->stack_a, 3))
		sort_3(push_swap);
	empty_b(push_swap);
}

void	range_selection_sort(t_push_swap *push_swap)
{
	uint32_t	chunk_size;
	int32_t		start;
	int32_t		end;
	int32_t		max;

	max = push_swap->a_weight - 1;
	if (push_swap->stacks_len < 200)
		chunk_size = max / 5;
	else
		chunk_size = max / 11;
	chunk_size = max / 5;
	start = 0;
	end = chunk_size;
	while (end < max + (int32_t)chunk_size)
	{
		while (push_first_in_range_to_b(push_swap, start, end))
			;
		start = end;
		end += chunk_size;
	}
	empty_b_sort(push_swap);
}
