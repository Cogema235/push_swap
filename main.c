/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:38 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:15:59 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	*push_swap_;

	ac--;
	av++;
	if (ac)
	{
		if (!entry_is_valid(ac, av))
			invalid_entry_error();
		push_swap_ = push_swap(ac);
		if (!push_swap_)
			allocation_error();
		init_push_swap(push_swap_, av, ac);
		display_stacks(push_swap_);
		delete_push_swap(push_swap_);
	}
	else
		invalid_entry_error();
	return (0);
}
