/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:49:22 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/11 21:49:24 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_init_stack(char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof (t_stack));
	if (!stack)
		ft_terminate("Memory allocation error");
	stack->head = NULL;
	stack->size = 0;
	stack->name = name;
	return (stack);
}

t_stack_elem	*ft_create_elem(int val)
{
	t_stack_elem	*new;

	new = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (!new)
		ft_terminate("Memory allocation error");
	new->val = val;
	new->score = -1;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_push(t_stack *stack, t_stack_elem *new)
{
	t_stack_elem	*last;

	if (stack->head)
	{
		last = stack->head->prev;
		new->prev = last;
		last->next = new;
		new->next = stack->head;
		stack->head->prev = new;
		stack->head = new;
	}
	else
	{
		stack->head = new;
		stack->head->prev = stack->head;
		stack->head->next = stack->head;
	}
	stack->size++;
}

t_stack_elem	*ft_pop(t_stack *stack)
{
	t_stack_elem	*tmp;

	tmp = NULL;
	if (stack && stack->size)
	{
		tmp = stack->head;
		if (stack->size == 1)
			stack->head = NULL;
		else
		{
			stack->head = stack->head->next;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		tmp->prev = NULL;
		tmp->next = NULL;
	}
	stack->size--;
	return (tmp);
}

void	ft_check_repeat(t_stack *stack)
{
	t_stack_elem	*curr;
	t_stack_elem	*next;

	if (stack->head->next != stack->head)
	{
		curr = stack->head;
		while (curr != stack->head->prev)
		{
			next = curr->next;
			while (next != stack->head)
			{
				if (next->val == curr->val)
					ft_error(stack);
				next = next->next;
			}
			curr = curr->next;
		}
	}
}
