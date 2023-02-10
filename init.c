/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:43:48 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 10:49:55 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

int32_t	atoi_(char *str)
{
	long	i;
	long	nbr;
	int		sign;

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

void	init_push_swap(t_push_swap *push_swap, char **nbrs, uint32_t size)
{
	uint32_t	current_index;

	current_index = 0;
	while (current_index < size)
	{
		push_swap->stack_a[current_index] = atoi_(nbrs[current_index]);
		current_index++;
	}
}
