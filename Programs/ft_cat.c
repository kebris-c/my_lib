/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:47:41 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/08 18:51:42 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        if (ft_cat("") == -1)
            return (1);
    }
    else
    {
        while (*argv)
        {
            if (ft_cat(*argv) == -1)
                return (1);
            *argv++;
        }
    }
    return (0);
}