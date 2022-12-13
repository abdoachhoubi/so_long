/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:07 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/18 09:50:36 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(long nb)
{
	size_t		size;
	long long	i;

	size = 0;
	if (nb == 0)
		size++;
	if (nb < 0)
	{
		i = nb * -1;
		size++;
	}
	else
		i = nb;
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

static int	ft_sign(long *nb, size_t *size)
{
	if (*nb < 0)
	{
		*nb = *nb * -1;
		*size = *size - 1;
		return (-1);
	}
	return (1);
}

static char	*ft_strrev(char *str, size_t len)
{
	size_t	i;
	char	c;

	i = 0;
	while (i < len)
	{
		c = str[i];
		str[i] = str[len - 1];
		str[len - 1] = c;
		len--;
		i++;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	size_t		size;
	size_t		i;
	int			sign;
	char		*a;
	long		n;

	n = nb;
	i = 0;
	size = ft_ilen(n);
	a = (char *)malloc((size + 1) * sizeof(char));
	if (!a)
		return (0);
	sign = ft_sign(&n, &size);
	if (n == 0)
		a[i++] = '0';
	while (i < size)
	{
		a[i++] = (n % 10) + 48;
		n /= 10;
	}
	if (sign == -1)
		a[i++] = '-';
	a[i] = '\0';
	ft_strrev(a, ft_strlen(a));
	return (a);
}
