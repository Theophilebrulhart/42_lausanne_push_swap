/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:07:45 by theophilebr       #+#    #+#             */
/*   Updated: 2022/04/07 15:38:35 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void	sa_swap(int *stk_a)
{
	int	nbr_tmp;

	nbr_tmp = 0;
	nbr_tmp = stk_a[0];
	stk_a[0] = stk_a[1];
	stk_a[1] = nbr_tmp;
	ft_putendl_fd("sa", 1);
}

void	rra_swap(int *stk_a, int i)
{
	int	nbr_tmp;

	nbr_tmp = stk_a[i];
	while (i > 0)
	{
		stk_a[i] = stk_a[i - 1];
		i--;
	}
	stk_a[0] = nbr_tmp;
	ft_putendl_fd("rra", 1);
}

void	ra_swap(int *stk_a, int list_size)
{
	int	nbr_tmp;
	int	i;

	i = 0;
	nbr_tmp = stk_a[0];
	while (i < list_size - 1)
	{
		stk_a[i] = stk_a[i + 1];
		i++;
	}
	stk_a[i] = nbr_tmp;
	ft_putendl_fd("ra", 1);
}

void	pa_swap(int *stack_a, int nbr_save, int list_size)
{
	while (list_size)
	{
		stack_a[list_size] = stack_a[list_size - 1];
		list_size--;
	}
	stack_a[0] = nbr_save;
	ft_putendl_fd("pa", 1);
}

void	pb_swap(int *stack_a, int list_size)
{
	int	i;

	i = 0;
	while (i < list_size - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	ft_putendl_fd("pb", 1);
	i = 0;
}
