/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:42:57 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 13:49:00 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

uint8_t	is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

int32_t	atoi32(char *str)
{
	int64_t	i;
	int64_t	nbr;
	uint8_t	sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] && is_ws(str[i]))
		i++;
	if (str[i] && str[i] == '-')
	{
		sign = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && is_digit_(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (sign == 1)
		return (-nbr);
	return (nbr);
}
