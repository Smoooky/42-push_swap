/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:49:56 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/11 23:16:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//void	ft_swap(t_stack_elem *first, t_stack_elem *second, t_stack *stack)
//{
//	t_stack_elem	*previous;
//	t_stack_elem	*next;
//
//	previous = first->prev;
//	next = second->next;
//	previous->next = second;
//	second->prev = previous;
//	first->next = next;
//	next->prev = first;
//	second->next = first;
//	first->prev = second;
//	stack->head = second;
//}

void	ft_swap(t_stack_elem *head)
{
	long long	temp;

	if (head == NULL || head->next == head)
		return ;
	temp = head->val;
	head->val = head->next->val;
	head->next->val = temp;
}

void	ft_px(t_stack *to, t_stack *from, t_cmd_list *list)
{
	char	*name;

	name = (char *) malloc(sizeof(char) * 3);
	if (!name)
		ft_terminate("Memory allocation error");
	name[0] = 'p';
	name[2] = '\0';
	if (to && from && list)
	{
		name[1] = to->name;
		ft_push(to, ft_pop(from));
		ft_add_cmd(list, ft_create_cmd(name));
	}
}

void	ft_sx(t_stack *stack, t_cmd_list *list)
{
	char	*name;

	name = (char *) malloc(sizeof(char) * 3);
	if (!name)
		ft_terminate("Memory allocation error");
	name[0] = 's';
	name[2] = '\0';
	if (stack && stack->head)
		ft_swap(stack->head);
	if (stack->name && list)
	{
		name[1] = stack->name;
		ft_add_cmd(list, ft_create_cmd(name));
	}
}

void	ft_ss(t_stack *a, t_stack *b, t_cmd_list *list)
{
	char	*name;

	name = ft_strdup("ss");
	if (!name)
		ft_terminate("Memory allocation error");
	if (a && a->head)
		ft_swap(a->head);
	if (b && b->head)
		ft_swap(b->head);
	if (list)
		ft_add_cmd(list, ft_create_cmd(name));
}
