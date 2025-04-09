/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:46:37 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/09 15:58:42 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_mem_err(int fd)
{
    char    *MEM_ERR_MSG;

    MEM_ERR_MSG = "Error with memory alocation\n";
    ft_putstr(MEM_ERR_MSG, 2);
    close(fd);
}

static int ft_tail_no_flag(char *filename, size_t size)


static int ft_tail_c_flag(int n, char filename, size_t size)
{
    char    buffer[size];
    char    *file_content;
    size_t  bytes_read;
    size_t  total_bytes_read;
    int     fd;

    bytes_read = 0;
    fd = open(filename, O_RDONLY);
    if (ft_check_OpenReadClose(bytes_read, fd) == -1)
        return (-1);
    file_content = (char *)malloc(0);
    if (!file_content)
    {
        ft_mem_err(fd);
        return (-1);
    }
    

    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytes_read] = '\0';
        ft_putstr(buffer, 1);
    }
    if (ft_check_OpenReadClose(bytes_read, fd) == -1)
        return (-1);
    else
        return (0);
}

int ft_tail(char *to_read, char *filename)
{
    size_t  size;

    size = 1024;
    if (!filename)
        ft_tail("10", to_read);
    else
    {
        if (ft_get_file_content(ft_atoi(to_read), filename, size) == -1)
            return (-1);
    }
    return (0);
}