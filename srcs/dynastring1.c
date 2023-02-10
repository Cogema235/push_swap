/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynastring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:52:46 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/08 19:03:35 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dynastring	*dynappend_str(t_dynastring *dynstr, char *str)
{
	uint32_t	i;

	i = 0;
	while (str[i])
	{
		dappend_chr(dynstr, str[i]);
		i++;
	}
	return (dynstr);
}
