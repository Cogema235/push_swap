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

typedef struct s_dynastring
{
	uint32_t	allocated_size;
	uint32_t	filled_size;
	char		*str;
}	t_dynastring;

typedef struct s_push_swap
{
	t_dynastring	*instructions;
	uint32_t		stacks_len;
	uint32_t		a_weight;
	uint32_t		b_weight;
	int32_t			*stack_a;
	int32_t			*stack_b;
	int32_t			*sorted_a;

}	t_push_swap;

t_dynastring	*dynappend_str(t_dynastring *dynstr, char *str);
t_dynastring	*dynastring(uint32_t size);
t_dynastring	*dappend_chr(t_dynastring *dynstr, char chr);
t_dynastring	*print_str(t_dynastring *dynstr);
t_push_swap		*push_swap(uint32_t stacks_len);
uint32_t		occurences(char *str, char **cont, uint32_t len);
uint32_t		uabs32(int32_t n);
uint32_t		cost_of(uint32_t index, t_push_swap *push_swap);
int64_t			atoi64(char *str);
int32_t			atoi32(char *str);
int32_t			min32(int32_t a, int32_t b);
uint8_t			entry_is_valid(uint32_t ac, char **av);
uint8_t			is_unique(char **args, uint32_t index, uint32_t len);
uint8_t			is_int(char *nbr);
uint8_t			is_digit_(char chr);
uint8_t			is_int32(char *str);
uint8_t			is_ws(char c);
void			init_push_swap(t_push_swap *push_swap,
					char **nbrs, uint32_t size);
void			add_number(t_push_swap *push_swap, int32_t number);
void			delete_push_swap(t_push_swap *push_swap);
void			invalid_entry_error(void);
void			allocation_error(void);
void			display_stacks(t_push_swap *push_swap);
void			sa(t_push_swap *push_swap);
void			sb(t_push_swap *push_swap);
void			pa(t_push_swap *push_swap);
void			pb(t_push_swap *push_swap);
void			ra(t_push_swap *push_swap);
void			rb(t_push_swap *push_swap);
void			rr(t_push_swap *push_swap);
void			rra(t_push_swap *push_swap);
void			rrb(t_push_swap *push_swap);
void			rrr(t_push_swap *push_swap);
void			shift_down(int32_t *stack, uint32_t len);
void			shift_up(int32_t *stack, uint32_t len);
void			simplify_a(t_push_swap *push_swap);
void			set_sorted(t_push_swap *push_swap);
void			delete_dynastring(t_dynastring *dynstr);
void			radix_sort(t_push_swap *push_swap);
void			low_cost_sort(t_push_swap *push_swap);

#endif