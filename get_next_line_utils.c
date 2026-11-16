/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 11:12:45 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/11/16 11:37:13 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	strnonl(char *stash)
{
	if (!stash)
		return (1);
	while (*stash)
	{
		if (*stash == '\n')
			return (0);
		stash++;
	}
	return (1);
}

char	*append(char *stash, char *buffer, ssize_t ret)
{
	ssize_t	len;
	ssize_t	i;
	char	*new;

	i = -1;
	len = ft_strlen(stash);
	new = malloc(len + ret + 1);
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	new[len + ret] = '\0';
	while (++i < len)
		new[i] = stash[i];
	i = -1;
	while (++i < ret)
		new[i + len] = buffer[i];
	free(stash);
	return (new);
}

char	*get_line(char *stash)
{
	char	*line;
	ssize_t	i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (--i >= 0)
		line[i] = stash[i];
	return (line);
}

char	*stashtrim(char *stash)
{
	char	*new;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = ft_strlen(stash);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new = malloc(j - i + 1);
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}
