# Obtiene automáticamente la lista de archivos .c en el directorio actual
C_FILES := $(filter-out lex.yy.c entrada.c, $(wildcard *.c))

# Archivo de salida para tp2
SALIDA := salida.txt 

# Obtiene automáticamente la lista de archivos .l en el directorio actual
LEX_FILES := $(wildcard *.l)
LEX_C_FILES := lex.yy.c

# Nombre del archivo de salida
OUTPUT := tp2ejec

# Compilador a usar
CC := gcc

# Regla predeterminada: compila todos los archivos .c en un solo ejecutable
all: $(OUTPUT)

# Regla para compilar los archivos .l con Flex
flex_compile: $(LEX_C_FILES)

lex.yy.c: $(LEX_FILES)
	flex $(LEX_FILES)

# Regla para compilar el ejecutable
$(OUTPUT): $(C_FILES) flex_compile
	$(CC) $(C_FILES) $(LEX_C_FILES) -o $(OUTPUT)

# Regla para limpiar los archivos generados
clean:
	del $(OUTPUT) $(LEX_C_FILES) $(SALIDA)

run: $(OUTPUT)
	./tp2ejec.exe
