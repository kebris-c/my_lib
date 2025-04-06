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
CFLAGS = -Wall -Wextra -Werror
NAME = libft
SRC = $(NAME).c
STATIC_LIB = $(NAME).a
SHARED_LIB = $(NAME).so
LIB_DIR = $(HOME)/.local/srcs/
CREATOR_SCRIPT = libft_creator.sh
CREATOR_FLAG = .creator_done

all: help_hint check_library

help_hint:
	@echo "Tip: Run 'make help' to see available commands."
	@echo ""

check_library:
	@echo "Checking for existing libraries...";
	@if [ ! -f $(CREATOR_FLAG) ]; then \
		if [ ! -f $(LIB_DIR)$(STATIC_LIB) ] && [ ! -f $(LIB_DIR)$(SHARED_LIB) ]; then \
			echo "No library found. Running $(CREATOR_SCRIPT)..."; \
			bash $(CREATOR_SCRIPT) && touch $(CREATOR_FLAG); \
		else \
			echo "Libraries exist. Marking creator as done."; \
			touch $(CREATOR_FLAG); \
		fi; \
	else \
		echo "Creator script has already been run."; \
		if [ -f $(LIB_DIR)$(STATIC_LIB) ]; then \
			echo "Static library $(STATIC_LIB) exists at $(LIB_DIR)"; \
		fi; \
		if [ -f $(LIB_DIR)$(SHARED_LIB) ]; then \
			echo "Shared library $(SHARED_LIB) exists at $(LIB_DIR)"; \
		fi; \
	fi
	@echo "Library check complete.";

compile_static:
	@echo "Creating static library..."
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(LIB_DIR)$(STATIC_LIB) $(NAME).o
	rm -f $(NAME).o
	@echo "✅ Static library created: $(LIB_DIR)$(STATIC_LIB)"

compile_shared:
	@echo "Creating shared library..."
	$(CC) $(CFLAGS) -shared -fPIC $(SRC) -o $(LIB_DIR)$(SHARED_LIB)
	@echo "✅ Shared library created: $(LIB_DIR)$(SHARED_LIB)"

clean:
	@echo "Cleaning object files..."
	rm -f $(NAME).o

fclean: clean
	@echo "Removing libraries..."
	rm -f $(LIB_DIR)$(STATIC_LIB) $(LIB_DIR)$(SHARED_LIB)
	rm -f $(CREATOR_FLAG)

recreate: fclean
	@echo "Recreating libraries with $(CREATOR_SCRIPT)..."
	bash $(CREATOR_SCRIPT)

help:
	@echo "Makefile for creating static and shared libraries."
	@echo "Usage:"
	@echo "  make all               - Check and create libraries if needed."
	@echo "  make compile_static    - Create static library manually."
	@echo "  make compile_shared    - Create shared library manually."
	@echo "  make clean             - Remove object files."
	@echo "  make fclean            - Remove libraries and object files."
	@echo "  make recreate          - Recreate libraries using $(CREATOR_SCRIPT)."
	@echo "  make re                - Clean and recreate libraries."
	@echo "  make help              - Display this help message."

re: fclean all

.PHONY: all clean fclean re check_library compile_static compile_shared recreate help help_hint