/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyronraviaer <tyronraviaer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:10:57 by tyronraviae       #+#    #+#             */
/*   Updated: 2022/10/17 13:11:05 by tyronraviae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stat_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stat_str)
	{
		stat_str = (char *)malloc(sizeof(char));
		stat_str[0] = '\0';
	}
	if (!stat_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(stat_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stat_str)
		while (stat_str[++i] != '\0')
			str[i] = stat_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(stat_str) + ft_strlen(buff)] = '\0';
	free(stat_str);
	return (str);
}

char	*ft_get_line(char *stat_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!stat_str[i])
		return (NULL);
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stat_str[i] && stat_str[i] != '\n')
	{
		str[i] = stat_str[i];
		i++;
	}
	if (stat_str[i] == '\n')
	{
		str[i] = stat_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *stat_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	if (!stat_str[i])
	{
		free(stat_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stat_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stat_str[i])
		str[j++] = stat_str[i++];
	str[j] = '\0';
	free(stat_str);
	return (str);
}
