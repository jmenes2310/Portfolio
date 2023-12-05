#ifndef UTILS
#define UTILS
#include <stdbool.h>
#include "model.h"

bool existeSimbolo(TablaSimbolos ts, char *identificador);

Simbolo *obtenerSimbolo(TablaSimbolos ts, char *identificador);
Simbolo *obtenerUltimo(Simbolo *tokens);

void insertarOrdenado(Simbolo **inicio, Simbolo *nuevoToken, int (*comparar)(const Simbolo *, const Simbolo *));
int cantidadSimbolos(Simbolo *tokens);
int cantidadArgumentos(Argumento *argumentos);
Simbolo *nuevoSimbolo(char *nombre, char *tipo, char* tipoDato, Argumento *argumentos, int linea, int columna);
void liberarMemoriaSimbolos(Simbolo *simbolos);
void liberarMemoriaTS(TablaSimbolos ts);
void eliminarSimbolos(TablaSimbolos *ts, int linea);

#endif
