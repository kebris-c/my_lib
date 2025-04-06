#ifndef LIBFT_H
#define LIBFT_H

#define ATOI_BASE_ERROR INT_MIN

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "ft_abs.h"
#include "ft_boolean.h"
#include "ft_point.h"
#include "ft_stock_str.h"

void                ft_putchar(char c);
void                ft_putnbr(int nbr);
void                ft_putnbr_base(int nbr, char *base);
void                ft_putstr(char *str);
void                ft_print_combn_aux(char *nb);
void                ft_print_combn_aux2(char *nb);
void                ft_print_combn(int n);
void                ft_swap(int *a, int *b);
void                ft_div_mod(int a, int b, int *div, int *mod);
void                ft_ultimate_div_mod(int *a, int *b);
void                ft_rev_int_tab(int *tab, int size);
void                ft_sort_int_tab(int *tab, int size);
void                ft_putstr_non_printable(char *str);
void                ft_print_addr(unsigned long addr, unsigned int size);
void                ft_print_memory_content(void *addr, unsigned int size, char *base);
void                ft_print_ascii(unsigned char *ptr, unsigned int size);
void                *ft_print_memory(void *addr, unsigned int size);
void                ft_play_chess(int n, char table[n][n], int *sol_num);
void                ft_queens_coronation(int n, char table[n][n], int *board);
void                ft_print_table(int n, int *board, int *sol_num);
void                ft_queen_backtracking(int *board, int n, int col, int row, int *sol_num);
void                ft_n_queens_puzzle(int n);
void                ft_strjoin_aux(char *str, char ** strs, int size, char *sep);
void                ft_set_point(t_point *point);
void                ft_show_tab(struct s_stock_str *par);
char                *ft_strcpy(char *str);
char                *ft_strncpy(char *str);
char                *ft_strupcase(char *str);
char                *ft_strlowcase(char *str);
char                *ft_strdup(char *src);
char                *ft_strjoin(int size, char **strs, char *sep);
char                *ft_itoa_base(int nb, char *base);
char                *ft_itoa(int nb);
char                *ft_strdup_char(char c);
char                *ft_convert_base(char *nbr, char *base_from, char *base_to);
char                **ft_split(char *str, char *charset);
int                 ft_atoi(char *str);
int                 ft_strlen(char *str);
int                 ft_base_checker(char *base);
int                 ft_base_pos(char nb, char *base);
int                 ft_atoi_base(char *nb, char *base);
int                 ft_str_is_alpha(char *str);
int                 ft_str_is_numeric(char *str);
int                 ft_str_is_lowercase(char *str);
int                 ft_str_is_uppercase(char *str);
int                 ft_str_is_printable(char *str);
int                 ft_strcmp(char *s1, char *s2);
int                 ft_strlcpy(char *dest, char *src, int size);
int                 ft_iterative_factorial(int nb);
int                 ft_recursive_factorial(int nb);
int                 ft_iterative_power(int nb, int power);
int                 ft_recursive_power(int nb, int power);
int                 ft_fibonacci(int index);
int                 ft_sqrt(int nb);
int                 ft_is_prime(int nb);
int                 ft_find_next_prime(int nb);
int                 *ft_range(int min, int max);
int                 ft_ultimate_range(int **range, int min, int max);
int                 ft_itoa_len(int nb, int base_len);
int                 ft_free_matrix(void **arr, int i);
int                 ft_free_arr(void *arr);
int                 ft_split_len(char *str, char *charset);
int                 ft_split_aux_mem(int i, int j, char **split, char *str, char *charset);
int                 ft_split_aux(char **split, char *str, char *charset);
t_bool              ft_incorrect_base(char *base);
t_bool              ft_valid_number(char *nbr, char *base);
t_bool              ft_safe_cell(int *board, int col, int row);
t_bool              ft_is_sep(char c, char *charset);
struct s_stock_str  *ft_strs_to_tab(int ac, char **av);

#endif