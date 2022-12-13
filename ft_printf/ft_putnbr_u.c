/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:35:51 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/22 12:35:52 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int nb, int *index)
{
	if (nb > 9)
	{
		ft_putnbr_u(nb / 10, index);
		ft_putnbr_u(nb % 10, index);
	}
	else
		ft_putchar(nb + 48, index);
}
