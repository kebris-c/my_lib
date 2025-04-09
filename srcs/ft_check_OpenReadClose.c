/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_OpenReadClose.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:23:34 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/08 21:36:19 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_check_OpenReadClose(size_t bytes_read, int fd)
{
    const char  *O_ERR_MSG;
    const char  *R_ERR_MSG;
    const char  *C_ERR_MSG;

    O_ERR_MSG = "Cannot open file.\n";
    R_ERR_MSG = "Error reading file.\n";
    C_ERR_MSG = "Error closing file.\n";
    if (fd == -1)
    {
        ft_putstr(O_ERR_MSG, 2);
        close(fd);
        if (close(fd) == -1)
            ft_putstr(C_ERR_MSG, 2);
        return (-1);
    }
    if (bytes_read == -1)
    {
        ft_putstr(R_ERR_MSG, 2);
        close(fd);
        return (-1);
    }
    if (close(fd) == -1)
    {
        ft_putstr(C_ERR_MSG, 2);
        return (-1);
    }
    return (0);
}