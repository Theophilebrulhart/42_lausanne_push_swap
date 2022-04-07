/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_digit_transform.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:11:01 by theophilebr       #+#    #+#             */
/*   Updated: 2022/04/07 15:38:48 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void	sort_copy(int *copy, int list_size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (list_size - 1))
	{
		if (copy[i] > copy[i + 1])
		{
			tmp = copy[i];
			copy[i] = copy[i + 1];
			copy[i + 1] = tmp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

void	tranformation(t_list *list_a, int list_size, int *copy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < list_size)
	{
		j = 0;
		while (*(int *)list_a->content != copy[j])
			j++;
		*(int *)list_a->content = j;
		list_a = list_a->next;
		i++;
	}
}

void	small_digit_transform(t_list *list_a, int list_size)
{
	int		*copy;
	int		i;
	t_list	*list_tmp;

	i = 0;
	list_tmp = list_a;
	copy = malloc(list_size * sizeof(*copy));
	if (!copy)
		exit(1);
	while (i < list_size)
	{
		copy[i] = *(int *)list_a->content;
		i++;
		list_a = list_a->next;
	}
	sort_copy(copy, list_size);
	i = 0;
	list_a = list_tmp;
	tranformation(list_a, list_size, copy);
	free(copy);
}
