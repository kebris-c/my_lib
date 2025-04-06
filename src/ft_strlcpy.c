/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:27:41 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/06 16:27:41 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strlcpy(char *dest, char *src, int size)
{
    int i;
    int src_len;

    src_len = ft_strlen(src);
    if (size == 0)
        return (src_len);
    i = 0;
    while (dest[i] && src[i] && i < size - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (src_len);
}
