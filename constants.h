/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:41:13 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/03/29 19:48:02 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H
# include "stdio.h"
# include "libft/libft.h"
# include <stdlib.h>

t_list	*list_parsing(char **argv);
void	error_exit(char *s, int fd);
void	integer_check(char *str);
void	duplicates_check(t_list *list);
t_list	*parsing_one_argument(char **argv);
void	push_swap(t_list *list_a);
int		already_sorted(t_list *list_a);
void	sort_big_stack(t_list *list_a, int list_size);
void	stack_movement(t_list *list_a, int list_size, int max_bits);
void	small_digit_transform(t_list *list_a, int list_size);
void	sort_small_stack(t_list *list_a, int list_size);
void	sa_swap(int *stk_a);
void	rra_swap(int *stk_a, int i);
void	ra_swap(int *stk_a, int list_size);
void	pa_swap(int *stack_a, int nbr_save, int list_size);
void	pb_swap(int *stack_a, int list_size);
int		*ft_strjoin_int(int *s1, int *s2, int a, int b);
int		*separation_0_1_bit(t_list *list_a, int list_size, int i);
void	get_new_order(t_list *list_a, int *new_list);
void	stack_movement(t_list *list_a, int list_size, int max_bits);
void	special_sort_2_3(int *stack_a, int list_size);

#endif