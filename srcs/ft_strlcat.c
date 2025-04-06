/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:32:53 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/06 16:32:54 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strlcat(char *dest, char *src, int size)
{
    int i;
    int dest_len;
    int src_len;

    if (!dest || !src)
        return (0);
    dest_len = 0;
    while (dest_len < size && dest[dest_len])
        dest_len++;
    src_len = ft_strlen(srcs);
    if (size <= dest_len)
        return (size + src_len);
    i = 0;
    while (src[i] && (dest_len + i) < (size - 1))
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = 0;
    return (dest_len + src_len);
}