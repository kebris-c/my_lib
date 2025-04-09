/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:18:43 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/08 19:01:41 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv)
{
    size_t  size;

    if (argc == 1)
    {
        ft_putstr("File name missing.\n");
        return (1);
    }
    else if (argc > 2)
    {
        ft_putstr("Too many arguments.\n");
        return (1);
    }
    size = 1024;
    if (ft_display_file(argv[1], size) == -1)
        return (1);
    else
        return (0);
}