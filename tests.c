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
	write(STDOUT_FILENO, "A :\n\n", sizeof("A :\n\n"));
	while (index < push_swap->stacks_len)
	{
		printf("%d\n", push_swap->stack_a[index]);
		index++;
	}
	printf("\n");
	index = 0;
	write(STDOUT_FILENO, "B :\n\n", sizeof("B :\n\n"));
	while (index < push_swap->stacks_len)
	{
		printf("%d\n", push_swap->stack_b[index]);
		index++;
	}
}
