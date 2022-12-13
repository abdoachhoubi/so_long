/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:34:30 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/22 12:34:33 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_specifier(va_list args, const char spec, int *index)
{
	if (spec == 'c')
		ft_putchar((char)va_arg(args, int), index);
	else if (spec == 's')
		ft_putstr(va_arg(args, char *), index);
	else if (spec == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), index);
	else if (spec == 'x' || spec == 'X')
		ft_putnbr_base(va_arg(args, int), spec, index);
	else if (spec == 'd' || spec == 'i')
		ft_putnbr(va_arg(args, int), index);
	else if (spec == 'p')
		ft_print_memory(va_arg(args, void *), index);
	else if (spec == '%')
		ft_putchar('%', index);
	else
		ft_putchar(spec, index);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_check_specifier(args, *format, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
