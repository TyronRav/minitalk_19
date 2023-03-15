/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyronraviaer <tyronraviaer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:11:38 by tyronraviae       #+#    #+#             */
/*   Updated: 2022/10/17 13:11:50 by tyronraviae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_stat_str(int fd, char *stat_str)
{
	char	*buffer;
	int		rd_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(stat_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		stat_str = ft_strjoin(stat_str, buffer);
	}
	free(buffer);
	return (stat_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stat_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stat_str = ft_read_stat_str(fd, stat_str);
	if (!stat_str)
		return (NULL);
	line = ft_get_line(stat_str);
	stat_str = ft_new_left_str(stat_str);
	return (line);
}
