/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_queens_puzzle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:41:41 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/06 16:42:10 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool     ft_safe_cell(int *board, int col, int row)
{
    int prev_col;
    int prev_row;

    prev_col = 0;
    while (prev_col < col)
    {
        prev_row = board[prev_col];
        if (prev_row == row || prev_row - prev_col == row - col
            || prev_row + prev_col == row + col)
            return (FALSE);
        prev_col++;
    }
    return (TRUE);
}

static void    ft_play_chess(int n, char table[n][n], int *sol_num)
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

static void    ft_queens_coronation(int n, char table[n][n], int *board)
{
    int col;

    col = 0;
    while (col < n)
    {
        table[board[col]][col] = 'Q';
        col++;
    }
}

static void    ft_print_table(int n, int *board, int *sol_num)
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

static void    ft_queen_backtracking(int *board, int n, int col, int row, int *sol_num)
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
