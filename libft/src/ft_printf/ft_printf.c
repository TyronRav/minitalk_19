/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyronraviaer <tyronraviaer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:50:44 by traviaer          #+#    #+#             */
/*   Updated: 2022/10/17 12:34:10 by tyronraviae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list list, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_char(va_arg(list, int));
	else if (format == 's')
		print_length += ft_print_str(va_arg(list, char *));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(list, unsigned int));
	else if (format == 'd' || format == 'i')
		print_length += ft_print_nbr(va_arg(list, int));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(list, unsigned long long));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(list, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(list, str[i + 1]);
			i++;
		}
		else
			print_length += ft_print_char(str[i]);
		i++;
	}
	va_end(list);
	return (print_length);
}
