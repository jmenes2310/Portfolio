#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "utils.h"
#include "model.h"

bool existeSimbolo(TablaSimbolos ts, char *identificador)
{
    Simbolo *aux = ts.variables;
    while (aux != NULL)
    {
        if (strcmp(aux->nombre, identificador) == 0)
        {
            return true;
        }
        aux = aux->siguiente;
    }

    aux = ts.funciones;
    while (aux != NULL)
    {
        if (strcmp(aux->nombre, identificador) == 0)
        {
            return true;
        }
        aux = aux->siguiente;
    }

    return false;
}

void eliminarSimbolos(TablaSimbolos *ts, int linea)
{
    Simbolo *aux = ts->variables;
    Simbolo *anterior = NULL;
    while (aux != NULL)
    {
        if (aux->linea == linea)
        {
            if (anterior == NULL)
            {
                ts->variables = aux->siguiente;
            }
            else
            {
                anterior->siguiente = aux->siguiente;
            }
            free(aux->nombre);
            free(aux->tipo);
            free(aux);
            return;
        }
        anterior = aux;
        aux = aux->siguiente;
    }

    aux = ts->funciones;
    anterior = NULL;
    while (aux != NULL)
    {
        if (aux->linea == linea)
        {
            if (anterior == NULL)
            {
                ts->funciones = aux->siguiente;
            }
            else
            {
                anterior->siguiente = aux->siguiente;
            }
            free(aux->nombre);
            free(aux->tipo);
            free(aux);
            return;
        }
        anterior = aux;
        aux = aux->siguiente;
    }
}

Simbolo *obtenerSimbolo(TablaSimbolos ts, char *identificador)
{
    Simbolo *aux = ts.variables;
        while (aux != NULL)
    {
                if (strcmp(aux->nombre, identificador) == 0)
        {
                        return aux;
        }
        aux = aux->siguiente;
    }
aux = ts.funciones;
    while (aux != NULL)
    {
        if (strcmp(aux->nombre, identificador) == 0)
        {
            return aux;
        }
        aux = aux->siguiente;
    }

    return NULL;
}

Simbolo *obtenerUltimo(Simbolo *tokens)
{
    Simbolo *aux = tokens;
    while (aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }
    return aux;
}

void insertarOrdenado(Simbolo **inicio, Simbolo *nuevoToken, int (*comparar)(const Simbolo *, const Simbolo *))
{
    Simbolo *actual = *inicio;
    Simbolo *anterior = NULL;

    while (actual != NULL && comparar(actual, nuevoToken) < 0)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (anterior == NULL)
    {
        nuevoToken->siguiente = *inicio;
        *inicio = nuevoToken;
    }
    else
    {
        anterior->siguiente = nuevoToken;
        nuevoToken->siguiente = actual;
    }
}

int cantidadSimbolos(Simbolo *tokens)
{
    int cantidad = 0;
    Simbolo *aux = tokens;
    while (aux != NULL)
    {
        cantidad++;
        aux = aux->siguiente;
    }
    return cantidad;
}

int cantidadArgumentos(Argumento *argumentos)
{
    int cantidad = 0;
    Argumento *aux = argumentos;
    while (aux != NULL)
    {
        cantidad++;
        aux = aux->siguiente;
    }
    return cantidad;
}

Simbolo *nuevoSimbolo(char *nombre, char *tipo,char* tipoDato, Argumento *argumentos, int linea, int columna)
{
    Simbolo *simboloNuevo = malloc(sizeof(Simbolo));
    if (simboloNuevo == NULL)
    {
        printf("No se pudo reservar memoria para el simboloNuevo\n");
        return NULL;
    }

    simboloNuevo->nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
    strcpy(simboloNuevo->nombre, nombre);

    simboloNuevo->tipo = malloc(sizeof(char) * (strlen(tipo) + 1));
    strcpy(simboloNuevo->tipo, tipo);

    simboloNuevo->tipoDato = malloc(sizeof(char) * (strlen(tipoDato) + 1));
    strcpy(simboloNuevo->tipoDato, tipoDato);

    simboloNuevo->argumentos = NULL;
    if (argumentos != NULL)
    {
        simboloNuevo->argumentos = argumentos;
    }
    simboloNuevo->linea = linea;
    simboloNuevo->columna = columna;

    return simboloNuevo;
}

void liberarMemoriaSimbolos(Simbolo *simbolos)
{
    Simbolo *aux = simbolos;
    while (aux != NULL)
    {
        
        Simbolo *siguiente = aux->siguiente;
        free(aux->nombre);
        free(aux->tipo);

        Argumento *auxArgumentos = aux->argumentos;
        while (auxArgumentos != NULL)
        {
            Argumento *siguiente = auxArgumentos->siguiente;
            free(auxArgumentos->nombre);
            free(auxArgumentos->tipo);
            free(auxArgumentos);
            auxArgumentos = siguiente;
        }

        free(aux);
        aux = siguiente;
    }
}

void liberarMemoriaTS(TablaSimbolos ts)
{
    liberarMemoriaSimbolos(ts.variables);
    liberarMemoriaSimbolos(ts.funciones);
}