/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:54:23 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/03/29 16:27:11 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void	integer_check(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && str[1])
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_exit("Error\n", 2);
		i++;
	}
	if (ft_atoi(str) < -2147483648 || ft_atoi(str) > 2147483647)
		error_exit("Error\n", 2);
}

void	duplicates_check(t_list *list)
{
	int		nbr;
	t_list	*tmp;

	while (list->next != NULL)
	{
		nbr = *(int *)list->content;
		list = list->next;
		tmp = list;
		while (nbr != *(int *)list->content && list->next != NULL)
			list = list->next;
		if (nbr == *(int *)list->content)
			error_exit("Error\n", 1);
		list = tmp;
	}
}

int	*ft_intdup(int nbr)
{
	int	*new_nbr;

	new_nbr = malloc(sizeof(*new_nbr));
	if (!new_nbr)
		exit (1);
	*new_nbr = nbr;
	return (new_nbr);
}

t_list	*list_parsing(char **argv)
{
	int		i;
	t_list	*list;
	int		*n;

	i = 0;
	list = NULL;
	while (argv[++i])
	{
		integer_check(argv[i]);
		n = ft_intdup(ft_atoi(argv[i]));
		ft_lstadd_back(&list, ft_lstnew((void *)n));
	}
	duplicates_check(list);
	return (list);
}

t_list	*parsing_one_argument(char **argv)
{
	int		i;
	t_list	*list;
	int		*n;
	char	**tab;

	tab = ft_split(argv[1], ' ');
	i = -1;
	list = NULL;
	while (tab[++i])
	{
		integer_check(tab[i]);
		n = ft_intdup(ft_atoi(tab[i]));
		ft_lstadd_back(&list, ft_lstnew((void *)n));
	}
	if (i == 1)
		return (list);
	duplicates_check(list);
	return (list);
}
