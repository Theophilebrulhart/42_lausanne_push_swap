/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:51:37 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/07 15:38:13 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void	stack_movement(t_list *list_a, int list_size, int max_bits)
{
	int	i;
	int	*new_list;

	i = 0;
	while (i < max_bits)
	{
		new_list = separation_0_1_bit(list_a, list_size, i);
		get_new_order(list_a, new_list);
		free(new_list);
		i++;
	}
}

void	sort_per_digit(t_list *list_a, int list_size)
{
	int		max_num;
	int		max_bits;

	max_num = list_size - 1;
	max_bits = 0;
	while (max_num >> max_bits != 0)
		max_bits++;
	stack_movement(list_a, list_size, max_bits);
}

void	sort_big_stack(t_list *list_a, int list_size)
{
	small_digit_transform(list_a, list_size);
	sort_per_digit(list_a, list_size);
}
