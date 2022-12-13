/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:40:15 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/10 09:01:23 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcchr(const char *s, const char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	int	i;
	int	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] && ft_strcchr(set, s[i]))
		i++;
	while (s[j] && ft_strcchr(set, s[j]))
		j--;
	if (j == -1)
		return (ft_substr(s, i, 0));
	return (ft_substr(s, i, (j - i + 1)));
}
