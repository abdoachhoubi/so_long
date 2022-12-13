/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:19:20 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/08 15:10:16 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Handles substring memory allocation errors
static char	**catch_err(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

// Counts the number of strings that will be added to the array
static int	ft_wdcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

// Duplicates a substring
static char	*ft_strxdup(char const *s, char c, int *x)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	while (s[*x] == c)
		(*x)++;
	i = *x;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[*x] && s[*x] != c)
		str[i++] = s[(*x)++];
	str[i] = '\0';
	return (str);
}

// Splits a string into an array of strings
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		x;
	int		len;

	len = ft_wdcount(s, c);
	strs = (char **)malloc((len + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	x = 0;
	while (i < len)
	{
		strs[i] = ft_strxdup(s, c, &x);
		if (!strs[i])
			return (catch_err(strs));
		i++;
	}
	strs[i] = 0;
	return (strs);
}
