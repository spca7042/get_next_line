/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:36:37 by seralves          #+#    #+#             */
/*   Updated: 2025/07/23 15:55:33 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*join(char *stash, char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = malloc((ft_strlen(stash) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!line)
		return (free(stash), NULL);
	while (stash && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	while (buffer[j] && buffer[j] != '\n')
	{
		line[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		line[i + j++] = '\n';
	line[i + j] = '\0';
	free(stash);
	return (line);
}

void	set_nl(char *buffer)
{
	size_t	i;
	size_t	j;

	if (buffer == NULL)
		return ;
	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
	return ;
}
