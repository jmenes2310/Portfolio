#ifndef TOKEN_MODEL
#define TOKEN_MODEL

typedef struct Token Token;
struct Token
{
     char *valor;
     int linea;
     int cantidad;
     Token *siguiente;
};

#endif