/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_2_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:46:47 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/03/29 19:50:20 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void	special_sort_2_3(int *stack_a, int list_size)
{
	int	rra_count;

	rra_count = 0;
	rra_swap(stack_a, list_size - 1);
	rra_count++;
	rra_swap(stack_a, list_size - 1);
	rra_count++;
	if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2])
	{
		rra_swap(stack_a, list_size - 1);
		rra_count++;
	}
	if (stack_a[0] > stack_a[1])
	{
		sa_swap(stack_a);
		if (rra_count != 3)
			rra_swap(stack_a, list_size - 1);
		if (stack_a[0] > stack_a[1])
			sa_swap(stack_a);
	}
}
