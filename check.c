/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:58:58 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 14:15:26 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint32_t	occurences(char *str, char **cont, uint32_t len)
{
	uint32_t	occ;
	uint32_t	index;

	occ = 0;
	index = 0;
	while (index < len)
	{
		if (!strcmp_(str, cont[index]))
			occ++;
		index++;
	}
	return (occ);
}

/* ATTENTION, +5 = 5 ? */
uint8_t	is_unique(char **args, uint32_t index, uint32_t len)
{
	return (occurences(args[index], args, len) == 1);
}

uint8_t	entry_is_valid(uint32_t ac, char **av)
{
	uint32_t	current_index;

	current_index = 0;
	while (current_index < ac)
	{
		if (!is_int(av[current_index]) || !is_unique(av, current_index, ac))
			return (0);
		current_index++;
	}
	return (1);
}
