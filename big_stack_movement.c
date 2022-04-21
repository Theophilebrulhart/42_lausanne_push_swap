/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:37:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/21 16:33:53 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void	movement(t_list *list_a, char *move, int *stack, int *index)
{
	ft_putendl_fd(move, 1);
	stack[*index] = *(int *)list_a->content;
	*index = *index + 1;
}

int	*separation_0_1_bit(t_list *list_a, int list_size, int i)
{
	int	j;
	int	*stack_a;
	int	*stack_b;
	int	a;
	int	b;

	a = 0;
	b = 0;
	j = 0;
	stack_a = malloc((list_size + 1) * sizeof(*stack_a));
	if (!stack_a)
		exit(1);
	stack_b = malloc((list_size + 1) * sizeof(*stack_b));
	if (!stack_a)
		exit(1);
	while (j < list_size)
	{
		if (((*(int *)list_a->content >> i) & 1) == 0)
			movement(list_a, "pb", stack_b, &b);
		else
			movement(list_a, "ra", stack_a, &a);
		list_a = list_a->next;
		j++;
	}
	return (ft_strjoin_int(stack_b, stack_a, a, b));
}

int	*ft_strjoin_int(int *s1, int *s2, int a, int b)
{
	int	*str;
	int	i;
	int	j;

	str = malloc((a + b) * sizeof(*str) + 1);
	str[a + b + 1] = '\0';
	if (str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < b)
	{
		ft_putendl_fd("pa", 1);
		str[i++] = s1[j++];
	}
	j = 0;
	while (j < a)
	{
		str[i++] = s2[j++];
	}
	free(s1);
	free(s2);
	return (str);
}

void	get_new_order(t_list *list_a, int *new_list)
{
	int	i;

	i = 0;
	while (list_a->next != NULL)
	{
		*(int *)list_a->content = new_list[i];
		i++;
		list_a = list_a->next;
	}
	*(int *)list_a->content = new_list[i];
}
