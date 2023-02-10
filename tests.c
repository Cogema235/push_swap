/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:01:25 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 11:30:17 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stacks(t_push_swap *push_swap)
{
	uint32_t	index;

	write(STDOUT_FILENO, "A :\n", sizeof("A :\n"));
	index = 0;
	while (index < push_swap->stacks_len)
	{
		write(STDOUT_FILENO, "test\n", 5);
	}
	write(STDOUT_FILENO, "B :\n", sizeof("B :\n"));
	index = 0;
	while (index < push_swap->stacks_len)
	{
		write(STDOUT_FILENO, "test\n", 5);
	}
}
