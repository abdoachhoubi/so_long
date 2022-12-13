/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:36:07 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/18 09:54:15 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		s1 = dest + (n - 1);
		s2 = (unsigned char *)src + (n - 1);
		while (n--)
		{
			*s1-- = *s2--;
		}
	}
	return (dest);
}
