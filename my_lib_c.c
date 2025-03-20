#include "my_lib.h"

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
    int base_len;
    int pos;
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
    base_len = ft_strlen(base);
    while (nbr[i])
    {
        pos = ft_base_pos(nbr[i], base);
        if (pos == -1)
            return (0);
        re = re * base_len + pos;
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