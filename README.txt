Para implementar las librerías personalizadas en un entorno con unas rutas que pueda usar siempre debo seguir los siguientes pasos:

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Si quieres hacer que tu librería sea accesible globalmente sin usar sudo, la mejor opción es instalarla en tu directorio de usuario y configurar tu entorno para que la encuentre automáticamente.
📌 Método: Instalar la librería en $HOME/.local
 Este método hace que cualquier programa pueda usar #include "my_lib.h" sin mover archivos manualmente.

1️⃣ Crear estructura de instalación
 mkdir -p $HOME/.local/include   # Para headers (.h)
 mkdir -p $HOME/.local/lib       # Para librerías (.a y .so)
2️⃣ Copiar los archivos
 cp my_lib.h $HOME/.local/include/
 gcc -shared -o $HOME/.local/lib/libmy_lib.so -fPIC my_lib.c
3️⃣ Configurar variables de entorno
 Añade estas líneas a tu ~/.bashrc o ~/.zshrc para que sean permanentes:

 export C_INCLUDE_PATH=$HOME/.local/include:$C_INCLUDE_PATH
 export LIBRARY_PATH=$HOME/.local/lib:$LIBRARY_PATH
 export LD_LIBRARY_PATH=$HOME/.local/lib:$LD_LIBRARY_PATH

 Después, aplica los cambios:
 
 source ~/.bashrc      /or/      source ~/.zshrc (si usas zsh)

🚀 Usarlo en cualquier proyecto
 Ahora, cuando compiles cualquier programa, simplemente haz:

 gcc -o my_program main.c -lmy_lib
🔹 Sin necesidad de -I ni -L, porque el compilador ya sabe dónde buscar.
🔹 Funciona para cualquier proyecto sin copiar archivos.

🔥 Ventajas de este método
✅ No necesita sudo
✅ Accesible en cualquier proyecto sin mover archivos
✅ Persistente, incluso tras reiniciar
✅ Compatible con librerías estáticas (.a) y dinámicas (.so)

💡 Ahora puedes usar my_lib.h y libmy_lib.so globalmente sin complicaciones. 🚀


--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Si ya usaste el método de instalación en ~/.local, aquí está lo que debes incluir y cómo:

📂 Contenido de ~/.local/include/
 Este directorio debe contener solo los headers (.h) de tu librería.

📌 Pasos:

 cp my_lib.h $HOME/.local/include/
📌 Ejemplo de my_lib.h:

 #ifndef MY_LIB_H
 #define MY_LIB_H

 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stddef.h>
 #include <fcntl.h>
 #include <string.h>

 // Prototipos de las funciones
 int ft_atoi(char *str);
 int ft_strlen(char *str);
 void ft_putchar(char c);
 void ft_putnbr(int nbr);
 void ft_swap(int *a, int *b);

 #endif
🔹 NO debe contener implementaciones de funciones, solo prototipos y #include necesarios.

📂 Contenido de ~/.local/lib/
 Aquí deben estar las compilaciones de la librería en forma de archivo estático (.a) o dinámico (.so).

📌 Opción 1: Librería Estática (.a)
 gcc -c my_lib.c -o my_lib.o
 ar rcs $HOME/.local/lib/libmy_lib.a my_lib.o
 Esto crea libmy_lib.a, que se enlaza en la compilación.

📌 Opción 2: Librería Dinámica (.so)
 gcc -shared -o $HOME/.local/lib/libmy_lib.so -fPIC my_lib.c
 Esto crea libmy_lib.so, que se carga en tiempo de ejecución.

📌 Configuración Final
 Para que el compilador encuentre la librería automáticamente, asegúrate de tener estas variables en ~/.bashrc o ~/.zshrc:

 export C_INCLUDE_PATH=$HOME/.local/include:$C_INCLUDE_PATH
 export LIBRARY_PATH=$HOME/.local/lib:$LIBRARY_PATH
 export LD_LIBRARY_PATH=$HOME/.local/lib:$LD_LIBRARY_PATH
 
 Y aplica los cambios:

 source ~/.bashrc  # O source ~/.zshrc si usas Zsh

🚀 Cómo usar la librería en un proyecto
 1️⃣ Enlazar la librería estática (.a):

 gcc -o my_program main.c -lmy_lib
 2️⃣ Enlazar la librería dinámica (.so):

 gcc -o my_program main.c -lmy_lib
 (Si da error al ejecutar, recarga LD_LIBRARY_PATH con export LD_LIBRARY_PATH=$HOME/.local/lib).

🔥 Ventajas
✅ No necesitas copiar archivos a cada proyecto
✅ No usas sudo
✅ Compatible con cualquier compilación (gcc, clang, etc.)
✅ Puedes actualizar la librería sin modificar cada proyecto

Ahora, cualquier código en C podrá incluir #include "my_lib.h" y enlazar con -lmy_lib sin preocuparse por rutas. 🚀

📌						Makefile Description:
 This Makefile is designed to work with a script named libft_creator.sh
 that sets up the project. The script should create the necessary files
 and directories, and the Makefile will handle the compilation of the
 source files into a static library named libft.a.
 The check_creator target ensures that the script is run only once,
 and the .creator_done file is used to track whether the script has
 already been executed.
 The script should be placed in the same directory as this Makefile.
 The script should also handle the creation of the include directory
 and the srcs directory, and any other necessary setup for the project.
 The script should also ensure that the source files are placed in the
 srcs directory and the header files are placed in the include directory.
 The script should also ensure that the Makefile is placed in the root
 directory of the project.
							How to use it:
 Make sure the libft_creator.sh file is in the same directory as the Makefile.
 Run make as usual. If the script has not been executed before,
 it will run automatically. If you need to force the script to run again,
 use make fclean followed by make.
