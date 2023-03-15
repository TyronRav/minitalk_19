/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyronraviaer <tyronraviaer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:37:36 by tyronraviae       #+#    #+#             */
/*   Updated: 2023/03/15 00:51:33 by tyronraviae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void ft_signal(int signal)
{
    static int bit;
    static int i;

    if (signal == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", i);
        bit = 0;
        i = 0;
    }
}

int main(int argc, char *argv[])
{
    int pid;

    (void)argv;
    if (argc != 1)
    {
        ft_printf("Wrong format\n");
        ft_printf("Try : ./server\n");
        return (1);
    }
    pid = getpid();
    ft_printf("PID : %d\n", pid);
    ft_printf("Waiting for client...\n");
    while (1)
    {
        signal(SIGUSR1, ft_signal);
        signal(SIGUSR2, ft_signal);
        pause();
    }
    return (0);
}