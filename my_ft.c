#include "my_header.h"

int ft_atoi(char *str)
{
    int i;
    int sign;
    int re;

    i = 0;
    sign = 1;
    re = 0;
    while (str[i] == ' ' || (str[i] >= '9' && str[i] <= '13'))
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
        re = re * 10 + (str[i] - '0');
        i++;
    }
    return (re * sign);
}

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nbr)
{
    if (nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    else if (nbr < 0)
    {
        write(1, "-", 1);
        ft_putnbr(-nbr);
        return ;
    }
    else
    {
        if (nbr > 9)
            ft_putnbr(nbr / 10);
        ft_putchar(nbr % 10 + '0');
    }
}

int ft_base_checker(char *base)
{
    int i;
    int j;

    if (ft_strlen(base) < 2)
        return (1);
    i = 0;
    while (base[i])
    {
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j] || base[i] == '-' || base[i] == '+')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void    ft_putnbr_base(int nbr, char *base)
{
    int base_len;

    if (ft_base_checker(base) == 1)
        return ;
    base_len = ft_strlen(base);
    if (nbr < 0)
    {
        ft_putchar('-');
        ft_putnbr_base(-nbr, base);
        return ;
    }
    if (nbr > 9)
        ft_putnbr_base(nbr / base_len, base);
    ft_putchar(base[nbr % base_len]);
}

int ft_base_pos(char nb, char *base)
{
    int pos;

    pos = 0;
    while (base[pos])
    {
        if (nb == base[pos])
            return (pos);
    }
    return (-1);
}

int ft_atoi_base(char *nbr, char *base)
{
    int sign;
    int re;
    int i;

    if (ft_base_checker(base) == 1)
        return (0);
    i = 0;
    re = 0;
    sign = 1;
    while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
        i++;
    while (nbr[i] == '-' || nbr[i] == '+')
    {
        if (nbr[i] == '-')
            sign = -sign;
        i++;
    }
    while (nbr[i])
    {
        if (pos == -1)
            return (0);
        re = re * ft_strlen(base) + ft_base_pos(nbr[i], base);
        i++;
    }
    return (re * sign);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0 ;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void    ft_print_combn_aux(char *nb)
{
    int i;

    i = 0;
    while (i < 10)
    {
        nb[i] = i + '0';
        ft_putchar(nb[i]);
        if (i + 1 != 10)
            ft_putstr(", ");
        else if (i + 1 == 10)
            ft_putchar('\n');
        i++;
    }
    nb[i] = 0;
}

void    ft_print_combn_aux2(char *nb)
{
    int i;

    i = 1;
    while (i < n && nb[i] && i > 0 && i < 10)
    {
        nb[i] = nb[i - 1] + 1;
        ft_putstr(nb);
        if (i + 1 != 10)
            ft_putstr(", ");
        else if (i + 1 == 10)
            ft_putchar("\n");
        i++;
    }
}

void    ft_print_combn(int n)
{
    int     i;
    char    *nb;

    if (n <= 0 || n >= 10)
        return ;
    else if (n == 1)
    {
        nb = (char *)malloc(sizeof(char) * 10);
        ft_print_combn_aux(nb);
        free(nb);
        return ;
    }
    nb = (char *)malloc(sizeof(char) * 10);
    nb[0] = 0;
    ft_print_combn_aux2(nb);
    free(nb);
}

void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}

void    ft_ultimate_div_mod(int *a, int *b)
{
    int div;
    int mod;

    div = *a / *b;
    mod = *a % *b;
    *a= div;
    *b = mod;
}

void    ft_rev_int_tab(int *tab, int size)
{
    int i;
    int k;

    i = 0;
    k = size - 1;
    while (i < size)
    {
        ft_swap(&tab[i], &tab[k]);
        i++;
        k--;
    }
}

void    ft_sort_int_tab(int *tab, int size)
{
    int i;
    int k;

    i = 0;
    while (tab[i] && k < size)
    {
        k = i + 1;
        while (tab[k])
        {
            if (tab[i] > tab[k])
                ft_swap(&tab[i], &tab[k]);
            k++;
        }
        i++;
    }
}

char    *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int    i;

    i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

int ft_str_is_alpha(char *str)
{
    int i;
    int str_len;

    str_len = ft_strlen(str);
    if (str_len == 0)
        return (1);
    i = 0;
    while (str[i])
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            return (0);
        i++;
    }
    return (1);
}

int ft_str_is_numeric(char *str)
{
    int i;
    int str_len;

    str_len = ft_strlen(str);
    if (str_len == 0)
        return (1);
    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int ft_str_is_lowercase(char *str)
{
    int i;
    int str_len;

    str_len = ft_strlen(str);
    if (str_len == 0)
        return (1);
    i = 0;
    while (str[i])
    {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return (0);
        i++;
    }
    return (1);
}

int ft_str_is_uppercase(char *str)
{
    int i;
    int str_len;

    str_len = ft_strlen(str);
    if (str_len == 0)
        return (1);
    i = 0;
    while (str[i])
    {
        if (!(str[i] >= 'A' && str[i] <= 'Z'))
            return (0);
        i++;
    }
    return (1);
}

int ft_str_is_printable(char *str)
{
    int i;
    int str_len;

    str_len = ft_strlen(str);
    if (str_len == 0)
        return (1);
    i = 0;
    while (str[i])
    {
        if (!(str[i] >= 32 && str[i] <= 126))
            return (0);
        i++;
    }
    return (1);
}

char    *ft_strupcase(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return (str);
}

char    *ft_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}

char    *ft_strcapitalize(char *str)
{
    int i;

    str = ft_strlowcase(str);
    i = 0;
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
    i++;
    while (str[i])
    {
        if (!((str[i - 1] >= 'a' && str[i - 1] <= 'z')
            || (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
            || (str[i - 1] >= '0' && str[i - 1] <= '9'))
            && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
        i++;
    }
    return (str);
}

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int    i;
    unsigned int    src_len;

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

void    ft_putstr_non_printable(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] > 31 && str[i] < 127)
            ft_putchar(str[i]);
        else
        {
            ft_putchar('\\');
            ft_putnbr_base((unsigned char)str[i], "0123456789abcdef");
        }
        i++;
    }
}

void    ft_print_addr(unsigned long addr, char *base)
{
    char    *hex;
    char    hex_addr[17];
    int     i;

    hex = base;
    hex_addr[16] = 0;
    i = 15;
    while (i >= 0)
    {
        hex_addr[i--] = hex[addr % 16];
        addr /= 16;
    }
    ft_putstr(hex_addr);
    ft_putstr(": ");
}

void    ft_print_memory_content(void *addr, unsigned int size, char *base)
{
    unsigned int    i;

    i = 0;
    while (i < 16)
    {
        if (i < size)
        {
            ft_putnbr_base(ptr[i], base);
            if (i % 2)
                ft_putchar(' ');
        }
        else
            ft_putstr("  ");
        i++;
    }
}

void    ft_print_ascii(unsigned char *ptr, unsigned int size)
{
    unsigned int    i;

    i = 0;
    while (i < size)
    {
        if (ptr[i] >= 32 && ptr[i] <= 126)
            ft_putchar(ptr[i]);
        else
            ft_putchar('.');
        i++;
    }
}

void    *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int    i;
    unsigned int    line_size;
    unsigned char   *ptr;
    char            *base;

    i = 0;
    ptr = (unsigned char *)addr;
    base = "0123456789abcdef";
    while (i < size)
    {
        if (size - i >= 16)
            line_size = 16;
        else
            line_size = size - i;
        ft_print_addr((unsigned long)(ptr + i), base);
        ft_print_memory_content(ptr + i, line_size, base);
        ft_print_ascii(ptr + 1, line_size);
        ft_putchar('\n');
        i += 16;
    }
    return (addr);
}

int     ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int     ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int i;

    i = 0;
    while (s1[i] && s1[i] == s2[i] && i < n)
        i++;
    return (s1[i] - s2[i]);
}

char    *ft_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    while (dest[i])
        i++;
    j = 0;
    while (src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = 0;
    return (dest);
}

char    *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int i;
    unsigned int j;

    i = 0;
    while (dest[i])
        i++;
    j = 0;
    while (src[j] && j < nb)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = 0;
    return (dest);
}

char    *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    if (!str || !to_find)
        return (NULL);
    else if (!*to_find)
        return (str);
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i + j] == to_find[j] && to_find[j])
            j++;
        if (!to_find[j])
            return (str + i);
        i++;
    }
    return (NULL);
}

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int    i;
    unsigned int    dest_len;
    unsigned int    src_len;

    if (!dest || !src)
        return (0);
    dest_len = 0;
    while (dest_len < size && dest[dest_len])
        dest_len++;
    src_len = (unsigned int)ft_strlen(src);
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

int     ft_iterative_factorial(int nb)
{
    int i;
    int re;

    if (nb == 0)
        return (1);
    else if (nb < 0)
        return (0);
    i = nb;
    re = 1;
    while (i > 1)
    {
        re *= i;
        i--;
    }
    return (re);
}

int     ft_recursive_factorial(int nb)
{
    if (nb == 0)
        return (1);
    else if (nb < 0)
        return (0);
    return (nb * ft_recursive_factorial(nb - 1));
}

int     ft_iterative_power(int nb, int power)
{
    int re;
    int i;

    if (power < 0)
        return (0);
    else if (power == 0)
        return (1);
    i = 0;
    re = 1;
    while (i < power)
    {
        re *= nb;
        i++;
    }
    return (re);
}

int     ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return (0);
    else if (power == 0)
        return (1);
    return (nb * ft_recursive_power(nb, power - 1));
}

int     ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    else if (index == 0 || index == 1)
        return (index);
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int     ft_sqrt(int nb)
{
    int guess;
    int next_guess;

    if (nb < 0)
        return (0);
    else if (nb == 0 || nb == 1)
        return (nb);
    guess = (nb / 2) + 1;
    next_guess = (guess + (nb / guess)) / 2;
    while (guess != next_guess)
    {
        guess = next_guess;
        next_guess = (guess + (nb / guess)) / 2;
    }
    if (next_guess * next_guess == nb)
        return (next_guess);
    return (0);
}

int ft_is_prime(int nb)
{
    int i;

    if (nb == 2 || nb == 3 || nb == 5)
        return (1);
    else if (nb < 2 || nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || (nb % 6 != 1
        && nb % 6 != 5))
        return (0);
    i = 7;
    while (i * i <= nb)
    {
        if (nb % i == 0 || nb % (i + 2) == 0)
            return (0);
        i += 6;
    }
    return (1);
}

int     ft_find_next_prime(int nb)
{
    if (nb <= 2)
        return (2);
    while (!ft_is_prime(nb))
        nb++;
    return (0);
}

bool     ft_safe_cell(int *board, int col, int row)
{
    int prev_col;
    int prev_row;

    prev_col = 0;
    while (prev_col < col)
    {
        prev_row = board[prev_col];
        if (prev_row == row || prev_row - prev_col == row - col
            || prev_row + prev_col == row + col)
            return (false);
        prev_col++;
    }
    return (true);
}

void    ft_play_chess(int n, char table[n][n], int *sol_num)
{
    int x;
    int y;

    printf("\nSolution nº%d:\n", ++(*sol_num));
    x = 0;
    while (x < n)
    {
        y = 0;
        while (y < n)
        {
            printf(" %c ", table[x][y]);
            y++;
        }
        printf("\n");
        x++;
    }
}

void    ft_queens_coronation(int n, char table[n][n], int *board)
{
    int col;

    col = 0;
    while (col < n)
    {
        table[board[col]][col] = 'Q';
        col++;
    }
}

void    ft_print_table(int n, int *board, int *sol_num)
{
    char    table[n][n];
    int     x;
    int     y;

    x = 0;
    while (x < n)
    {
        y = 0;
        while (y < n)
        {
            table[x][y] = '.';
            y++;
        }
        x++;
    }
    ft_queens_coronation(n, table, board);
    ft_play_chess(n, table, sol_num);
}

void    ft_queen_backtracking(int *board, int n, int col, int row, int *sol_num)
{
    if (col == n)
    {
        ft_print_table(n, board, sol_num);
        return ;
    }
    row = 0;
    while (row < n)
    {
        if (ft_safe_cell(board, col, row))
        {
            board[col] = row;
            ft_queen_backtracking(board, n, col + 1, row, sol_num);
        }
        row++;
    }
}

void     ft_n_queens_puzzle(int n)
{
    int board[n];
    int col;
    int row;
    int sol_num;
    int i;

    i = 0;
    while (i < n)
    {
        board[i] = 0;
        i++;
    }
    col = 0;
    row = 0;
    sol_num = 0;
    ft_queen_backtracking(board, n, col, row, &sol_num);
}

char    *ft_strdup(char *src)
{
    char    *dup;
    int     i;
    int     src_len;

    if (!src)
        return (NULL);
    src_len = ft_strlen(src);
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = 0;
    return (dup);
}

int     *ft_range(int min, int max)
{
    int *range;
    int i;
    int size;

    if (min >= max)
        return (NULL);
    size = max - min;
    range = (int *)malloc(sizeof(int) * size);
    if (!range)
        return (0);
    i = 0;
    while (i < size)
    {
        range[i] = min + i;
        i++;
    }
    return (range);
}

int     ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int size;

    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    size = max - min;
    *range = (int *)malloc(sizeof(int) * size);
    if (!range)
        return (-1);
    i = 0;
    while (i < size)
    {
        (*range)[i] = min + i;
        i++;
    }
    return (size);
}

void    ft_strjoin_aux(char *str, char ** strs, int size, char *sep)
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