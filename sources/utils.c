/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:55:16 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/11 20:55:20 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_terminate(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	ft_swap_num(long long *xp, long long *yp)
{
	long long	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

long long	ft_find_mid(long long *arr, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap_num(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	return (arr[size / 2]);
}

t_env	*ft_init_env(t_stack *a, t_stack *b, t_cmd_list *cmds)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		ft_terminate("Memory allocation error");
	env->a = a;
	env->b = b;
	env->cmds = cmds;
	return (env);
}

long long	ft_abs(long long a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
