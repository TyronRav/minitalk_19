/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traviaer <traviaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:52:04 by traviaer          #+#    #+#             */
/*   Updated: 2022/09/02 13:06:59 by traviaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*num;
	int		len;

	len = ft_num_len(nb);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (nb != 0)
	{
		num[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int nb)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (nb == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(nb);
		print_length += ft_print_str(num);
		free(num);
	}
	return (print_length);
}
