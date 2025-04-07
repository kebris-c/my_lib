CC = gcc
CFLAGS = -Wall -Wextra -Werror
PROJECT = project
NAME = libft
SRC = $(NAME).c
STATIC_LIB = $(NAME).a
SHARED_LIB = $(NAME).so
LIB_DIR = $(HOME)/.local/srcs/
CREATOR_SCRIPT = libft_creator.sh
CREATOR_FLAG = .creator_done
NORMINETTE = norminette
FTS = *.c

all: $(NAME) ask_to_compile

$(NAME): help_hint check_library

help_hint:
	@echo "Tip: Run 'make help' to see available commands."
	@echo ""

check_library:
	@echo "Checking for existing libraries...";
	@if [ ! -f $(CREATOR_FLAG) ]; then \
		if [ ! -f $(LIB_DIR)$(STATIC_LIB) ] && [ ! -f $(LIB_DIR)$(SHARED_LIB) ]; then \
			echo "No library found. Running $(CREATOR_SCRIPT)..."; \
			sed -i 's/\r$//' libft_creator.sh; \
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
	fi;
	@echo "Library check complete.";

ask_to_compile:
	@echo "Do you want to compile any project.c on the current directory? (y/n)"; \
	read answer; \
	answer=$$(echo $$answer | tr -d '[:space:]'); \
	if [ "$$answer" = "y" ]; then \
		$(MAKE) --no-print-directory $(PROJECT); \
	elif [ "$$answer" = "n" ]; then \
		echo "⏭️  Skipping compilation."; \
	else \
		printf "❌ Invalid answer: '$$answer'. I will ask again.\n"; \
		$(MAKE) --no-print-directory ask_to_compile; \
	fi;

$(PROJECT):
	@echo "Compiling project..."
	$(NORMINETTE) $(FTS)
	$(CC) $(CFLAGS) -c *.c -o $(PROJECT)
	@echo "✅ Project compiled: $(PROJECT)"
	@echo "If you want to execcute the project, run './$(PROJECT)' or 'make exec'"

force:
	@echo "Forcing the compile of the project..."
	$(CC) -c $(FTS) -o $(PROJECT)
	@echo "✅ Project compiled: $(PROJECT)"
	@echo "If you want to execcute the project, run './$(PROJECT)' or 'make exec'"

norm:
	@echo "Running norminette..."
	$(NORMINETTE) $(FTS)
	@echo "✅ Norminette check complete."

exec:
	@echo "Executing project..."
	./$(PROJECT)
	@echo "✅ Project executed."

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
	rm -f $(PROJECT)

recreate: fclean
	@echo "Recreating libraries with $(CREATOR_SCRIPT)..."
	bash $(CREATOR_SCRIPT)

re: fclean all

help:
	@echo "Makefile for creating static and shared libraries."
	@echo "Usage:"
	@echo "  make all               - Check and create libraries if needed and execute the $(PROJECT)."
	@echo "  make compile_static    - Create static library manually."
	@echo "  make compile_shared    - Create shared library manually."
	@echo "  make clean             - Remove object files."
	@echo "  make fclean            - Remove libraries, object files, and the compiled project."
	@echo "  make recreate          - Recreate libraries using $(CREATOR_SCRIPT)."
	@echo "  make re                - Clean and recreate everything."
	@echo "  make force             - Force the compilation of the project."
	@echo "  make norm              - Run norminette on the source files."
	@echo "  make exec              - Execute the compiled project."
	@echo "  make help              - Display this help message."

.PHONY: all clean fclean re recreate help help_hint check_library \
compile_static compile_shared force norm exec $(NAME) $(PROJECT)
