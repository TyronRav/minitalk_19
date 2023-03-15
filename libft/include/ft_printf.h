/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traviaer <traviaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:24:06 by traviaer          #+#    #+#             */
/*   Updated: 2022/09/02 11:52:54 by traviaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

int		ft_print_str(char *str);
int		ft_ptr_len(uintptr_t num);
char	*ft_uitoa(unsigned int nb);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_nbr(int nb);

int		ft_formats(va_list list, const char format);
int		ft_print_char(int c);
void	ft_putstr(char *str);
void	ft_put_ptr(uintptr_t num);

int		ft_num_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_hex_len(unsigned	int num);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);

#endif
