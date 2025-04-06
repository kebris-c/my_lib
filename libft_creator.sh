# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/06 13:33:53 by kebris-c          #+#    #+#              #
#    Updated: 2025/04/06 16:18:15 by kebris-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

LIB_NAME="libft"
HEADER_DIR="$HOME/.local/includes"
LIB_DIR="$HOME/.local/srcs"

# Check if libft.c exists in the current directory
if [ ! -f "$LIB_NAME.c" ]; then
    echo "❌ Error: '$LIB_NAME.c' not found in the current directory."
    exit 1
fi

# Create necessary directories if they don't exist
mkdir -p "$HEADER_DIR"
mkdir -p "$LIB_DIR"

# Copy headers from ~/Desktop/libs/
if compgen -G "$HOME/Desktop/libs/*.h" > /dev/null; then
    rm -f "$HEADER_DIR"/*.h
    mv "$HOME/Desktop/libs/"*.h "$HEADER_DIR/"
    echo "✅ Header files movied to $HEADER_DIR"
else
    echo "⚠️  No header files found in $HOME/Desktop/libs/, skipping copy."
fi

# Ask user for the library type to build
echo "Which type of library do you want to create?"
select TYPE in "Shared (.so)" "Static (.a)"; do
    case $REPLY in
        1)
            echo "🔧 Compiling shared library..."
            gcc -shared -fPIC $LIB_NAME.c -o "$LIB_DIR/$LIB_NAME.so"
            if [ $? -eq 0 ]; then
                echo "✅ Shared library created: $LIB_DIR/$LIB_NAME.so"
            else
                echo "❌ Failed to compile the shared library"
            fi
            break
            ;;
        2)
            echo "🔧 Compiling static library..."
            gcc -c $LIB_NAME.c -o $LIB_NAME.o
            if [ $? -ne 0 ]; then
                echo "❌ Failed to compile $LIB_NAME.o"
                exit 1
            fi
            ar rcs "$LIB_DIR/$LIB_NAME.a" $LIB_NAME.o
            rm -f $LIB_NAME.o
            echo "✅ Static library created: $LIB_DIR/$LIB_NAME.a"
            break
            ;;
        *)
            echo "❗ Invalid option. Please select 1 or 2."
            ;;
    esac
done

# Reminder for environment setup
echo -e "\n📌 Don't forget to add the following lines to your ~/.bashrc or ~/.zshrc:"
echo "export C_INCLUDE_PATH=\$HOME/.local/include:\$C_INCLUDE_PATH"
echo "export LIBRARY_PATH=\$HOME/.local/lib:\$LIBRARY_PATH"
echo "export LD_LIBRARY_PATH=\$HOME/.local/lib:\$LD_LIBRARY_PATH"
echo -e "\n✅ Perfect! Now you can compile every program without to use "-I" or "-L" with your own library by using:"
echo "gcc -o <your_program> main.c -l($LIB_NAME)"