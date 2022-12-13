/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:35:39 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/22 12:35:40 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *index)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648", index);
	else if (nb < 0)
	{
		ft_putchar('-', index);
		ft_putnbr(-nb, index);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, index);
		ft_putnbr(nb % 10, index);
	}
	else
		ft_putchar(nb + 48, index);
}
