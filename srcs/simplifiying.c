/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifiying.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:38 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:24:34 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swapp(int32_t *xp, int32_t *yp)
{
	int32_t	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	bubble_sort(int32_t *stack, uint32_t len)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (stack[j] > stack[j + 1])
				swapp(&stack[j], &stack[j + 1]);
			j++;
		}
		i++;
	}
}

void	set_sorted(t_push_swap *push_swap)
{
	uint32_t	index;

	index = 0;
	while (index < push_swap->stacks_len)
	{
		push_swap->sorted_a[index] = push_swap->stack_a[index];
		index++;
	}
	bubble_sort(push_swap->sorted_a, push_swap->stacks_len);
}

static uint32_t	indexof(int32_t *stack, int32_t n, uint32_t size)
{
	uint32_t	index;

	index = 0;
	while (index < size)
	{
		if (stack[index] == n)
			return (index);
		index++;
	}
	return (0);
}

void	simplify_a(t_push_swap *push_swap)
{
	uint32_t	i;

	i = 0;
	while (i < push_swap->stacks_len)
	{
		push_swap->stack_a[i] = indexof(push_swap->sorted_a,
				push_swap->stack_a[i], push_swap->stacks_len);
		i++;
	}
}
