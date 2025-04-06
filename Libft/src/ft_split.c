#include "libft.h"
#include <stdlib.h>

static int ft_word_count(char *str, char *charset)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (!ft_is_sep(*str, charset) && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (ft_is_sep(*str, charset))
        {
            in_word = 0;
        }
        str++;
    }
    return count;
}

static char *ft_get_next_word(char **str, char *charset)
{
    char *start;
    char *word;
    int len = 0;

    while (**str && ft_is_sep(**str, charset))
        (*str)++;
    start = *str;
    while (**str && !ft_is_sep(**str, charset))
    {
        len++;
        (*str)++;
    }
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;
    for (int i = 0; i < len; i++)
        word[i] = start[i];
    word[len] = '\0';
    return word;
}

char **ft_split(char *str, char *charset)
{
    char **result;
    int word_count;
    int i = 0;

    if (!str || !charset)
        return NULL;
    word_count = ft_word_count(str, charset);
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return NULL;
    while (i < word_count)
    {
        result[i] = ft_get_next_word(&str, charset);
        if (!result[i])
        {
            while (i > 0)
                free(result[--i]);
            free(result);
            return NULL;
        }
        i++;
    }
    result[i] = NULL;
    return result;
}