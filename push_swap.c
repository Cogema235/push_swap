/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:46:34 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:29:57 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_push_swap *push_swap, int32_t number)
{
	static uint32_t	last_added_index = 0;

	if (last_added_index < push_swap->stacks_len)
	{
		push_swap->stack_a[last_added_index] = number;
		last_added_index++;
	}
}

t_push_swap	*push_swap(uint32_t stacks_len)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (NULL);
	push_swap->stacks_len = stacks_len;
	push_swap->stack_a = calloc(stacks_len, sizeof(int32_t));
	push_swap->stack_b = calloc(stacks_len, sizeof(int32_t));
	push_swap->sorted_a = malloc(sizeof(int32_t) * stacks_len);
	push_swap->instructions = dynastring(10);
	if (!(push_swap->stack_a && push_swap->stack_b && push_swap->sorted_a
			&& push_swap->instructions))
		return (NULL);
	push_swap->a_weight = 0;
	push_swap->b_weight = 0;
	return (push_swap);
}

void	delete_push_swap(t_push_swap *push_swap)
{
	delete_dynastring(push_swap->instructions);
	free(push_swap->stack_a);
	free(push_swap->stack_b);
	free(push_swap->sorted_a);
	free(push_swap);
}
