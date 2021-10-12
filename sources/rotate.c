/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:47:29 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/11 21:47:32 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rx(t_stack *stack, t_cmd_list *list)
{
	char	*name;

	name = (char *)malloc(sizeof (char ) * 3);
	if (!name)
		ft_terminate("Memory allocation error");
	name[0] = 'r';
	name[2] = '\0';
	if (stack && stack->head)
		stack->head = stack->head->next;
	if (stack->name && list)
	{
		name[1] = stack->name;
		ft_add_cmd(list, ft_create_cmd(name));
	}
}

void	ft_rr(t_stack *a, t_stack *b, t_cmd_list *list)
{
	char	*name;

	name = ft_strdup("rr");
	if (!name)
		ft_terminate("Memory allocation error");
	if (a && a->head)
		a->head = a->head->next;
	if (b && b->head)
		b->head = b->head->next;
	if (list)
		ft_add_cmd(list, ft_create_cmd(name));
}

void	ft_rrx(t_stack *stack, t_cmd_list *list)
{
	char	*name;

	name = (char *)malloc(sizeof (char ) * 4);
	if (!name)
		ft_terminate("Memory allocation error");
	name[0] = 'r';
	name[1] = 'r';
	name[3] = '\0';
	if (stack && stack->head)
		stack->head = stack->head->prev;
	if (stack->name && list)
	{
		name[2] = stack->name;
		ft_add_cmd(list, ft_create_cmd(name));
	}
}

void	ft_rrr(t_stack *a, t_stack *b, t_cmd_list *list)
{
	char	*name;

	name = ft_strdup("rrr");
	if (!name)
		ft_terminate("Memory allocation error");
	if (a && a->head)
		a->head = a->head->prev;
	if (b && b->head)
		b->head = b->head->prev;
	if (list)
		ft_add_cmd(list, ft_create_cmd(name));
}
