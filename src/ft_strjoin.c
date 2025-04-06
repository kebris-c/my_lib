/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:01:35 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/06 16:48:52 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

static void    ft_strjoin_aux(char *str, char ** strs, int size, char *sep)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j])
            str[k++] = strs[i][j++];
        if (i < size - 1)
        {
            j = 0;
            while (sep[j])
                str[k++] = sep[j++];
        }
        i++;
    }
    str[k] = 0;
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
    char    *str;
    int     i;
    int     total_len;

    if (!strs || size == 0)
    {
        str = (char *)malloc(sizeof(char) * 1);
        if (!str)
            return (NULL);
        str[0] = 0;
        return (str);
    }
    i = 0;
    total_len = 0;
    while (i < size)
        total_len += ft_strlen(strs[i++]);
    total_len += ft_strlen(sep) * (size - 1);
    str = (char *)malloc(sizeof(char) * (total_len + 1));
    if (!str)
        return (NULL);
    ft_strjoin_aux(str, strs, size, sep);
    return (str);
}