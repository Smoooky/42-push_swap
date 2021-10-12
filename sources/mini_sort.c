/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:46:45 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/12 00:00:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_is_max(t_stack_elem *head, long long val)
{
	t_stack_elem	*curr;

	if (head->val > val)
		return (0);
	curr = head->next;
	while (curr != head)
	{
		if (curr->val > val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static void	ft_b_to_a(t_env *env, long long amin)
{
	long long	rotations;

	while (env->b->size != 0)
	{
		if (env->b->head->val < env->a->head->val)
			ft_px(env->a, env->b, env->cmds);
		else if (ft_is_max(env->a->head, env->b->head->val)
			&& env->a->head->val == amin)
			ft_px(env->a, env->b, env->cmds);
		ft_rx(env->a, env->cmds);
	}
	if (!ft_is_sorted(env->a))
	{
		rotations = ft_rotations_to_elem(env->a->head, env->a->size, amin);
		ft_do_rotations(env, rotations, 0);
	}
}

static void	ft_sort_trio(t_stack *stack, t_cmd_list *cmds)
{
	long long	min;
	long long	max;
	long long	mid;

	mid = ft_find_values(stack, &min, &max);
	if (stack->head->val == max)
		ft_rx(stack, cmds);
	if (stack->head->val == mid)
	{
		if (stack->head->next->val == max)
			ft_rrx(stack, cmds);
		else
			ft_sx(stack, cmds);
		return ;
	}
	if (stack->head->next->val == max)
	{
		ft_rrx(stack, cmds);
		ft_sx(stack, cmds);
	}
}

void	ft_mini_sort(t_env *env)
{
	long long	min;
	long long	max;

	if (env->a->size == 2)
	{
		ft_sx(env->a, env->cmds);
		return ;
	}
	ft_find_values(env->a, &min, &max);
	while (env->a->size > 3)
		ft_px(env->b, env->a, env->cmds);
	ft_sort_trio(env->a, env->cmds);
	if (env->b->size == 2 && !ft_is_sorted(env->b))
		ft_sx(env->b, env->cmds);
	else if (env->b->size == 3)
		ft_sort_trio(env->b, env->cmds);
	ft_b_to_a(env, min);
}
