#ifndef MY_LIB_H
#define MY_LIB_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <string.h>

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size);
void            ft_putchar(char c);
void            ft_putnbr(int nbr);
void            ft_putnbr_base(int nbr, char *base);
void            ft_putstr(char *str);
void            ft_print_combn_aux(char *nb);
void            ft_print_combn_aux2(char *nb);
void            ft_print_combn(int n);
void            ft_swap(int *a, int *b);
void            ft_div_mod(int a, int b, int *div, int *mod);
void            ft_ultimate_div_mod(int *a, int *b);
void            ft_rev_int_tab(int *tab, int size);
void            ft_sort_int_tab(int *tab, int size);
void            ft_putstr_non_printable(char *str);
void            ft_print_addr(unsigned long addr, unsigned int size);
void            ft_print_memory_content(void *addr, unsigned int size, char *base);
void            ft_print_ascii(unsigned char *ptr, unsigned int size);
void            *ft_print_memory(void *addr, unsigned int size);
char            *ft_strcpy(char *str);
char            *ft_strncpy(char *str);
char            *ft_strupcase(char *str);
char            *ft_strlowcase(char *str);
int             ft_atoi(char *str);
int             ft_strlen(char *str);
int             ft_base_checker(char *base);
int             ft_base_pos(char nb, char *base);
int             ft_atoi_base(char *nb, char *base);
int             ft_str_is_alpha(char *str);
int             ft_str_is_numeric(char *str);
int             ft_str_is_lowercase(char *str);
int             ft_str_is_uppercase(char *str);
int             ft_str_is_printable(char *str);

#endif