/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:40:28 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/20 16:16:11 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswspc(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	catch_error(unsigned long long x, int sign)
{
	if (x >= 9223372036854775807 && sign == 1)
		return (-1);
	else if (x > 9223372036854775807 && sign == -1)
		return (0);
	else
		return ((int)x);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] != '\0' && ft_iswspc(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]) == 1)
	{
		res *= 10;
		res += nptr[i++] - 48;
	}
	return (catch_error(res, sign) * sign);
}
