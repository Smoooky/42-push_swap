/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:52:57 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/11 20:52:58 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_cmd_list	*ft_init_cmd_list(void)
{
	t_cmd_list	*list;

	list = (t_cmd_list *) malloc(sizeof (t_cmd_list));
	if (!list)
		ft_terminate("Memory allocation error");
	list->size = 0;
	list->head = NULL;
	return (list);
}

t_cmd	*ft_create_cmd(char *name)
{
	t_cmd	*new;

	new = (t_cmd *) malloc(sizeof (t_cmd));
	if (!new)
		ft_terminate("Memory allocation error");
	new->name = name;
	new->next = NULL;
	return (new);
}

void	ft_add_cmd(t_cmd_list *list, t_cmd *new)
{
	t_cmd	*tmp;

	if (!list->head)
		list->head = new;
	else
	{
		tmp = list->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	list->size++;
}

void	ft_print_cmd_list(t_cmd_list *list)
{
	t_cmd	*tmp;

	tmp = list->head;
	while (tmp)
	{
		ft_putendl_fd(tmp->name, 1);
		tmp = tmp->next;
	}
}
