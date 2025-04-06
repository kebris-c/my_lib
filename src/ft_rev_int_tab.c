/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_in_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:16:06 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/06 16:19:27 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_rev_int_tab(int *tab, int size)
{
    int i;
    int k;

    i = 0;
    k = size - 1;
    while (i < size)
    {
        ft_swap(&tab[i], &tab[k]);
        i++;
        k--;
    }
}
