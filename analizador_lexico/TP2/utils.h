#ifndef UTILS
#define UTILS

#include "tokenModel.h"

bool existeToken(Token* tokens, char* lexema);
Token* obtenerToken(Token* tokens, char* lexema);
void insertarOrdenado(Token **inicio, Token *nuevoToken, int(*comparar)(const Token *, const Token *));
int cantidadTokens(Token* tokens);
void agregarTokenOrdenadoPor(char *lexema, int num_linea, Token **tokens, int(*comparar)(const Token *, const Token *));
void liberarMemoriaTokens(Token* tokens);

#endif
