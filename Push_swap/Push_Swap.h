/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_Swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 14:35:27 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/10 16:09:20 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./src/libft/libft.h"

typedef struct s_alist{
	int				content;
	int				index;
	struct s_alist	*next;
	struct s_alist	*prev;
}				t_alist;

typedef struct s_top_vals{
	struct s_alist	*top_a;
	struct s_alist	*top_b;
	int				list_size;
}				t_top_vals;

// Found in main.c file
int			input_checker(t_top_vals *t_vals);
int			check_for_numbers(int argc, char **argv);
void		init_top(t_alist *stack_a, t_alist *stack_b, t_top_vals **top);

// Found in Rules.c file
int			swap(t_top_vals *top, char stack);
int			swap_both(t_top_vals *top);
int			push_a(t_top_vals *top);
int			push_b(t_top_vals *top);
void		rotate(t_top_vals *top, char stack);

//Found in more_rules_.c file
void		rotate_both(t_top_vals *top);
int			reverse_rotate(t_top_vals *top, char stack);
int			reverse_rotate_both(t_top_vals *top);
void		rotate_a(t_top_vals *top);
void		rotate_b(t_top_vals *top);

//Found in more_rules_2.c file
void		swap_a(t_top_vals *top);
void		swap_b(t_top_vals *top);
void		reverse_rotate_a(t_top_vals *top);
void		reverse_rotate_b(t_top_vals *top);
void		push(t_top_vals *top, char stack);

//Found in Push_Swap.c file
void		ray_dicks_sort(t_top_vals *top);
void		ray_dicks_core(t_top_vals *top, int i);
void		sorting_algo(int argc, t_top_vals *top);

//Found in utils.c
t_alist		*ps_lstnew(int content);
void		ps_lstadd_back(t_alist *lst, t_alist *new);
t_alist		*ps_lstadd_front(t_alist *lst, t_alist *new);
int			count_nodes(t_alist *a_list);
t_alist		*init_stack_a(int argc, char **values);

//Found in utils_2.c
t_alist		*init_stack_b(void);
int			ps_atoi(const char *str);

//Found in utils_3.c
int			check_sorted(t_alist *lst_a);
int			check_duplicates(t_alist *lst);
int			check_rest_of_list(int i, t_alist *lst);
int			check_if_smallest(t_alist *stack_a, int ref);
int			return_smallest_in_stack(t_top_vals *top, char sign);

//Found in utils_4.c
int			return_next_smallest(t_top_vals *top, char sign, int prev);
int			return_largest_in_stack(t_top_vals *top, char sign);
void		index_increasing(t_top_vals *top);
t_alist		*find_node(t_top_vals *top, char stack, int val);
t_top_vals	*initializer(int argc, char **argv);

//Found in utils_5.c
t_alist		*get_stack(t_top_vals *top, char stack);
void		set_stack(t_top_vals *top, t_alist *lst, char stack);
int			find_index(t_top_vals *top, int index);
void		error_exit(void);

//Found in small_sort.c
void		small_sort(t_top_vals *top, int vals);
void		sort_3(t_alist *tmp, t_top_vals *top);
void		sort_4(t_top_vals *top);
void		sort_5(t_top_vals *top);

#endif