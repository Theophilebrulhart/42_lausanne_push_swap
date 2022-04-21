/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:17:41 by theophilebr       #+#    #+#             */
/*   Updated: 2022/04/21 16:20:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void	sort_3(int *stk_a, int list_size)
{
	if (stk_a[0] > stk_a[1] && stk_a[1] < stk_a[2] && stk_a[0] < stk_a[2])
		sa_swap(stk_a);
	if (stk_a[0] > stk_a[1] && stk_a[1] > stk_a[2])
	{
		sa_swap(stk_a);
		rra_swap(stk_a, list_size - 1);
	}
	if (stk_a[0] < stk_a[1] && stk_a[1] > stk_a[2] && stk_a[0] < stk_a[2])
	{
		sa_swap(stk_a);
		ra_swap(stk_a, 3);
	}
	if (stk_a[0] > stk_a[1] && stk_a[1] < stk_a[2] && stk_a[0] > stk_a[2])
		ra_swap(stk_a, 3);
	if (stk_a[0] < stk_a[1] && stk_a[1] > stk_a[2] && stk_a[0] > stk_a[2])
		rra_swap(stk_a, list_size - 1);
}

void	sort_4(int *stack_a, int list_size)
{
	int	nbr_save;

	nbr_save = stack_a[0];
	pb_swap(stack_a, list_size);
	sort_3(stack_a, list_size);
	pa_swap(stack_a, nbr_save, list_size);
	if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		sa_swap(stack_a);
	if (stack_a[0] > stack_a[2] && stack_a[0] < stack_a[3])
	{
		sa_swap(stack_a);
		nbr_save = stack_a[0];
		pb_swap(stack_a, list_size);
		sa_swap(stack_a);
		pa_swap(stack_a, nbr_save, list_size);
	}
	if (stack_a[0] > stack_a[3])
		ra_swap(stack_a, list_size);
}

void	sort_5_put_middle(int *stack_a, int list_size)
{
	int	nbr_save;
	int	nbr_save_2;

	nbr_save = stack_a[1];
	nbr_save_2 = stack_a[2];
	sa_swap(stack_a);
	pb_swap(stack_a, list_size);
	sa_swap(stack_a);
	pa_swap(stack_a, nbr_save, list_size);
}

void	sort_5(int *stack_a, int list_size)
{
	int	nbr_save;
	int	nbr_save_2;

	nbr_save = stack_a[0];
	nbr_save_2 = stack_a[1];
	if ((stack_a[0] == 2 && stack_a[1] == 3)
		|| (stack_a[0] == 3 && stack_a[1] == 2))
		special_sort_2_3(stack_a, list_size);
	pb_swap(stack_a, list_size);
	sort_4(stack_a, list_size - 1);
	pa_swap(stack_a, nbr_save, list_size);
	if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		sa_swap(stack_a);
	if (stack_a[0] > stack_a[2] && stack_a[0] < stack_a[3])
		sort_5_put_middle(stack_a, list_size);
	if (stack_a[0] > stack_a[3] && stack_a[0] < stack_a[4])
	{
		rra_swap(stack_a, list_size - 1);
		sa_swap(stack_a);
		ra_swap(stack_a, list_size);
		ra_swap(stack_a, list_size);
	}
	if (stack_a[0] > stack_a[4])
		ra_swap(stack_a, list_size);
}

void	sort_small_stack(t_list *list_a, int list_size)
{
	int	*stack_a;
	int	i;

	if (list_size == 2)
		ft_putendl_fd("sa", 1);
	small_digit_transform(list_a, list_size);
	stack_a = malloc(list_size * sizeof(*stack_a));
	i = 0;
	while (i < list_size)
	{
		stack_a[i] = *(int *)list_a->content;
		i++;
		if (list_a->next != NULL)
			list_a = list_a->next;
	}
	if (list_size == 3)
		sort_3(stack_a, list_size);
	if (list_size == 4)
		sort_4(stack_a, list_size);
	if (list_size == 5)
		sort_5(stack_a, list_size);
	i = 0;
	free(stack_a);
}
