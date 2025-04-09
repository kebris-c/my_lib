/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:26:07 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/09 15:58:34 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv)
{
    const char  *ERR_MSG;
    int         option_index;
    int         i;
    size_t      bytes_read;

    ERR_MSG = "Error: Invalid number of arguments.\nUsage:\n\t\tft_tail"
        " <filename>\n\t\tft_tail -c <N> <filename>\n";
    if (argc != 2 || argc != 4)
        ft_putstr(ERR_MSG, 2);
    else
    {
        if (argc == 2)
        {
            if (ft_tail(argv[1]) == -1)
                return (1);
        }
        else
        {
            option_index = 0;
            bytes_read = ft_parse_option_c(argc, argv, &option_index);
            if (ft_tail(argv[2], argv[3]) == -1)
                return (1);
        }
        return (0);
    }
    return (1);
}

static void ft_print_err(char *program_name, char *file_name, char *err_msg);
{
    ft_putstr(program_name, 2);
    ft_putstr(": ", 2);
    ft_putstr(file_name, 2);
    ft_putstr(err_msg, 2);
    ft_putchar('\n', 2);
}

#include <stdlib.h>
#include <unistd.h>

static void ft_display_final(int total_size, int bytes_to_read, char *content)
{
    int start_pos;

    start_pos = total_size - bytes_to_read;
    if (start_pos < 0)
        start_pos = 0;
    ft_putstr(content + start_pos, 1);
    free(content);
}

static void    ft_display_aux(char *content, int *total_size, char *tmp, int bytes_read, char *buffer)
{
    int start_pos;

    start_pos = 0;
    if (content)
    {
        while (start_pos < *total_size)
            tmp[start_pos] = content[start_pos++];
        free(content);
        start_pos = 0;
    }
    while (start_pos < bytes_read)
        tmp[*total_size + start_pos] = buffer[start_pos++];
    content = tmp;
    *total_size += bytes_read;
}

static void	ft_display_file_tail(int fd, int bytes_to_read, int total_size)
{
	char	buffer[1024];
	char	*content;
	char	*tmp;
	int		bytes_read;

    content = NULL;
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
        if (bytes_read == -1)
        {
            if (content)
                free(content);
            return ;
        }
		tmp = (char *)malloc(sizeof(char) * (total_size + bytes_read));
		if (!tmp)
		{
            if (content)
                free(content);
			return ;
		}
        ft_display_aux(content, &total_size, tmp, bytes_read, buffer);
	}
	if (!content)
		return ;
    ft_display_final(total_size, bytes_to_read, content);
}

static void ft_process_file(char *program_name, char *file_name, int bytes_to_read)
{
	int	fd;
    int total_size;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
        ft_print_err(program_name, file_name, strerror(errno));
    else
    {
        total_size = 0;
        ft_display_file_tail(fd, bytes_to_read, total_size);
        close(fd);
    }
}

static int  ft_parse_option_c(int argc, char **argv, int *option_index)
{
	int	    i;
	size_t  bytes;

	i = 1;
    bytes = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == 'c')
		{
			if (argv[i][2] != '\0')
				bytes = ft_atoi(&argv[i][2]);
			else if (i + 1 < argc)
			{
				bytes = ft_atoi(argv[i + 1]);
				*option_index = i + 1;
			}
			else
				return (-1);
			return (bytes);
		}
		i++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int	        bytes_to_read;
	int	        option_index;
	int	        i;
    const char  *ERR_MSG;

    ERR_MSG = "Error: Invalid or missing -c option\n";
	option_index = 0;
	bytes_to_read = ft_parse_option_c(argc, argv, &option_index);
	if (bytes_to_read < 0)
	{
		ft_putstr(ERR_MSG, 2);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (i != option_index && i != option_index - 1
            && !(argv[i][0] == '-' && argv[i][1] == 'c'))
		{
			if (argc - option_index - (option_index > 0 ? 1 : 0) > 2)
			{
				ft_putstr("\n==> ", 1);
				ft_putstr(argv[i], 1);
				ft_putstr(" <==\n");
			}
			ft_process_file(argv[0], argv[i], bytes_to_read);
		}
		i++;
	}
	if (i == 1 || (argc == 3 && option_index == 2)
        || (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'c'))
		ft_display_file_tail(0, bytes_to_read);
	return (0);
}