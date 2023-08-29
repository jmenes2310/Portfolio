#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "tokenLogic.h"
#include "tokenModel.h"
#include "utils.h"

bool anteriorEsReconocible = true;

void setEsReconocible(bool reconocible){
    // printf("Estado anterior = %d, nuevo estado = %d\n", anteriorEsReconocible, reconocible);
    anteriorEsReconocible = reconocible;
}
// Metodos auxiliares para analizar lexemas
int cantidadSaltoDeLinea(char *cadena)
{
    int i = 0;
    int cantidad = 0;
    while (cadena[i] != '\0')
    {
        if (cadena[i] == '\n')
        {
            cantidad++;
        }
        i++;
    }
    return cantidad;
}

int cadenaMasGrande(const Token *token1, const Token *token2)
{
    return strlen(token1->valor) - strlen(token2->valor);
}

int ordenAlfabetico(const Token *token1, const Token *token2)
{
    return strcmp(token1->valor, token2->valor);
}

int aparecePrimero(const Token *token1, const Token *token2)
{
    return token1->linea - token2->linea;
}

int menorLinea(const Token *token1, const Token *token2)
{
    if(token1->linea - token2->linea == 0){
        return -1;
    }
    return token1->linea - token2->linea;
}

// Metodos para imprimir los listados
void listarLiteralCadena(Token *tokens, FILE *salida)
{
    fprintf(salida,"---------------------------- LITERALES CADENA ----------------------------\n");
    printf("---------------------------- LITERALES CADENA ----------------------------\n");
    Token *aux = tokens;
    while (aux != NULL)
    {
        fprintf(salida,"Linea %d: %s, tamanio %d\n", aux->linea, aux->valor, strlen(aux->valor) - 2);
        printf("Linea %d: %s, tamanio %d\n", aux->linea, aux->valor, strlen(aux->valor) - 2);
        aux = aux->siguiente;
    }
    fprintf(salida,"--------------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------------\n");
}

void listarIdentificadores(Token *tokens, FILE* salida)
{
    fprintf(salida,"---------------------------- IDENTIFICADORES -----------------------------\n");
    printf("---------------------------- IDENTIFICADORES -----------------------------\n");
    Token *aux = tokens;
    while (aux != NULL)
    {
        fprintf(salida,"%s, x%d\n", aux->valor, aux->cantidad);
        printf("%s, x%d\n", aux->valor, aux->cantidad);
        aux = aux->siguiente;
    }
    fprintf(salida,"--------------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------------\n");
}

void listarComentarios(Token *comentariosMonolinea, Token *comentariosMultilineas, FILE* salida)
{
    fprintf(salida,"---------------------------- COMENTARIOS ---------------------------------\n");
    printf("---------------------------- COMENTARIOS ---------------------------------\n");
    Token *aux = comentariosMonolinea;
    
    if(aux != NULL){
        fprintf(salida,"Monolinea:\n");
        printf("Monolinea:\n");
    }else{
        fprintf(salida,"No hay comentarios monolinea\n");
        printf("No hay comentarios monolinea\n");
    }

    while (aux != NULL)
    {
        fprintf(salida,"Linea %d: %s\n", aux->linea, aux->valor);
        printf("Linea %d: %s\n", aux->linea, aux->valor);
        aux = aux->siguiente;
    }
    aux = comentariosMultilineas;
    
    if(aux != NULL){
        fprintf(salida,"Multilinea:\n");
        printf("Multilinea:\n");
    }else{
        fprintf(salida,"No hay comentarios multilinea\n");
        printf("No hay comentarios multilinea\n");
    }
    
    while (aux != NULL)
    {
        int lineaDesde = aux->linea - cantidadSaltoDeLinea(aux->valor);
        int lineaHasta = aux->linea;
        if(lineaDesde != lineaHasta){
            fprintf(salida,"Lineas [%d - %d]: %s\n", lineaDesde, lineaHasta, aux->valor);
            printf("Lineas [%d - %d]: %s\n", lineaDesde, lineaHasta, aux->valor);
        }else{
            fprintf(salida,"Linea %d: %s\n", aux->linea, aux->valor);
            printf("Linea %d: %s\n", aux->linea, aux->valor);
        }
        aux = aux->siguiente;
    }
    fprintf(salida,"--------------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------------\n");
}

void listarNoReconocidos(Token* tokens, FILE* salida){
    fprintf(salida,"---------------------------- NO RECONOCIDOS ------------------------------\n");
    printf("---------------------------- NO RECONOCIDOS ------------------------------\n");
    Token* aux = tokens;
    while (aux != NULL)
    {
        fprintf(salida,"\nLinea %d: %s", aux->linea, aux->valor);
        printf("\nLinea %d: %s", aux->linea, aux->valor);
        aux = aux->siguiente;
    }
    fprintf(salida,"\n--------------------------------------------------------------------------\n");
    printf("\n--------------------------------------------------------------------------\n");
}

void listarPalabrasReservadas(Token* tiposDato, Token* estructurasControl, FILE* salida){
    fprintf(salida,"---------------------------- PALABRAS RESERVADAS -------------------------\n");
    printf("---------------------------- PALABRAS RESERVADAS -------------------------\n");
    fprintf(salida,"Tipos de dato:\n");
    printf("Tipos de dato:\n");
    Token *aux = tiposDato;
    while (aux != NULL)
    {
        fprintf(salida,"%s\n", aux->valor);
        printf("%s\n", aux->valor);
        aux = aux->siguiente;
    }
    fprintf(salida,"Estructuras de control:\n");
    printf("Estructuras de control:\n");
    aux = estructurasControl;
    while (aux != NULL)
    {
        fprintf(salida,"%s\n", aux->valor);
        printf("%s\n", aux->valor);
        aux = aux->siguiente;
    }
    fprintf(salida,"--------------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------------\n");
}

void listarOperadoresYCaracteresPuntuacion(Token* operadoresYCaracteresPuntuacion, FILE* salida){
    fprintf(salida,"---------------- OPERADORES Y CARACTERES DE PUNTUACION -------------------\n");
    printf("---------------- OPERADORES Y CARACTERES DE PUNTUACION -------------------\n");
    fprintf(salida,"Tipos de dato:\n");
    printf("Tipos de dato:\n");
    Token *aux = operadoresYCaracteresPuntuacion;
    while (aux != NULL)
    {
        fprintf(salida,"Linea %d: %s x%d\n", aux->linea, aux->valor, aux->cantidad);
        printf("Linea %d: %s x%d\n", aux->linea, aux->valor, aux->cantidad);
        aux = aux->siguiente;
    }
    fprintf(salida,"--------------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------------\n");
}

void listarConstantes(Token* octales, Token* hexas, Token* decimales, Token* reales, Token* caracter, FILE* salida){
    fprintf(salida,"---------------------------- CONSTANTES ----------------------------------\n");
    printf("---------------------------- CONSTANTES ----------------------------------\n");
    fprintf(salida, "Octales:\n");
    printf("Octales:\n");
    Token *aux = octales;
    while (aux != NULL)
    {
        fprintf(salida,"Linea %d: %s",aux->linea, aux->valor);
        printf("Linea %d: %s",aux->linea, aux->valor);
        fprintf(salida,", Valor decimal: %d\n", strtol(aux->valor, NULL, 8));
        printf(", Valor decimal: %d\n", strtol(aux->valor, NULL, 8));
        aux = aux->siguiente;
    }
    fprintf(salida,"Hexadecimales:\n");
    printf("Hexadecimales:\n");
    aux = hexas;
    while (aux != NULL)
    {
        fprintf(salida,"Linea %d: %s",aux->linea, aux->valor);
        printf("Linea %d: %s",aux->linea, aux->valor);
        fprintf(salida,", Valor decimal: %d\n", strtol(aux->valor, NULL, 16));
        printf(", Valor decimal: %d\n", strtol(aux->valor, NULL, 16));
        aux = aux->siguiente;
    }
    fprintf(salida,"Decimales:\n");
    printf("Decimales:\n");
    aux = decimales;
    int totalAcumulado = 0;
    while (aux != NULL)
    {
        fprintf(salida,"Linea %d: %s\n",aux->linea, aux->valor);
        printf("Linea %d: %s\n",aux->linea, aux->valor);
        totalAcumulado += atoi(aux->valor);
        aux = aux->siguiente;
    }
    fprintf(salida,"Total acumulado: %d\n", totalAcumulado);
    printf("Total acumulado: %d\n", totalAcumulado);
    fprintf(salida,"Reales:\n");
    printf("Reales:\n");
    aux = reales;
    while (aux != NULL)
    {
        double parteDecimal, parteEntera;
        parteDecimal = modf(atof(aux->valor), &parteEntera);
        fprintf(salida,"Linea %d: %s",aux->linea, aux->valor);
        printf("Linea %d: %s",aux->linea, aux->valor);
        fprintf(salida,", Parte entera: %d", (int)parteEntera);
        printf(", Parte entera: %d", (int)parteEntera);
        fprintf(salida,", Parte decimal: %f\n", parteDecimal);
        printf(", Parte decimal: %f\n", parteDecimal);
        aux = aux->siguiente;
    }
    fprintf(salida,"Caracter:\n");
    printf("Caracter:\n");
    aux = caracter;
    while (aux != NULL)
    {
        fprintf(salida,"Linea %d: %s\n",aux->linea, aux->valor);
        printf("Linea %d: %s\n",aux->linea, aux->valor);
        aux = aux->siguiente;
    }
    fprintf(salida,"--------------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------------\n");
}

// Metodos para procesar lexemas
void procesarLiteralCadena(char *lexema, int numeroLinea, Token **tokens)
{
    setEsReconocible(true);
    if (!existeToken(*tokens, lexema))
    {
        agregarTokenOrdenadoPor(lexema, numeroLinea, tokens, &cadenaMasGrande);
    }
}

void procesarIdentificador(char *lexema, int numeroLinea, Token **tokens)
{
    setEsReconocible(true);
    if (!existeToken(*tokens, lexema))
    {
        agregarTokenOrdenadoPor(lexema, numeroLinea, tokens, &ordenAlfabetico);
    }else{
        Token *token = obtenerToken(*tokens, lexema);
        token->cantidad += 1;
    }
}

void procesarComentario(char *lexema, int numeroLinea, Token **tokens)
{
    setEsReconocible(true);
    agregarTokenOrdenadoPor(lexema, numeroLinea, tokens, &aparecePrimero);
}

void procesarNoReconocidos(char *lexema, int numeroLinea, Token **tokens){
    Token* aux = *tokens;
    if(anteriorEsReconocible || aux == NULL){
        agregarTokenOrdenadoPor(lexema, numeroLinea, tokens, &menorLinea);
    }else{
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->valor = realloc(aux->valor, sizeof(char) * (strlen(lexema) + strlen(aux->valor) + 1));
        strcat(aux->valor, lexema);
        strcat(aux->valor, "\0");
    }
    setEsReconocible(false);
}

void procesarTipoDato(char *lexema, int numeroLinea, Token **tokens){
    setEsReconocible(true);
    agregarTokenOrdenadoPor(lexema, numeroLinea, tokens, &menorLinea);
}

void procesarEstructuraControl(char *lexema, int numeroLinea, Token **tokens){
    setEsReconocible(true);
    agregarTokenOrdenadoPor(lexema, numeroLinea, tokens, &menorLinea);
}

void procesarConstante(char* lexema, int numeroLinea, Token** tokens){
    setEsReconocible(true);
    agregarTokenOrdenadoPor(lexema, numeroLinea, tokens, &menorLinea);
}

void procesarCaracterPuntuacionOperador(char* lexema, int numeroLinea, Token** tokens){
    setEsReconocible(true);
    if (!existeToken(*tokens, lexema))
    {
        agregarTokenOrdenadoPor(lexema, numeroLinea, tokens, &ordenAlfabetico);
    }else{
        Token *token = obtenerToken(*tokens, lexema);
        token->cantidad += 1;
    }
}