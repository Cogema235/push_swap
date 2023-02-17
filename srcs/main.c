/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:38 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:24:34 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	*push_swap_;

	if (ac > 1)
	{
		if (!entry_is_valid(--ac, ++av))
			invalid_entry_error();
		push_swap_ = push_swap(ac);
		if (!push_swap_)
			allocation_error();
		init_push_swap(push_swap_, av, ac);
		if (!is_sorted(push_swap_->stack_a, push_swap_->stacks_len))
		{
			if (push_swap_->stacks_len == 2)
				sort_2(push_swap_);
			else if (push_swap_->stacks_len == 3)
				sort_3(push_swap_);
			else if (push_swap_->stacks_len < 30)
				selection_sort(push_swap_);
			else
				reverse_pyramid(push_swap_);
			print_str(push_swap_->instructions);
		}
		delete_push_swap(push_swap_);
	}
	return (0);
}
