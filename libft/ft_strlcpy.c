/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:45:21 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/08 13:49:56 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s2);
	if (len > 0)
	{
		while (s2[i] != '\0' && i < len - 1)
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (l);
}
