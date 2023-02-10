/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:58:58 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 11:53:58 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t	strcmp_(char *str0, char *str1)
{
	uint32_t	index;

	index = 0;
	while ((str0[index] && str1[index]))
	{
		if (str0[index] != str1[index])
			return (1);
		index++;
	}
	if (str0[index] || str1[index])
		return (1);
	return (0);
}

uint8_t	is_digit_(char chr)
{
	return (chr >= '0' && chr <= '9');
}

uint8_t	is_int(char *nbr)
{
	uint8_t	digits_number;
	uint8_t	chr_number;

	if (nbr[0] == '+' || nbr[0] == '-')
		nbr++;
	digits_number = 0;
	chr_number = 0;
	while (nbr[chr_number])
	{
		if (is_digit_(nbr[chr_number]))
			digits_number++;
		chr_number++;
	}
	return (chr_number == digits_number && digits_number);
}

uint8_t	is_unique(char **args, uint32_t index, uint32_t len) //ATTENTION, +5 = 5 ?
{
	uint32_t	test_index;

	test_index = 0;
	while (test_index < len)
	{
		if (strcmp_(args[index], args[test_index])
			|| test_index == index)
		test_index++;
		else
			return (0);
	}
	return (1);
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
