#ifndef MODEL
#define MODEL

typedef struct Simbolo Simbolo;
typedef struct TablaSimbolos TablaSimbolos;
typedef struct Argumento Argumento;

struct Argumento
{
     char *nombre;
     char *tipo;
     Argumento *siguiente;
};

struct Simbolo
{
     char *nombre;
     char *tipo;
     char* tipoDato;
     int linea;
     int columna;
     Argumento *argumentos;
     Simbolo *siguiente;
};

struct TablaSimbolos
{
     Simbolo *variables;
     Simbolo *funciones;
};

#endif