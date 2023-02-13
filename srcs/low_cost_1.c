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

static uint32_t index_in_b(uint32_t order, uint32_t b_top)
{
	if (order > b_top)
		return (order - b_top);
	return (b_top + order - 1);
}

void	set_b(uint32_t index, t_push_swap *push_swap)
{
	static uint32_t	top_order = 0;
	uint32_t r_cost;
	uint32_t rr_cost;

	index = index_in_b(index, top_order);
	r_cost = index;
	rr_cost = push_swap->b_weight - index;
	if (r_cost < rr_cost)
	{
		while (r_cost)
		{
			rb(push_swap);
			r_cost--;
			top_order++;
		}
	}
	else
	{
		while (rr_cost)
		{
			rrb(push_swap);
			rr_cost--;
			top_order--;
		}
	}
}

void	place_in_b(uint32_t index, t_push_swap *push_swap)
{
	uint32_t	r_cost;
	uint32_t	rr_cost;

	r_cost = index;
	rr_cost = push_swap->a_weight - index;
	if (r_cost < rr_cost)
	{
		while (r_cost)
		{
			ra(push_swap);
			r_cost--;
		}
	}
	else
	{
		while (rr_cost)
		{
			rra(push_swap);
			rr_cost--;
		}
	}
	pb(push_swap);
}

void	empty_b(t_push_swap *push_swap)
{
	while (push_swap->b_weight)
	{
		pa(push_swap);
	}
}

void	low_cost_sort(t_push_swap *push_swap)
{
	uint32_t	lower_cost_index;
	uint32_t	lower_cost;
	uint32_t	i_cost;
	uint32_t	i;

	while (push_swap->a_weight)
	{
		i = 0;
		lower_cost = UINT32_MAX;
		lower_cost_index = 0;
		while (i < push_swap->a_weight)
		{
			i_cost = cost_of(i, push_swap);
			if (i_cost < lower_cost)
			{
				lower_cost = i_cost; 
				lower_cost_index = i;
			}
			i++;
		}
		set_b(push_swap->stack_a[lower_cost_index], push_swap);
		place_in_b(lower_cost_index, push_swap);
	}
	empty_b(push_swap);
}