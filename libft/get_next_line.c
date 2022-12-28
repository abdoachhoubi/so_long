/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:23:10 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:31:18 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[s1_len++] = s2[i++];
	str[s1_len] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (str);
}

static char	*get_reminder(char **str, int nl)
{
	char	*reminder;
	int		rlen;

	rlen = ft_strlen(*str + nl);
	reminder = ft_substr(*str, nl, rlen);
	free(*str);
	*str = NULL;
	return (reminder);
}

static char	*get_current_line(char **line, char **tmp, int nl)
{
	*line = ft_substr(*tmp, 0, nl + 1);
	*tmp = get_reminder(tmp, nl + 1);
	return (*line);
}

static int	check_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*tmp[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			ret;
	int			nl;

	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret >= 0)
	{
		buff[ret] = 0;
		tmp[fd] = ft_strjoin_free(tmp[fd], buff);
		nl = check_newline(tmp[fd]);
		if (nl != -1)
			return (get_current_line(&line, &tmp[fd], nl));
		if (!ret && !tmp[fd][0])
			break ;
		if (!ret)
			return (get_reminder(&tmp[fd], 0));
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(tmp[fd]);
	tmp[fd] = NULL;
	return (NULL);
}
