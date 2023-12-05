#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "model.h"

extern void yyerror(const char* message);

struct text{
    char *nombre;
    char* tipo;
} text;

//Sintacticas
bool validarLvalue(char* token)
{
    if( strcmp(token,"id") != 0)
    {
        yyerror("Error sintactico: se esperaba LValue modificable"); 
        return false;
    }
    else
        return true;
}

//Semanticas

void validarBinaria(TablaSimbolos ts,struct text op1, struct text op2)
{    
    Simbolo *operando1 = obtenerSimbolo(ts, op1.nombre);
    Simbolo *operando2 = obtenerSimbolo(ts, op2.nombre);
    char mensaje[512];


    if(operando1 && operando2)
    {
        if(strcmp(operando1->tipo, operando2->tipo) != 0 || strcmp(operando1->tipo, "char*") == 0 || strcmp(operando2->tipo, "char*") == 0)
        {
            sprintf(mensaje, "Error semantico: Los tipos de datos %s y %s no coinciden", operando1->tipo, operando2->tipo);
            yyerror(mensaje);
        }
    }
    else if(operando1)
    {
        if(strcmp(operando1->tipo,op2.tipo) != 0)
        {
            sprintf(mensaje, "Error semantico: Los tipos de datos no coinciden");
            yyerror(mensaje);
        }

    }
    else if(operando2)
    {
        if(strcmp(operando2->tipo,op1.tipo) != 0 || strcmp(op1.tipo, "char*") == 0)
        {
            sprintf(mensaje, "Error semantico: Los tipos de datos no coinciden");
            yyerror(mensaje);
        }
    }

    else if(strcmp(op1.tipo,op2.tipo) != 0)
    {
        sprintf(mensaje, "Error semantico: Los tipos de datos no coinciden");
        yyerror(mensaje);
    }
    else if(strcmp(op1.tipo, "char*") == 0 || strcmp(op2.tipo, "char*") == 0)
    {
        sprintf(mensaje, "Error semantico: No se puede realizar la operacion con el tipo de dato string");
        yyerror(mensaje);
    }
}

bool hayDobleDeclaracion(TablaSimbolos ts, Simbolo *simbolo, int linea, int columna)
{
    if (existeSimbolo(ts, simbolo->nombre))
    {
        Simbolo *aux = obtenerSimbolo(ts, simbolo->nombre);
        if (aux->linea != simbolo->linea)
        {
            char mensaje[512];
            sprintf(mensaje, "Error semantico: El identificador %s ya fue declarado en la linea %d", simbolo->nombre, aux->linea);
            yyerror(mensaje);
            return true;
            // agregarError(mensaje, linea, columna);
        }
    }
    return false;
}

void validarVariableNoDeclarada(TablaSimbolos ts, char *identificador)
{

    if (!existeSimbolo(ts, identificador))
    {
        char mensaje[1000];
        sprintf(mensaje, "Error semantico: El identificador \"%s\" no fue declarado\0", identificador);
        yyerror(mensaje);
    }
}

void validarInvocacionFuncion(TablaSimbolos ts, char *identificador,Argumento* args, int linea, int columna)
{
    Simbolo* funcion = obtenerSimbolo(ts, identificador);

    if (funcion == NULL)
    {
        // char mensaje[1000];
        // sprintf(mensaje, "Error semantico: La funcion \"%s\" no fue declarada\0", identificador);
        // yyerror(mensaje);
    }
    else 
    {

        Argumento *argumento = args;
        Argumento *argumentoFuncion = funcion->argumentos;

        if(cantidadArgumentos(argumento) != cantidadArgumentos(argumentoFuncion))
        {
            yyerror("Error semantico: La cantidad de argumentos no coincide");
        }
        else
        {
            while (argumento != NULL || argumentoFuncion != NULL)
            {
            if (strcmp(argumento->tipo, argumentoFuncion->tipo) != 0)
            {
                yyerror("Error semantico: Los tipos de los argumentos no coinciden");
            }
            argumento = argumento->siguiente;
            argumentoFuncion = argumentoFuncion->siguiente;
            }
        }

    }
}
