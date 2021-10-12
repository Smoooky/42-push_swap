/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:53:16 by sstyr             #+#    #+#             */
/*   Updated: 2021/10/11 20:53:17 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	ft_is_ignorable(char ch)
{
	if ((ch != '\n') && (ch != ' ') && (ch != '\t')
		&& (ch != '\v') && (ch != '\r') && (ch != '\f'))
		return (0);
	return (1);
}

long long	ft_atol(const char *str)
{
	long long	sign;
	long long	res;

	res = 0;
	sign = 1;
	while (ft_is_ignorable(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - '0') * sign;
		str++;
	}
	return (res);
}
