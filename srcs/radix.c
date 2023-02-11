/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:38 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:24:34 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static uint8_t	max_bits(int32_t n)
{
	uint8_t	nb;

	nb = 0;
	while (n >> nb)
		nb++;
	return (nb);
}

void	radix_sort(t_push_swap *push_swap)
{
	uint32_t	stack_index;
	uint8_t		max_bit_number;
	uint8_t		count;

	max_bit_number = max_bits(push_swap->sorted_a[push_swap->stacks_len - 1]);
	count = 0;
	while (count < max_bit_number)
	{
		stack_index = 0;
		while (stack_index < push_swap->stacks_len)
		{
			if (((push_swap->stack_a[0] >> count) & 1) == 1)
				ra(push_swap);
			else
				pb(push_swap);
			stack_index++;
		}
		while (push_swap->b_weight)
			pa(push_swap);
		count++;
	}
}
