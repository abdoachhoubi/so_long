/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:07:09 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/21 16:18:11 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			l;
	unsigned int	i;
	size_t			j;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l < start)
		return (ft_strdup("\0"));
	if (l < len)
		sub = (char *)ft_calloc(l + 1, sizeof(char));
	else
		sub = (char *)ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (start <= i && j < len)
			sub[j++] = s[i];
		i++;
	}
	return (sub);
}
