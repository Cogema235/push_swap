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

uint32_t	min_b_index(t_push_swap *push_swap)
{
	uint32_t	min_index;
	uint32_t	index;
	int32_t		current_value;
	int32_t		min;

	index = 0;
	min = push_swap->stack_b[0];
	min_index = 0;
	while (index < push_swap->a_weight)
	{
		current_value = push_swap->stack_b[index];
		if (current_value < min)
		{
			min = current_value;
			min_index = index;
		}
		index++;
	}
	return (min_index);
}

void	send_b_max_to_a(t_push_swap *push_swap)
{
	set_b(max_b_index(push_swap), push_swap);
	pa(push_swap);
}

uint32_t	max_b_index(t_push_swap *push_swap)
{
	uint32_t	max_index;
	uint32_t	index;
	int32_t		current_value;
	int32_t		max;

	index = 0;
	max = push_swap->stack_b[0];
	max_index = 0;
	while (index < push_swap->a_weight)
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

void	send_b_min_to_a(t_push_swap *push_swap)
{
	set_b(min_b_index(push_swap), push_swap);
	pa(push_swap);
}


void	empty_b_sort(t_push_swap *push_swap)
{
	while (push_swap->b_weight)
	{
		send_b_max_to_a(push_swap);
	}
}

uint8_t	is_in_range(int32_t n, int32_t start, int32_t end)
{
	return (n >= start && n < end);
}

uint8_t	push_first_in_range_to_b(t_push_swap *push_swap, int32_t start, int32_t end)
{
	uint32_t	index;

	index = 0;
	while (index < push_swap->a_weight)
	{
		if (is_in_range(push_swap->stack_a[index], start, end))
		{
			set_a(index, push_swap);
			pb(push_swap);
			return (1);
		}
		index++;
	}
	return (0);
}

void	send_range_to_b(t_push_swap *push_swap, int32_t start, int32_t end)
{
	while (push_first_in_range_to_b(push_swap, start, end));
}