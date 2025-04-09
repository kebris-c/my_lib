/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:57:24 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/06 16:57:24 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_show_tab(struct s_stock_str *par)
{
    int     i;

    i = 0;
    while (par[i].str != NULL)
    {
        ft_putstr(par[i].str, 1);
        ft_putchar('\n');
        ft_putnbr(par[i].size);
        ft_putchar('\n', 1);
        ft_putstr(par[i].copy);
        ft_putchar('\n');
        i++;
    }
}
