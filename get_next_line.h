/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 11:12:51 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/11/16 11:38:49 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
#include <stdlib.h>
# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*stashtrim(char *stash);
char	*get_line(char *stash);
char	*append(char *stash, char *buffer, ssize_t ret);
int	strnonl(char *stash);
ssize_t	ft_strlen(char *str);

#endif
