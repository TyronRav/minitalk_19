/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyronraviaer <tyronraviaer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:37:29 by tyronraviae       #+#    #+#             */
/*   Updated: 2023/03/15 00:59:20 by tyronraviae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void    ft_send_bits(int pid, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if ((c &(0x01 << bit)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        bit++;
    }
}

int main(int argc, char *argv[])
{
    int pid;
    int i;

    i = 0;
    if (argc != 3)
    {
        ft_printf("Wrong format\n");
        ft_printf("Try : ./client <PID> <MESSAGE>\n");
        return (1);
    }
    pid = ft_atoi(argv[1]);
    while (argv[2][i] != '\0')
    {
        ft_send_bits(pid, argv[2][i]);
        i++;
    }
    ft_send_bits(pid, '\0');
    ft_send_bits(pid, '\n');
    return (0);
}