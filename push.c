/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:54:08 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 10:58:57 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_down(int32_t *stack, uint32_t len)
{
	uint32_t	index;

	index = len - 1;
	while (index > 0)
	{
		stack[index] = stack[index - 1];
		index--;
	}
}

void	shift_up(int32_t *stack, uint32_t len)
{
	uint32_t	index;

	index = 0;
	while (index < len - 1)
	{
		stack[index] = stack[index + 1];
		index++;
	}
}

void	pa(t_push_swap *push_swap)
{
	if (push_swap->b_weight)
	{
		if (push_swap->a_weight)
			shift_down(push_swap->stack_a, push_swap->stacks_len);
		push_swap->stack_a[0] = push_swap->stack_b[0];
		shift_up(push_swap->stack_b, push_swap->stacks_len);
	}
	push_swap->a_weight++;
	push_swap->b_weight--;
	dynappend_str(push_swap->instructions, "pa\n");
}

void	pb(t_push_swap *push_swap)
{
	if (push_swap->a_weight)
	{
		if (push_swap->b_weight)
			shift_down(push_swap->stack_b, push_swap->stacks_len);
		push_swap->stack_b[0] = push_swap->stack_a[0];
		shift_up(push_swap->stack_a, push_swap->stacks_len);
	}
	push_swap->b_weight++;
	push_swap->a_weight--;
	dynappend_str(push_swap->instructions, "pb\n");
}
