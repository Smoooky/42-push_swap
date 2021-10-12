/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:54:32 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/11 20:54:34 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long long	ft_calc_a_rotations(t_stack *a, long long val)
{
	t_stack_elem	*curr;
	long long		count;

	count = 0;
	curr = a->head;
	while (curr->prev->val > val || val > curr->val)
	{
		curr = curr->next;
		++count;
	}
	if (count < a->size - count - 1)
		return (count);
	return (count - a->size);
}

void	ft_calc_score(t_env *env, t_stack_elem *curr, long long pos)
{
	long long	a_rotations;
	long long	b_rotations;

	a_rotations = ft_calc_a_rotations(env->a, curr->val);
	if (pos < env->b->size - pos)
		b_rotations = pos;
	else
		b_rotations = pos - env->b->size;
	if ((a_rotations > 0 && b_rotations > 0)
		|| (a_rotations < 0 && b_rotations < 0))
	{
		if (ft_abs(a_rotations) > ft_abs(b_rotations))
			curr->score = ft_abs(a_rotations);
		else
			curr->score = ft_abs(b_rotations);
	}
	else
		curr->score = ft_abs(a_rotations) + ft_abs(b_rotations);
}

t_stack_elem	*ft_find_min_score(t_stack *b, long long *pos)
{
	long long		count;
	t_stack_elem	*curr;
	t_stack_elem	*min_score;

	*pos = 0;
	count = 1;
	min_score = b->head;
	curr = b->head->next;
	while (count < b->size)
	{
		if (curr->score < min_score->score)
		{
			*pos = count;
			min_score = curr;
		}
		curr = curr->next;
		count++;
	}
	return (min_score);
}

void	ft_push_min_score(t_env *env, t_stack_elem *min_score, long long pos)
{
	long long	a_rotations;
	long long	b_rotations;

	a_rotations = ft_calc_a_rotations(env->a, min_score->val);
	if (pos < env->b->size - pos)
		b_rotations = pos;
	else
		b_rotations = pos - env->b->size;
	ft_do_rotations(env, a_rotations, b_rotations);
	ft_px(env->a, env->b, env->cmds);
}

long long	ft_rotations_to_elem(t_stack_elem *head,
								  long long size, long long val)
{
	long long		count;
	t_stack_elem	*curr;

	if (head->val == val)
		return (0);
	count = 1;
	curr = head->next;
	while (curr != head)
	{
		if (curr->val == val)
			break ;
		curr = curr->next;
		count++;
	}
	if (count < size - count)
		return (count);
	return (count - size);
}
