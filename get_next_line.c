/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeizi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:52:17 by afeizi            #+#    #+#             */
/*   Updated: 2025/11/27 14:00:33 by afeizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	char	*buff;
	char	*temp;
	ssize_t	byte_red;

	byte_red = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && byte_red > 0)
	{
		byte_red = read(fd, buff, BUFFER_SIZE);
		if (byte_red < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[byte_red] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer, buff);
		free(temp);
		if (!buffer)
			return (free(buff), NULL);
	}
	free(buff);
	return (buffer);
}

char	*sub_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*rest_line(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
	{
		new_buffer[j++] = buffer[i++];
	}
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = sub_line(buffer);
	buffer = rest_line(buffer);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include "get_next_line.h"

// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("test.txt", O_RDONLY); 
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return 1;
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);         
//     }

//     close(fd); 
//     return 0;
// }
