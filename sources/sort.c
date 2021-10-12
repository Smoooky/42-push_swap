/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:48:34 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/12 01:28:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long long	ft_find_values(t_stack *stack, long long *min, long long *max)
{
	t_stack_elem	*tmp;
	long long		i;
	long long		*arr;
	long long		res;

	arr = (long long *)malloc(sizeof(long long) * stack->size);
	if (!arr)
		ft_terminate("Memory allocation error");
	i = 0;
	tmp = stack->head;
	*min = stack->head->val;
	*max = stack->head->val;
	while (i < stack->size)
	{
		if (tmp->val < *min)
			*min = tmp->val;
		if (tmp->val > *max)
			*max = tmp->val;
		arr[i++] = tmp->val;
		tmp = tmp->next;
	}
	res = ft_find_mid(arr, stack->size);
	free(arr);
	return (res);
}

void	ft_push_to_b(t_env *env, long long min, long long mid, long long max)
{
	long long	count;

	count = 0;
	while (1)
	{
		if (env->a->head->val != min && env->a->head->val != max)
		{
			if (env->a->head->score != 1)
			{
				ft_px(env->b, env->a, env->cmds);
				if (env->b->head->val > mid)
					ft_rx(env->b, env->cmds);
			}
			else
				ft_rx(env->a, env->cmds);
		}
		else if (count != 2)
		{
			ft_rx(env->a, env->cmds);
			count++;
		}
		else
			break ;
	}
}

void	ft_next_move(t_env *env)
{
	long long		count;
	long long		position;
	t_stack_elem	*curr;
	t_stack_elem	*min_score;

	count = 0;
	curr = env->b->head;
	while (count < env->b->size)
	{
		ft_calc_score(env, curr, count);
		curr = curr->next;
		++count;
	}
	min_score = ft_find_min_score(env->b, &position);
	ft_push_min_score(env, min_score, position);
}

void	ft_full_sort(t_env *env)
{
	long long	min;
	long long	mid;
	long long	max;
	long long	a_rotations;

	mid = ft_find_values(env->a, &min, &max);
	ft_push_to_b(env, min, mid, max);
	if (env->a->head->val == max)
		ft_rx(env->a, env->cmds);
	while (env->b->head != NULL)
		ft_next_move(env);
	a_rotations = ft_rotations_to_elem(env->a->head, env->a->size, min);
	ft_do_rotations(env, a_rotations, 0);
}
