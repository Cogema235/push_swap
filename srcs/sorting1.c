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

uint32_t	max_b_index(t_push_swap *push_swap)
{
	uint32_t	max_index;
	uint32_t	index;
	int32_t		current_value;
	int32_t		max;

	index = 0;
	max = push_swap->stack_b[0];
	max_index = 0;
	while (index < push_swap->b_weight)
	{
		current_value = push_swap->stack_b[index];
		if (current_value > max)
		{
			max = current_value;
			max_index = index;
		}
		index++;
	}
	return (max_index);
}

void	empty_b_sort(t_push_swap *push_swap)
{
	while (push_swap->b_weight)
	{
		set_b(max_b_index(push_swap), push_swap);
		pa(push_swap);
	}
}

void	set_a(uint32_t index, t_push_swap *push_swap)
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
}

void	empty_b(t_push_swap *push_swap)
{
	while (push_swap->b_weight)
	{
		pa(push_swap);
	}
}
