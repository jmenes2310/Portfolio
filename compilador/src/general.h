/* En los archivos de cabecera (header files) (*.h) poner DECLARACIONES (evitar DEFINICIONES) de C, así como directivas de preprocesador */
/* Recordar solamente indicar archivos *.h en las directivas de preprocesador #include, nunca archivos *.c */

#define YYLTYPE YYLTYPE
#include "model.h"
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;

#define INICIO_CONTEO_LINEA 1
#define INICIO_CONTEO_COLUMNA 1

void pausa(void);
void inicializarUbicacion(void);
void reinicializarUbicacion(void);

void imprimirFunciones(TablaSimbolos ts);
void imprimirSentencias(Simbolo *listaSentencias);
void imprimirErrores(Simbolo *listaErrores);
void imprimirVariablesSimples(TablaSimbolos ts);

void procesarVariableSimple(char *tipo, char *nombre, int linea, TablaSimbolos* ts);
void procesarFuncion(char *tipo, char* tipoDato, char *nombre, Argumento *argumentos, int linea, TablaSimbolos* ts);
void procesarSentencia(Simbolo **listaSentencias, char *tipo, char *nombre, int linea);
void procesarError(Simbolo **listaErrores, char *tipo, int linea, int columna);
