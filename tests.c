/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:01:25 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 13:51:26 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stacks(t_push_swap *push_swap)
{
	uint32_t	index;

	index = 0;
	printf("A : -");
	while (index < push_swap->a_weight)
	{
		printf("%d ", push_swap->stack_a[index]);
		index++;
	}
	index = 0;
	printf("\b- B : -");
	while (index < push_swap->b_weight)
	{
		printf("%d ", push_swap->stack_b[index]);
		index++;
	}
	printf("\b-\n");
}
