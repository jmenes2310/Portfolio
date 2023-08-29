#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "utils.h"
#include "tokenModel.h"

bool existeToken(Token *tokens, char *lexema)
{
    Token *aux = tokens;
    while (aux != NULL)
    {
        if (strcmp(aux->valor, lexema) == 0)
        {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

Token* obtenerToken(Token* tokens, char* lexema){
    Token* aux = tokens;
    while(aux != NULL){
        if(strcmp(aux->valor, lexema) == 0){
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

Token* obtenerUltimoToken(Token* tokens){
    Token* aux = tokens;
    while(aux->siguiente != NULL){
        aux = aux->siguiente;
    }
    return aux;
}

void insertarOrdenado(Token **inicio, Token *nuevoToken, int(*comparar)(const Token *, const Token *))
{
    Token *actual = *inicio;
    Token *anterior = NULL;

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

int cantidadTokens(Token *tokens)
{
    int cantidad = 0;
    Token *aux = tokens;
    while (aux != NULL)
    {
        cantidad++;
        aux = aux->siguiente;
    }
    return cantidad;
}

Token* nuevoToken(int tamLexema){
    Token* token = malloc(sizeof(Token));
    if(token == NULL){
        printf("No se pudo reservar memoria para el token\n");
        return NULL;
    }
    token->valor = malloc(sizeof(char) * tamLexema);
    if(token->valor == NULL){
        printf("No se pudo reservar memoria para el valor del token\n");
        return NULL;
    }
    return token;
}

void agregarTokenOrdenadoPor(char *lexema, int num_linea, Token **tokens, int(*criterio)(const Token *, const Token *))
{
    Token* token = nuevoToken(strlen(lexema) + 1);
    strcpy(token->valor, lexema);
    token->linea = num_linea;
    token->cantidad = 1;
    token->siguiente = NULL;
    insertarOrdenado(tokens, token, criterio);
}

void liberarMemoriaTokens(Token* tokens){
    Token* aux = tokens;
    while(aux != NULL){
        Token* siguiente = aux->siguiente;
        free(aux->valor);
        free(aux);
        aux = siguiente;
    }
}
