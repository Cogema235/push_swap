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
	while (push_swap->a_weight > 3)
	{
		set_a(min_a_index(push_swap), push_swap);
		pb(push_swap);
	}
	if (!is_sorted(push_swap->stack_a, 3))
		sort_3(push_swap);
	empty_b(push_swap);
}
