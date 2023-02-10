/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:43:48 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:04:39 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_swap(t_push_swap *push_swap, char **nbrs, uint32_t size)
{
	uint32_t	current_index;

	current_index = 0;
	while (current_index < size)
	{
		push_swap->stack_a[current_index] = atoi32(nbrs[current_index]);
		current_index++;
		push_swap->a_weight++;
	}
}
