/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:52:30 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/11 21:31:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(t_stack *stack)
{
	if (stack)
		ft_clean_stack(stack);
	ft_terminate("Error");
	exit(1);
}

void	ft_nothing_to_do(t_stack *stack)
{
	if (stack)
		ft_clean_stack(stack);
	exit(0);
}

void	ft_clean_stack(t_stack *stack)
{
	t_stack_elem	*curr;

	if (stack->head)
	{
		curr = stack->head->next;
		while (curr != stack->head)
		{
			free(curr);
			curr = curr->next;
		}
		free(curr);
		stack->head = NULL;
	}
	free(stack);
}

static void	ft_clean_cmds(t_cmd_list *cmds)
{
	t_cmd	*curr;

	while (cmds->head != NULL)
	{
		curr = cmds->head;
		cmds->head = cmds->head->next;
		free(curr->name);
		free(curr);
	}
	free(cmds);
}

void	ft_clean_env(t_env *env)
{
	ft_clean_stack(env->a);
	ft_clean_stack(env->b);
	ft_clean_cmds(env->cmds);
	free(env);
	exit(0);
}
