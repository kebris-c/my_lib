#!/bin/sh

LIB_NAME="libft"
HEADER_DIR="$HOME/.local/includes/"
LIB_DIR="$HOME/.local/srcs/"
LOCAL_LIB="$HOME/Desktop/libs/srcs/*.c"
LOCAL_HEADER="$HOME/Desktop/libs/includes/*.h"
CFLAGS="-c -Wall -Werror -Wextra -g3 -fsanitize=address"
CC="gcc"

# Check if libft.c exists in its directory
if [ ! -f "$LOCAL_LIB" ]; then
    echo "❌ Error: '$LOCAL_LIB' not found in the current directory."
    exit 1
fi

# Create necessary directories if they don't exist
mkdir -p "$HEADER_DIR"
mkdir -p "$LIB_DIR"

# Copy headers from ~/Desktop/libs/includes/
if compgen -G $HOME/Desktop/libs/includes/*.h > /dev/null; then
    rm -f "$HEADER_DIR"*.h
    cp $HOME/Desktop/libs/includes/*.h "$HEADER_DIR"
    echo "✅ Header files copied to '$HEADER_DIR'"
else
    echo "⚠️  No header files found in '$HOME/Desktop/libs/includes/', skipping copy."
fi

# Ask user for the library type to build
echo "Which type of library do you want to create?"
select TYPE in "Shared (.so)" "Static (.a)"; do
    case $REPLY in
        1)
            echo "🔧 Compiling shared library..."
            $CC $CFLAGS -shared -fPIC $LOCAL_LIB -I$HOME/Desktop/libs/includes -o "$LIB_DIR/$LIB_NAME.so"
            if [ $? -eq 0 ]; then
                echo "✅ Shared library created: $LIB_DIR/$LIB_NAME.so"
            else
                echo "❌ Failed to compile the shared library"
            fi
            break
            ;;
        2)
            echo "🔧 Compiling static library..."
            $CC $CFLAGS $LOCAL_LIB -I$HOME/Desktop/libs/includes -o $LIB_NAME.o
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

# Detect shell config file
if [ -n "$ZSH_VERSION" ]; then
    SHELL_RC="$HOME/.zshrc"
elif [ -n "$BASH_VERSION" ]; then
    SHELL_RC="$HOME/.bashrc"
else
    # fallback if it can not be detected
    SHELL_RC="$HOME/.profile"
fi

# Adding if it is not exist
append_if_missing()
{
    VAR="$1"
    VALUE="$2"
    FILE="$3"
    grep -qxF "$VALUE" "$FILE" 2>/dev/null || echo "$VALUE" >> "$FILE"
}

append_if_missing "INCLUDE_PATH" "export INCLUDE_PATH=\$HOME/.local/includes:\$INCLUDE_PATH" "$SHELL_RC"
append_if_missing "C_INCLUDE_PATH" "export C_INCLUDE_PATH=\$HOME/.local/includes:\$C_INCLUDE_PATH" "$SHELL_RC"
append_if_missing "LIBRARY_PATH" "export LIBRARY_PATH=\$HOME/.local/srcs:\$LIBRARY_PATH" "$SHELL_RC"
append_if_missing "LD_LIBRARY_PATH" "export LD_LIBRARY_PATH=\$HOME/.local/srcs:\$LD_LIBRARY_PATH" "$SHELL_RC"

echo -e "\n🧩 Added config on $SHELL_RC"
echo "⚠️  Remind to reboot your terminal or execute: source $SHELL_RC"
echo -e "\n✅ Perfect! Now you can compile every program without to use "-I" or "-L" with your own library by using:"
echo "$CC $CFLAGS -o <your_program> main.c -l($LIB_NAME)"
