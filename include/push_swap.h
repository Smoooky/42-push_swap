/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:06:21 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/12 01:24:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../sources/printf/includes/ft_printf.h"

typedef struct s_stack_elem
{
	long long			val;
	long long			score;
	struct s_stack_elem	*prev;
	struct s_stack_elem	*next;
}						t_stack_elem;

typedef struct s_stack
{
	t_stack_elem	*head;
	char			name;
	long long 		size;
}				t_stack;

typedef struct s_cmd
{
	char			*name;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_cmd_list
{
	size_t	size;
	t_cmd	*head;
}			t_cmd_list;

typedef struct s_env
{
	t_stack		*a;
	t_stack		*b;
	t_cmd_list	*cmds;
}				t_env;

long long		ft_atol(const char *str);
void			ft_parse_str(char *str, t_stack *stack);
void			ft_read_args(size_t argc, char **argv, t_stack *stack);
void			ft_check_args(long long argc, char **argv);
t_stack			*ft_init_stack(char name);
t_stack_elem	*ft_create_elem(int val);
void			ft_push(t_stack *stack, t_stack_elem *new);
t_stack_elem	*ft_pop(t_stack *stack);
void			ft_check_repeat(t_stack *stack);
void			ft_terminate(char *str);
long long		ft_find_mid(long long *arr, size_t size);
t_env			*ft_init_env(t_stack *a, t_stack *b, t_cmd_list *cmds);
long long		ft_abs(long long a);
void			ft_rx(t_stack *stack, t_cmd_list *list);
void			ft_rr(t_stack *a, t_stack *b, t_cmd_list *list);
void			ft_rrx(t_stack *stack, t_cmd_list *list);
void			ft_rrr(t_stack *a, t_stack *b, t_cmd_list *list);
void			ft_px(t_stack *to, t_stack *from, t_cmd_list *list);
void			ft_sx(t_stack *stack, t_cmd_list *list);
void			ft_ss(t_stack *a, t_stack *b, t_cmd_list *list);
t_cmd_list		*ft_init_cmd_list(void);
t_cmd			*ft_create_cmd(char *name);
void			ft_add_cmd(t_cmd_list *list, t_cmd *new);
void			ft_print_cmd_list(t_cmd_list *list);
void			ft_calc_score(t_env *env, t_stack_elem *curr, long long count);
t_stack_elem	*ft_find_min_score(t_stack *b, long long *pos);
void			ft_push_min_score(t_env *env, t_stack_elem *min_score,
					long long pos);
long long		ft_rotations_to_elem(t_stack_elem *head, long long size,
					long long val);
void			ft_do_rotations(t_env *env, long long a_rotations,
					long long b_rotations);
int				ft_is_sorted(t_stack *stack);
void			ft_push_to_b(t_env *env, long long min, long long mid,
					long long max);
long long		ft_find_values(t_stack *stack, long long *min, long long *max);
void			ft_full_sort(t_env *env);
void			ft_mini_sort(t_env *env);
void			ft_clean_env(t_env *env);
void			ft_clean_stack(t_stack *stack);
void			ft_error(t_stack *stack);
void			ft_nothing_to_do(t_stack *stack);

#endif
