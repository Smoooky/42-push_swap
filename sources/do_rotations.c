/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:53:06 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/11 20:53:07 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_comb_rotations(t_env *env, long long *a_rotations,
						  long long *b_rotations)
{
	while (*a_rotations > 0 && *b_rotations > 0)
	{
		ft_rr(env->a, env->b, env->cmds);
		--(*a_rotations);
		--(*b_rotations);
	}
	while (*a_rotations < 0 && *b_rotations < 0)
	{
		ft_rrr(env->a, env->b, env->cmds);
		++(*a_rotations);
		++(*b_rotations);
	}
}

static void	ft_simp_rotations(t_env *env, long long *a_rotations,
								 long long *b_rotations)
{
	while (*b_rotations < 0)
	{
		ft_rrx(env->b, env->cmds);
		++(*b_rotations);
	}
	while (*b_rotations > 0)
	{
		ft_rx(env->b, env->cmds);
		--(*b_rotations);
	}
	while (*a_rotations < 0)
	{
		ft_rrx(env->a, env->cmds);
		++(*a_rotations);
	}
	while (*a_rotations > 0)
	{
		ft_rx(env->a, env->cmds);
		--(*a_rotations);
	}
}

void	ft_do_rotations(t_env *env, long long a_rotations,
						long long b_rotations)
{
	ft_comb_rotations(env, &a_rotations, &b_rotations);
	ft_simp_rotations(env, &a_rotations, &b_rotations);
}
