/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:38 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:24:34 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplify_stack(int32_t *stack, uint32_t len)
{
	uint32_t	count;
	int32_t		offset;
	int32_t		*current_min;

	count = 0;
	offset = *(minint32(stack, INT32_MIN, len));
	while (count < len)
	{
		current_min = minint32(stack, offset, len);
		offset = *current_min;
		*current_min = count;
		count++;
		if (offset != INT32_MAX)
			offset++;
		else
			return ;
	}
}

void	simplify_a(t_push_swap *push_swap)
{
	simplify_stack(push_swap->stack_a, push_swap->stacks_len);
}
