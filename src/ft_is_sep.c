/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:52:02 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/06 16:52:03 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

t_bool    ft_is_sep(char c, char *charset)
{
    int i;

    i = 0;
    while (charset[i])
    {
        if (c == charset[i])
            return (TRUE);
        i++;
    }
    return (FALSE);
}