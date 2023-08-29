%option noyywrap

%{

// Definimos las librerías que incluímos, entre ellas "misfunciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenLogic.h"
#include "tokenModel.h"
#include "utils.h"



// Podemos definir variables globales para nuestro analizador léxico
int num_linea = 1;
Token* tokensLiteralCadena;
Token* tokensIdentificadores;
Token* tokensComentariosMonolinea;
Token* tokensComentariosMultilinea;
Token* tokensNoReconocidos;
Token* tokensEstructurasControl;
Token* tokensTipoDato;

Token* tokensConstanteDecimal;
Token* tokensConstanteOctal;
Token* tokensConstanteHexadecimal;
Token* tokensConstanteReal;
Token* tokensConstanteCaracter;

Token* tokensOperadoresYCaracteresPuntuacion;

%}
ERpalabrasReservadasTipoDato             auto|char|const|double|enum|extern|float|int|long|register|short|signed|sizeof|static|struct|typedef|union|unsigned|void|volatile
ERpalabrasReservadasEstructurasControl   break|case|continue|default|do|else|for|goto|if|return|switch|while             
ERcaracteresDePuntuacion          [,\.;:\?\(\)\[\]\{\}]
EROperadores                      (\+{1,2})|(\-{1,2})|\*|\/|\%|(\={1,2})|\!\=|\!|(\&{1,2})|\/|\>|\<|\>\=|\<\=|\+\=|\-\=|\*\=|\/\=|\%\=|\&\=|\|\=|\^|\^=|\~|\~\=|\,|\?|\:|\;|\(|\)|\[|\]|\{|\}
ERcomentarioMultilinea            \/\*([^*]|(\*+[^*/]))*\*+\/
ERcomentarioMonolinea             \/\/.*
ERconstanteDecimal                [1-9][0-9]*
ERconstanteOctal                  0[0-7]*
ERconstanteHexadecimal            0[xX][0-9a-fA-F]+
ERconstanteReal                   ([0-9]*\.[0-9]+([eE][+-]?[0-9]+)?)|([0-9]+[eE][+-]?[0-9]+)|([0-9]+\.)
ERidentificador                   [a-zA-Z_][a-zA-Z0-9_]*
ERcadena                          \"[^\"\n]*\"
ERCaracter                        \'[^\'\n]\'
ERsaltoLinea                      \n
ERyyout                           [^\n ]

%%
{ERsaltoLinea}  {setEsReconocible(true);num_linea+=1;}
{ERpalabrasReservadasTipoDato} {printf("Encontre la palabra reservada: %s \n",yytext);procesarTipoDato(yytext, num_linea, &tokensTipoDato);}
{ERpalabrasReservadasEstructurasControl} {printf("Encontre la palabra reservada: %s \n",yytext);procesarEstructuraControl(yytext, num_linea, &tokensEstructurasControl);}
{ERcomentarioMultilinea} {printf("Encontre el comentario multilinea: %s \n",yytext);num_linea += cantidadSaltoDeLinea(yytext); procesarComentario(yytext, num_linea, &tokensComentariosMultilinea);}
{ERcaracteresDePuntuacion} {printf("Encontre el caracter de puntuacion: %s \n",yytext);procesarCaracterPuntuacionOperador(yytext, num_linea, &tokensOperadoresYCaracteresPuntuacion);}
{EROperadores} {printf("Encontre el operador: %s \n",yytext);procesarCaracterPuntuacionOperador(yytext, num_linea, &tokensOperadoresYCaracteresPuntuacion);}
{ERcomentarioMonolinea} {printf("Encontre el comentario monolinea: %s \n",yytext);procesarComentario(yytext, num_linea, &tokensComentariosMonolinea);}
{ERconstanteDecimal} {printf("Encontre la constante entera decimal: %s\n",yytext);procesarConstante(yytext, num_linea, &tokensConstanteDecimal);}
{ERconstanteOctal} {printf("Encontre la constante entera octal: %s \n",yytext);procesarConstante(yytext, num_linea, &tokensConstanteOctal);}
{ERconstanteReal} {printf("Encontre la constante real: %s \n",yytext);procesarConstante(yytext, num_linea, &tokensConstanteReal);}
{ERconstanteHexadecimal} {printf("Encontre la constante entera hexadecimal: %s \n",yytext); procesarConstante(yytext, num_linea, &tokensConstanteHexadecimal);}
{ERidentificador} {printf("Encontre el identificador: %s \n",yytext);procesarIdentificador(yytext, num_linea, &tokensIdentificadores);}
{ERcadena} {printf("Encontre una cadena: %s, y su tamanio es: %d \n",yytext,(yyleng-2));procesarLiteralCadena(yytext, num_linea, &tokensLiteralCadena);}
{ERCaracter} {printf("Encontre una constante caracter: %s",yytext);procesarConstante(yytext, num_linea, &tokensConstanteCaracter);}
{ERyyout} {printf("Caracter no reconocido: %s \n",yytext);procesarNoReconocidos(yytext, num_linea, &tokensNoReconocidos);}



%%

int main() {
   
    /* Acciones previas a la invocación den analizador léxico */

    yyin = fopen("entrada.c", "r");
    FILE* archivoSalida = fopen("salida.txt", "w");	

    /* Invocación del analizador léxico */

    yylex();


    listarIdentificadores(tokensIdentificadores, archivoSalida);
    listarLiteralCadena(tokensLiteralCadena, archivoSalida);
    listarPalabrasReservadas(tokensTipoDato, tokensEstructurasControl, archivoSalida);
    listarConstantes(tokensConstanteOctal, tokensConstanteHexadecimal, tokensConstanteDecimal, tokensConstanteReal, tokensConstanteCaracter, archivoSalida); 
    listarOperadoresYCaracteresPuntuacion(tokensOperadoresYCaracteresPuntuacion, archivoSalida);
    listarComentarios(tokensComentariosMonolinea, tokensComentariosMultilinea, archivoSalida);
    listarNoReconocidos(tokensNoReconocidos, archivoSalida);


    liberarMemoriaTokens(tokensLiteralCadena);
    liberarMemoriaTokens(tokensIdentificadores);
    liberarMemoriaTokens(tokensComentariosMonolinea);
    liberarMemoriaTokens(tokensComentariosMultilinea);
    liberarMemoriaTokens(tokensNoReconocidos);
    liberarMemoriaTokens(tokensTipoDato);
    liberarMemoriaTokens(tokensEstructurasControl);
    liberarMemoriaTokens(tokensConstanteDecimal);
    liberarMemoriaTokens(tokensConstanteOctal);
    liberarMemoriaTokens(tokensConstanteHexadecimal);
    liberarMemoriaTokens(tokensConstanteReal);
    liberarMemoriaTokens(tokensConstanteCaracter);
    
    printf("Se genero correctamente archivo salida.txt con el analisis\n");
    return 0;
}

