/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:38:53 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/21 17:05:41 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void	error_exit(char *s, int fd)
{
	if (fd)
		ft_putstr_fd(s, 2);
	exit (fd);
}

int	already_sorted(t_list *list_a)
{
	int	nbr;

	if (list_a->next == NULL)
		exit(EXIT_SUCCESS);
	while (list_a->next != NULL)
	{
		nbr = *(int *)list_a->content;
		list_a = list_a->next;
		if (nbr > *(int *)list_a->content)
			return (0);
	}
	exit(EXIT_SUCCESS);
}

int	stack_size(t_list *list_a)
{
	int	i;

	i = 0;
	while (list_a->next != NULL)
	{
		i++;
		list_a = list_a->next;
	}
	i++;
	return (i);
}

void	push_swap(t_list *list_a)
{
	int	list_size;

	already_sorted(list_a);
	list_size = stack_size(list_a);
	if (list_size < 6)
	{
		sort_small_stack(list_a, list_size);
	}
	else
	{
		sort_big_stack(list_a, list_size);
	}	
}

int	main(int argc, char **argv)
{
	t_list	*list_a;

	if (argc < 2)
		error_exit("Error\n", 2);
	if (argc == 2)
		list_a = parsing_one_argument(argv);
	else
		list_a = list_parsing(argv);
	push_swap(list_a);
	return (0);
}
