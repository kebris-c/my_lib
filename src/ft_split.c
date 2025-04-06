/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:01:19 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/06 16:53:27 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_split_len(char *str, char *charset)
{
    int len;
    int i;

    len = 0;
    i = 0;
    while (ft_is_sep(str[i], charset))
        i++;
    while (str[i])
    {
        if (ft_is_sep(str[i], charset) && !ft_is_sep(str[i - 1], charset))
            len++;
        i++;
    }
    if (!ft_is_sep(str[i - 1], charset))
        len++;
    return (len);
}

static int ft_split_aux_mem(int i, int j, char **split, char *str, char *charset)
{
    int element_len;

    element_len = 0;
    while (ft_is_sep(str[i], charset))
        i++;
    if (!str[i])
        return (ft_free_matrix((void **)split, j), -1);
    while (str[i])
    {
        if (!ft_is_sep(str[i], charset))
            element_len++;
        else if (element_len > 0)
        {
            split[j] = (char *)malloc(sizeof(char) * (element_len + 1));
            if (!split[j])
                return (ft_free_matrix((void **)split, j), -1);
            element_len = 0;
            j++;
        }
        i++;
    }
    if (element_len > 0)
    {
        split[j] = (char *)malloc(sizeof(char) * (element_len + 1));
        if (!split[j])
            return (ft_free_matrix((void **)split, j), -1);
    }
    return (0);
}

static int ft_split_aux(char **split, char *str, char *charset)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    if (ft_split_aux_mem(i, j, split, str, charset) == -1)
        return (-1);
    while (str[i])
    {
        while (ft_is_sep(str[i], charset))
            i++;
        k = 0;
        while (!ft_is_sep(str[i], charset) && str[i])
            split[j][k++] = str[i++];
        split[j][k] = 0;
        j++;
    }
    return (0);
}

char    **ft_split(char *str, char *charset)
{
    char    **split;
    int     len;

    if (!str || !charset)
        return (NULL);
    if (ft_strlen(str) == 0)
    {
        split = (char **)malloc(sizeof(char *) * 1);
        if (!split)
            return (NULL);
        split[0] = NULL;;
        return (split);
    }
    len = ft_split_len(str, charset);
    split = (char **)malloc(sizeof(char *) * (len + 1));
    if (!split || ft_split_aux(split, str, charset) == -1)
        return (NULL);
    return (split);
}
