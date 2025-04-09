/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:08:58 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/08 19:37:44 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ft_putstr_non_printable(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] > 31 && str[i] < 127)
            ft_putchar(str[i]);
        else
        {
            ft_putchar('\\', 1);
            ft_putnbr_base((str[i] - '0'), "0123456789abcdef");
        }
        i++;
    }
}