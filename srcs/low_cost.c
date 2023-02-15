/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:46:34 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:29:57 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static uint32_t	a_set_cost(uint32_t index, t_push_swap *push_swap)
{
	uint32_t	r_cost;
	uint32_t	rr_cost;

	r_cost = index;
	rr_cost = push_swap->a_weight - index;
	return (min32(r_cost, rr_cost));
}

uint32_t	set_min_cost(t_push_swap *push_swap)
{
	return (min_a_index(push_swap));
}

uint32_t	set_max_cost(t_push_swap *push_swap)
{
	return (a_set_cost(max_a_index(push_swap), push_swap) + 1);
}

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
		if (push_swap->stack_a[0] == min)
		{
			rra(push_swap);
			sa(push_swap);
		}
		else
			rra(push_swap);
	}
	else
	{
		ra(push_swap);
		sa(push_swap);
	}
}
