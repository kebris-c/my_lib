/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:39:02 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/06 16:39:03 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

int ft_find_next_prime(int nb)
{
    if (nb <= 2)
        return (2);
    while (!ft_is_prime(nb))
        nb++;
    return (0);
}