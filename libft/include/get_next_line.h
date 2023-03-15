/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyronraviaer <tyronraviaer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:41:15 by traviaer          #+#    #+#             */
/*   Updated: 2022/10/17 13:04:28 by tyronraviae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *stat_str, char *buff);
char	*ft_read_to_left_str(int fd, char *stat_str);
char	*get_next_line(int fd);
char	*ft_get_line(char *stat_str);
char	*ft_new_left_str(char *stat_str);

#endif