/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:53:26 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/12 00:28:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_not_valid(long long argc, char **argv,
						   long long arg, size_t count)
{
	if ((!(ft_isdigit(argv[arg][count])) && argv[arg][count] != '-'
			&& !((argv[arg][count] == ' ') && (argc == 2)))
		|| ((argv[arg][count + 1] == '\0'
			|| argv[arg][count + 1] == ' ') && argv[arg][count] == '-')
		|| (count > 0 && (argv[arg][count] == '-'
			&& argv[arg][count - 1] != ' ')))
		return (1);
	return (0);
}

void	ft_check_args(long long argc, char **argv)
{
	long long	arg;
	size_t		count;
	size_t		str_len;

	arg = 1;
	while (arg < argc)
	{
		count = 0;
		str_len = ft_strlen(argv[arg]);
		if (str_len == 0)
			ft_error(NULL);
		while (count < str_len)
		{
			if (is_not_valid(argc, argv, arg, count))
				ft_error(NULL);
			count++;
		}
		arg++;
	}
}

void	ft_parse_str(char *str, t_stack *stack)
{
	size_t		i;
	char		**spltd;
	long long	val;

	spltd = ft_split(str, ' ');
	i = 0;
	while (spltd[i])
		i++;
	while (i-- != 0)
	{
		val = ft_atol(spltd[i]);
		if (val > INT32_MAX || val < INT32_MIN)
			ft_error(stack);
		ft_push(stack, ft_create_elem(ft_atol(spltd[i])));
	}
	i = 0;
	while (spltd[i])
		free(spltd[i++]);
	free(spltd);
}

void	ft_read_args(size_t argc, char **argv, t_stack *stack)
{
	size_t		i;
	long long	val;

	i = 1;
	while (i < argc)
	{
		val = ft_atol(argv[argc - i]);
		if (val > INT32_MAX || val < INT32_MIN)
			ft_error(stack);
		ft_push(stack, ft_create_elem(val));
		i++;
	}
}
