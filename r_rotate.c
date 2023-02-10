/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:54:08 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 10:58:57 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(int32_t *stack, uint32_t len)
{
	int32_t	tmp;

	tmp = stack[len - 1];
	shift_down(stack, len);
	stack[0] = tmp;
}

void	rra(t_push_swap *push_swap)
{
	r_rotate(push_swap->stack_a, push_swap->stacks_len);
}

void	rrb(t_push_swap *push_swap)
{
	r_rotate(push_swap->stack_b, push_swap->stacks_len);
}

void	rrr(t_push_swap *push_swap)
{
	rra(push_swap);
	rrb(push_swap);
}
