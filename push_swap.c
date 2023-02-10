/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:46:34 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 09:52:58 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_push_swap *push_swap, int32_t number)
{
	static uint32_t	last_added_index = 0;

	if (last_added_index < push_swap->stacks_len)
		push_swap->stack_b[last_added_index++] = number;
}

t_push_swap	*push_swap(uint32_t stacks_len)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(push_swap));
	if (!push_swap)
		return (NULL);
	push_swap->stacks_len = stacks_len;
	push_swap->stack_a = malloc(sizeof(int32_t) * stacks_len * 2);
	if (!push_swap->stack_a)
		return (NULL);
	push_swap->stack_b = &(push_swap->stack_a[push_swap->stacks_len]);
	return (push_swap);
}

void	delete_push_swap(t_push_swap *push_swap)
{
	free(push_swap->stack_a);
	free(push_swap);
}
