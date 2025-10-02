/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:36:05 by seralves          #+#    #+#             */
/*   Updated: 2025/07/24 17:10:55 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	int			read_chars;

	read_chars = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= MAX_FD)
		return (NULL);
	while (*buffer[fd] || read_chars)
	{
		if (!*buffer[fd])
		{
			read_chars = read(fd, buffer[fd], BUFFER_SIZE);
			if (read_chars <= 0)
				break ;
			buffer[fd][read_chars] = '\0';
		}
		line = join(line, buffer[fd]);
		set_nl(buffer[fd]);
		if (line && line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	if (read_chars < 0)
		return (free(line), NULL);
	return (line);
}

#include <stdio.h>

void	create_test_files(void)
{
	int		fd;
	char	text[] = "Line1\nLine2\nLine3";

	fd = open("./test1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error creating file!");
		return ;
	}
	write(fd, text, sizeof(text) - 1);
	close(fd);
	fd = open("./test2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error creating file!");
		return ;
	}
	write(fd, text, sizeof(text) - 1);
	close(fd);
	fd = open("./test3.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error creating file!");
		return ;
	}
	write(fd, text, sizeof(text) - 1);
	close(fd);
	return ;
}

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*next_line;
	int		count1;
	int		count2;
	int		count3;

	//create_test_files();
	fd = open("test1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error by opening file 1!");
		return (1);
	}
	fd2 = open("test2.txt", O_RDONLY);
	if (fd2 < 0)
	{
		perror("Error by opening file 2!");
		return (1);
	}
	fd3 = open("test3.txt", O_RDONLY);
	if (fd3 < 0)
	{
		perror("Error by opening file 3!");
		return (1);
	}
	count1 = 0;
	count2 = 0;
	count3 = 0;
	next_line = get_next_line(fd);
	printf("file 1 [line %d]->%s\n", ++count1, next_line);
	free(next_line);
	next_line = get_next_line(fd2);
	printf("file 2 [line %d]->%s\n", ++count2, next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("file 1 [line %d]->%s\n", ++count1, next_line);
	free(next_line);
	next_line = get_next_line(fd3);
	printf("file 3 [line %d]->%s\n", ++count3, next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("file 1 [line %d]->%s\n", ++count1, next_line);
	free(next_line);
	next_line = get_next_line(fd2);
	printf("file 2 [line %d]->%s\n", ++count2, next_line);
	free(next_line);
	next_line = get_next_line(fd3);
	printf("file 3 [line %d]->%s\n", ++count3, next_line);
	free(next_line);
	next_line = get_next_line(fd2);
	printf("file 2 [line %d]->%s\n", ++count2, next_line);
	free(next_line);
	next_line = get_next_line(fd);
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}