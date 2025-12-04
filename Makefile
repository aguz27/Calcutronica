################################################################
# INFORMACION DEL PROYECTO                                     #
################################################################
AUTHOR      = Zanetti Agustin
PROJECT     = Calcutronica
YEAR        = 2025
VERSION     = 1.0

################################################################
# COMPILADOR Y FLAGS                                           #
################################################################
CC          = gcc
# CFLAGS:
# -Wall: Muestra advertencias
# -g: debug
# -Iinc: Busca archivos .h en la carpeta inc
CFLAGS      = -Wall -g -Iinc

# Directorios
SRC_DIR     = src
OBJ_DIR     = obj
BIN_DIR     = bin
INC_DIR     = inc

# Nombre del ejecutable final
EXEC_NAME   = Calcutronica
EXEC        = $(BIN_DIR)/$(EXEC_NAME)

################################################################
# FUENTES Y OBJETOS (AUTOMATICO)                               #
################################################################
SRCS        = $(wildcard $(SRC_DIR)/*.c)
OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
################################################################
# REGLAS (TARGETS)                                             #
################################################################
.PHONY: all clean new run
all: $(EXEC)

$(EXEC): $(OBJS)
	@echo ''
	@echo '--> Enlazando y creando ejecutable: $@'
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo '--> Compilacion exitosa! Ejecuta con: ./$(EXEC)'

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@echo '--> Compilando objeto: $@'
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

################################################################
# UTILIDADES                                                   #
################################################################

# Limpiar archivos generados
clean:
	@echo '--> Limpiando archivos temporales y ejecutables...'
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo '--> Limpieza terminada.'

# Reconstruir desde cero
new: clean all

# Atajo para compilar y ejecutar de una vez
run: all
	@echo '--> Ejecutando $(EXEC_NAME)...'
	@./$(EXEC)