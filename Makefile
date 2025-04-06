# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/06 16:17:55 by kebris-c          #+#    #+#              #
#    Updated: 2025/04/06 16:17:57 by kebris-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
NAME = Libft.a
CREATOR_SCRIPT = libft_creator.sh
CREATOR_FLAG = .creator_done

all: check_creator $(NAME)

check_creator:
ifeq ($(wildcard $(CREATOR_FLAG)),)
    @echo "Running $(CREATOR_SCRIPT) to set up the project..."
    @bash $(CREATOR_SCRIPT)
    @touch $(CREATOR_FLAG)
endif

$(NAME): $(OBJ)
    ar rcs $(NAME) $(OBJ)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)
    rm -f $(CREATOR_FLAG)

re: fclean all

.PHONY: all clean fclean re check_creator