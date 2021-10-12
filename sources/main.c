/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:03:03 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/12 01:23:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_stack_elem	*curr;
	t_stack_elem	*last;

	curr = stack->head;
	last = stack->head->prev;
	while (curr != last)
	{
		if (curr->val > curr->next->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static void	ft_fill_stack_a(t_stack *stack, int argc, char **argv)
{
	if (argc < 2)
	{
		ft_clean_stack(stack);
		exit(0);
	}
	else if (argc == 2)
		ft_parse_str(argv[1], stack);
	else
		ft_read_args(argc, argv, stack);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_cmd_list	*cmds;
	t_env		*env;

	cmds = NULL;
	env = NULL;
	ft_check_args(argc, argv);
	stack_a = ft_init_stack('a');
	ft_fill_stack_a(stack_a, argc, argv);
	ft_check_repeat(stack_a);
	if (ft_is_sorted(stack_a))
		ft_nothing_to_do(stack_a);
	else
	{
		stack_b = ft_init_stack('b');
		cmds = ft_init_cmd_list();
		env = ft_init_env(stack_a, stack_b, cmds);
	}
	if (stack_a->size <= 5)
		ft_mini_sort(env);
	else
		ft_full_sort(env);
	ft_print_cmd_list(cmds);
	ft_clean_env(env);
}
