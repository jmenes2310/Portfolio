#include <stdbool.h>
#include "tokenModel.h"

#ifndef IDENTIFICADORESLEXICOS_H
#define IDENTIFICADORESLEXICOS_H


void setEsReconocible(bool reconocible);

// metodos auxiliares para analizar lexemas
int cantidadSaltoDeLinea(char *cadena);
int cadenaMasGrande(const Token *token1, const Token *token2);
int ordenAlfabetico(const Token *token1, const Token *token2);
int aparecePrimero(const Token *token1, const Token *token2);
int menorLinea(const Token *token1, const Token *token2);

// metodos para imprimir los listados
void listarLiteralCadena(Token* tokens, FILE* salida);
void listarIdentificadores(Token* tokens, FILE* salida);
void listarComentarios(Token* monolinea, Token* multilinea, FILE* salida);
void listarNoReconocidos(Token* tokens, FILE* salida);
void listarPalabrasReservadas(Token* tiposDato, Token* estructurasControl, FILE* salida);
void listarConstantes(Token* octales, Token* hexas, Token* decimales, Token* reales, Token* caracter, FILE* salida);
void listarOperadoresYCaracteresPuntuacion(Token* operadoresYCaracteresPuntuacion, FILE* salida);

// metodos para liberar memoria

// metodos para procesar lexemas
void procesarLiteralCadena(char *lexema, int numeroLinea, Token **tokens);
void procesarIdentificador(char *lexema, int numeroLinea, Token **tokens);
void procesarComentario(char *lexema, int numeroLinea, Token **tokens);
void procesarNoReconocidos(char *lexema, int numeroLinea, Token **tokens);
void procesarTipoDato(char *lexema, int numeroLinea, Token **tokens);
void procesarEstructuraControl(char *lexema, int numeroLinea, Token **tokens);
void procesarConstante(char* lexema, int numeroLinea, Token** tokens);
void procesarCaracterPuntuacionOperador(char* lexema, int numeroLinea, Token** tokens);

#endif