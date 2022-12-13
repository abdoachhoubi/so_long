/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:35:13 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/22 12:35:16 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Similar to ft_putnbr_base
static void	ft_puthex(unsigned long int nb, int *index)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(base[nb % 16], index);
	else
	{
		ft_puthex(nb / 16, index);
		ft_puthex(nb % 16, index);
	}
}

// Prints memory address to the std output
void	ft_print_memory(const void *ptr, int *index)
{
	unsigned long int	address;

	address = (unsigned long int)ptr;
	ft_putstr("0x", index);
	ft_puthex(address, index);
}
