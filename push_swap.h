/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:35:31 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/10 13:47:58 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

typedef	struct s_push_swap
{
	uint32_t	stacks_len;
	int32_t		*stack_a;
	int32_t		*stack_b;	
}	t_push_swap;

t_push_swap	*push_swap(uint32_t stacks_len);
uint32_t	occurences(char *str, char **cont, uint32_t len);
int32_t		atoi_(char *str);
uint8_t		entry_is_valid(uint32_t ac, char **av);
uint8_t		is_unique(char **args, uint32_t index, uint32_t len);
uint8_t		is_int(char *nbr);
uint8_t		is_digit_(char chr);
void		init_push_swap(t_push_swap *push_swap, char **nbrs, uint32_t size);
void		add_number(t_push_swap *push_swap, int32_t number);
void		delete_push_swap(t_push_swap *push_swap);
void		invalid_entry_error(void);
void		allocation_error(void);
void		display_stacks(t_push_swap *push_swap);
int			strcmp_(const char *s1, const char *s2);

#endif