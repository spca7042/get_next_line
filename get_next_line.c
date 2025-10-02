/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:36:05 by seralves          #+#    #+#             */
/*   Updated: 2025/07/24 14:14:21 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_chars;

	read_chars = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (*buffer || read_chars)
	{
		if (!*buffer)
		{
			read_chars = read(fd, buffer, BUFFER_SIZE);
			if (read_chars <= 0)
				break ;
			buffer[read_chars] = '\0';
		}
		line = join(line, buffer);
		set_nl(buffer);
		if (line && line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	if (read_chars < 0)
		return (free(line), NULL);
	return (line);
}

/*#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		count;
	char	text[] = "abcd efghijkl\nm\nnopqrstu\n\nvwxyz"; //To create test file

	//To create a test file
	fd = open("./testfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error creating file!");
		return (0);
	}
	write(fd, text, sizeof(text) - 1);
	close(fd);
	//To test get_next_line
	fd = open("./testfile.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Cannot read file!");
		return (0);
	}
	count = 0;
	while ((line = get_next_line(fd)) > 0)
	{
		printf("line %d ->%s\n", ++count, line);
		free(line);
	}
	if (line == NULL)
		printf("line %d ->(null)\n", ++count);
	free(line);
	close(fd);
	return (0);
}*/