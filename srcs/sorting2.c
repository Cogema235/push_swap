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

uint32_t	min_a_index(t_push_swap *push_swap)
{
	uint32_t	min_index;
	uint32_t	index;
	int32_t		current_value;
	int32_t		min;

	index = 0;
	min = push_swap->stack_a[0];
	min_index = 0;
	while (index < push_swap->a_weight)
	{
		current_value = push_swap->stack_a[index];
		if (current_value < min)
		{
			min = current_value;
			min_index = index;
		}
		index++;
	}
	return (min_index);
}

uint32_t	max_a_index(t_push_swap *push_swap)
{
	uint32_t	max_index;
	uint32_t	index;
	int32_t		current_value;
	int32_t		max;

	index = 0;
	max = push_swap->stack_a[0];
	max_index = 0;
	while (index < push_swap->a_weight)
	{
		current_value = push_swap->stack_a[index];
		if (current_value > max)
		{
			max = current_value;
			max_index = index;
		}
		index++;
	}
	return (max_index);
}

void	set_b(uint32_t index, t_push_swap *push_swap)
{
	uint32_t	r_cost;
	uint32_t	rr_cost;

	r_cost = index;
	rr_cost = push_swap->b_weight - index;
	if (r_cost < rr_cost)
	{
		while (r_cost)
		{
			rb(push_swap);
			r_cost--;
		}
	}
	else
	{
		while (rr_cost)
		{
			rrb(push_swap);
			rr_cost--;
		}
	}
}
