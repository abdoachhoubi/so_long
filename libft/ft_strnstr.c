/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:43:48 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/07 14:08:18 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	j = ft_strlen(needle);
	while (haystack[i] != '\0' && i < n)
	{
		if (haystack[i] == needle[0] && n - i >= j
			&& ft_strncmp(&haystack[i], needle, j) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
