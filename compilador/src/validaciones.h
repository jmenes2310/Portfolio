#ifndef VALIDACIONES
#define VALIDACIONES
#include <stdbool.h>
#include "model.h"

struct text;

//Sintacticas
bool validarLvalue(char* token);

//Semanticas
void validarBinaria(TablaSimbolos ts,struct text op1, struct text op2);
bool hayDobleDeclaracion(TablaSimbolos ts, Simbolo *simbolo, int linea, int columna);
void validarVariableNoDeclarada(TablaSimbolos ts, char *identificador, int linea, int columna);
void validarInvocacionFuncion(TablaSimbolos ts, char *identificador,Argumento* args, int linea, int columna);


#endif