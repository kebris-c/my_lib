#include "libft.h"
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep)
{
    char *result;
    int total_len = 0;
    int i;
    int j;
    int k;

    if (size <= 0)
        return (malloc(1)); // Return an empty string if size is 0 or less

    // Calculate total length needed for the result string
    for (i = 0; i < size; i++)
    {
        total_len += ft_strlen(strs[i]);
        if (i < size - 1)
            total_len += ft_strlen(sep);
    }

    result = (char *)malloc(sizeof(char) * (total_len + 1));
    if (!result)
        return (NULL);

    k = 0;
    for (i = 0; i < size; i++)
    {
        j = 0;
        while (strs[i][j])
            result[k++] = strs[i][j++];
        if (i < size - 1)
        {
            j = 0;
            while (sep[j])
                result[k++] = sep[j++];
        }
    }
    result[k] = '\0';
    return (result);
}