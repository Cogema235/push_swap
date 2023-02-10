/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:54:08 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 10:58:57 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int32_t *stack)
{
	int32_t	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	sa(t_push_swap *push_swap)
{
	swap(push_swap->stack_a);
	dynappend_str(push_swap->instructions, "sa\n");
}

void	sb(t_push_swap *push_swap)
{
	swap(push_swap->stack_b);
	dynappend_str(push_swap->instructions, "sb\n");
}

void	ss(t_push_swap *push_swap)
{
	swap(push_swap->stack_a);
	swap(push_swap->stack_b);
	dynappend_str(push_swap->instructions, "ss\n");
}
