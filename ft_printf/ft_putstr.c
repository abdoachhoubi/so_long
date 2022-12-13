/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:35:03 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/22 12:35:05 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *s, int *index)
{
	unsigned int	i;

	if (!s)
		ft_putstr("(null)", index);
	else
	{
		i = 0;
		while (s[i] != '\0')
			ft_putchar(s[i++], index);
	}
}
