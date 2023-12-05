/* En los archivos (*.c) se pueden poner tanto DECLARACIONES como DEFINICIONES de C, así como directivas de preprocesador */
/* Recordar solamente indicar archivos *.h en las directivas de preprocesador #include, nunca archivos *.c */

#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "model.h"
#include "general.h"
#include "validaciones.h"

extern YYLTYPE yylloc;

//--------------------------------------------------------------
//--------------------------------------------------------------
int menorLinea(const Simbolo *token1, const Simbolo *token2)
{
    if (token1->linea - token2->linea == 0)
    {
        return -1;
    }
    return token1->linea - token2->linea;
}
//--------------------------------------------------------------
//--------------------------------------------------------------
void pausa(void)
{

    printf("Presione ENTER para continuar...\n");
    getchar();
}
//--------------------------------------------------------------
//--------------------------------------------------------------
void inicializarUbicacion(void)
{
    yylloc.first_line = yylloc.last_line = INICIO_CONTEO_LINEA;
    yylloc.first_column = yylloc.last_column = INICIO_CONTEO_COLUMNA;
}

void reinicializarUbicacion(void)
{
    yylloc.first_line = yylloc.last_line;
    yylloc.first_column = yylloc.last_column;
}
//--------------------------------------------------------------
//--------------------------------------------------------------
void imprimirVariablesSimples(TablaSimbolos ts)
{

    Simbolo *listaVariables = ts.variables;
    printf("\nVariables simples:\n");
    Simbolo *aux = listaVariables;
    while (aux != NULL)
    {
        printf("Linea %d: Tipo: %s Nombre: %s;\n", aux->linea, aux->tipo, aux->nombre);
        aux = aux->siguiente;
    }
}

void imprimirFunciones(TablaSimbolos ts)
{

    Simbolo *listaFunciones = ts.funciones;
    printf("Funciones Declaradas:\n");
    Simbolo *aux = listaFunciones;
    while (aux != NULL)
    {
        // listar argumentos
        Argumento *argumentos = aux->argumentos;
        if (argumentos != NULL)
        {
            printf("Linea %d: %s %s( ", aux->linea, aux->tipo, aux->nombre);
            while (argumentos != NULL)
            {
                printf("%s %s", argumentos->tipo, argumentos->nombre);
                if (argumentos->siguiente != NULL)
                {
                    printf(", ");
                }
                argumentos = argumentos->siguiente;
            }
            printf(" );\n");
        }
        else{

            printf("Linea %d: %s %s(  );\n", aux->linea, aux->tipo, aux->nombre);
        }

        aux = aux->siguiente;
    }
}

void imprimirSentencias(Simbolo *listaFunciones)
{

    printf("Sentencias Declaradas:\n");
    Simbolo *aux = listaFunciones;
    while (aux != NULL)
    {
        printf("Linea %d: %s \n", aux->linea, aux->tipo);
        aux = aux->siguiente;
    }
}

void imprimirErrores(Simbolo *listaErrores)
{
    if (listaErrores == NULL)
        return;

    printf("Errores Sintacticos detectados con token error:\n");
    Simbolo *aux = listaErrores;
    while (aux != NULL)
    {
        printf("Linea %d:%d %s \n", aux->linea, aux->columna, aux->tipo);
        aux = aux->siguiente;
    }
}
//--------------------------------------------------------------
//--------------------------------------------------------------
void procesarVariableSimple(char *tipo, char *nombre, int linea, TablaSimbolos* ts)
{
    Simbolo *variable = nuevoSimbolo(nombre, "TIPO", tipo, NULL, linea, linea);
    if(hayDobleDeclaracion(*ts, variable, linea, linea) == false){
        insertarOrdenado(&(ts->variables), variable, &menorLinea);
    }
    
}

void procesarSentencia(Simbolo **listaSentencias, char *tipo, char *nombre, int linea)
{
    Simbolo *sentencia = nuevoSimbolo(nombre, tipo, "sentencia", NULL, linea, linea);
    insertarOrdenado(listaSentencias, sentencia, &menorLinea); 
}

void procesarFuncion(char *tipo,char* tipoDato, char *nombre, Argumento *argumentos, int linea, TablaSimbolos* ts)
{   
    Simbolo *funcion = nuevoSimbolo(nombre, tipo, tipoDato, argumentos, linea, linea);
    if(hayDobleDeclaracion(*ts, funcion, linea, linea) == false){
        insertarOrdenado(&(ts->funciones), funcion, &menorLinea);
    }
}
void procesarError(Simbolo **listaErrores, char *tipo, int linea, int columna)
{
    Simbolo *error = nuevoSimbolo(tipo, tipo,"error", NULL, linea, columna);
    insertarOrdenado(listaErrores, error, &menorLinea);
}
//--------------------------------------------------------------
//--------------------------------------------------------------