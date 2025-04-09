/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:51:57 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/08 20:16:57 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_cat(char *filename)
{
    size_t  size;
    char    *basename_file;

    size = 30720;
    basename_file = basename(filename);
    if (ft_display_file(filename, size) == -1)
    {
        ft_putstr("ft_cat: ", 2);
        ft_putstr(basename_file, 2);
        ft_putstr(": ", 2);
        ft_putstr(strerror(errno), 2);
        ft_putchar('\n', 2);
        return (-1);
    }
    else
        return (0);
}