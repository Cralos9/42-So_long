/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:09:09 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/13 12:21:56 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_extractline(char *line)
{
	size_t	size;
	char	*file;

	size = 0;
	while (line[size] != '\n' && line[size])
		size++;
	if (!line[size])
		return (0);
	file = ft_substr(line, size + 1, ft_strlen(line) - size);
	if (file[0] == '\0')
	{
		free(file);
		file = 0;
	}
	line[size + 1] = '\0';
	return (file);
}

static char	*ft_getline(int fd, char *buffer, char *file)
{
	int		count;
	char	*temp;

	count = 1;
	while (count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (0);
		if (count == 0)
			break ;
		buffer[count] = '\0';
		if (!file)
			file = ft_strdup("");
		temp = file;
		file = ft_strjoin(temp, buffer);
		free (temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = ft_getline(fd, buffer, file);
	free(buffer);
	if (!line)
	{
		free (file);
		file = 0;
		return (file);
	}
	file = ft_extractline(line);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
//     close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
