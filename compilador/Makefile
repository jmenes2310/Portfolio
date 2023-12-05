# Detectar el sistema operativo
ifeq ($(OS),Windows_NT)
	# Comandos para Windows
    EXECUTABLE = ejecutable
    CC = gcc
    CFLAGS = -o
    LIBRARIES = 
else
# Comandos para Linux
	EXECUTABLE = ejecutable
    CC = gcc
    CFLAGS = -o
    LIBRARIES = -lfl -lm
    
endif
#llamo a bison para que me cree el archivo .tab.c
tp3.tab.c: tp3.y
	bison -d tp3.y
#llamo a bison para que me cree el archivo .tab.h
tp3.tab.h: tp3.y
	bison -d tp3.y
#llamo a flex para que cree el archivo lex.yy.c
lex.yy.c: tp3.l
	flex tp3.l
#a partir de todos los archivos antes creados y de mi codigo C compilo y creo mi ejecutable
ejecutable: tp3.tab.c lex.yy.c src/general.c src/general.h src/utils.c src/utils.h src/model.c src/model.h
	$(CC) $(CFLAGS) $(EXECUTABLE) tp3.tab.c lex.yy.c src/general.c src/general.h src/utils.c src/utils.h src/model.c src/model.h src/validaciones.c src/validaciones.h $(LIBRARIES)
