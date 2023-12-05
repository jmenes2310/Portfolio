
%{

#include "src/general.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp3.tab.h"

bool DEBUG_LEX = false;

void setTextToken(char *text){
    yylval.text.nombre = malloc(sizeof(char) * (strlen(text) + 1));
    strcpy(yylval.text.nombre,text);
    //printf("yylval.text.nombre: %s\n",yylval.text.nombre);
}

void setTipoToken (char* tipo){
    yylval.text.tipo = malloc(sizeof(char) * (strlen(tipo) + 1));
    strcpy(yylval.text.tipo,tipo);
}

void setNumberToken(char *text){
    yylval.long_type = strtoul(yytext, NULL, 0);
}

void printLexema(char* texto){
    if(DEBUG_LEX == true)
        printf("%s ",texto);
    if(strcmp(texto,"\n") == 0 || strcmp(texto,";") == 0)
        printf("\n");
    
}

%}

%pointer

%option yylineno
%option noyywrap

%x tokenNoReconocido
%x comentarioMultipleLinea

ERpalabrasReservadasTipoDato      auto|char|const|double|enum|extern|float|int|long|register|short|signed|static|struct|typedef|union|unsigned|void|volatile    
EROperadorUnario                  \&|\!|\~|\+\+|\-\-
EROperadorAsignacion              \+\=|\-\=|\*\=|\/\=
EROperadorIgualdad                \=\=|\!\=
EROperadorRelacion                \>|\>\=|\<|\<\=
ERcomentarioMonolinea             \/\/.*
ERconstanteDecimal                [1-9][0-9]*
ERconstanteOctal                  0[0-7]*
ERconstanteHexadecimal            0[xX][0-9a-fA-F]+
ERconstanteReal                   ([0-9]*\.[0-9]+([eE][+-]?[0-9]+)?)|([0-9]+[eE][+-]?[0-9]+)|([0-9]+\.)
ERidentificador                   [a-zA-Z_][a-zA-Z0-9_]*
ERcadena                          \"[^\"\n]*\"
ERCaracter                        \'([^'\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+)+\'

%%

    reinicializarUbicacion();

"/*"                                    {BEGIN(comentarioMultipleLinea);yylloc.last_column += yyleng;}
<comentarioMultipleLinea>"*/"           {BEGIN(INITIAL);yylloc.last_column += yyleng;}
<comentarioMultipleLinea>([^*]|\n)+|.   {yylloc.last_column += yyleng;}
<comentarioMultipleLinea><<EOF>>        {yylloc.last_column += yyleng;}

{ERcomentarioMonolinea}                 {yylloc.last_column += yyleng;}

{ERcadena}                  {printLexema(yytext); yylloc.last_column += yyleng; setTextToken(yytext); setTipoToken("char*"); return LITERAL_CADENA;}

{ERCaracter}                {printLexema(yytext); yylloc.last_column += yyleng; setTextToken(yytext); setTipoToken("char"); return CARACTER;}
{ERconstanteDecimal}        {printLexema(yytext);yylloc.last_column += yyleng; setTextToken(yytext); setTipoToken("int");return CONSTANTE_DECIMAL;}
{ERconstanteOctal}          {printLexema(yytext);yylloc.last_column += yyleng; setTextToken(yytext); setTipoToken("int"); return CONSTANTE_OCTAL;}
{ERconstanteHexadecimal}    {printLexema(yytext);yylloc.last_column += yyleng; setTextToken(yytext); setTipoToken("int"); return CONSTANTE_HEXA;}
{ERconstanteReal}           {printLexema(yytext);yylloc.last_column += yyleng; setTextToken(yytext); setTipoToken("double"); return CONSTANTE_REAL;}

{ERpalabrasReservadasTipoDato} {printLexema(yytext); yylloc.last_column += yyleng; setTextToken(yytext); return TIPO_DE_DATO;}

{EROperadorUnario}      {printLexema(yytext);yylloc.last_column += yyleng; setTextToken(yytext); return OPERADOR_UNARIO;}
{EROperadorAsignacion}  {printLexema(yytext);yylloc.last_column += yyleng; setTextToken(yytext); return OPER_ASIGNACION;}
{EROperadorIgualdad}    {printLexema(yytext);yylloc.last_column += yyleng; setTextToken(yytext); return OPER_IGUALDAD;}
{EROperadorRelacion}    {printLexema(yytext);yylloc.last_column += yyleng; setTextToken(yytext); return OPER_RELACION;}


"||"                {printLexema(yytext); yylloc.last_column += yyleng; return OPER_OR;}
"&&"                {printLexema(yytext); yylloc.last_column += yyleng; return OPER_AND;}
"{"                 {printLexema(yytext); yylloc.last_column += yyleng; return '{'; }
"}"                 {printLexema(yytext); yylloc.last_column += yyleng; return '}'; }
"("                 {printLexema(yytext); yylloc.last_column += yyleng; return '('; }
")"                 {printLexema(yytext); yylloc.last_column += yyleng; return ')'; }
"["                 {printLexema(yytext); yylloc.last_column += yyleng; return '['; }
"]"                 {printLexema(yytext); yylloc.last_column += yyleng; return ']'; }
"?"                 {printLexema(yytext); yylloc.last_column += yyleng; return '?'; }
";"                 {printLexema(yytext); yylloc.last_column += yyleng; return ';'; }
":"                 {printLexema(yytext); yylloc.last_column += yyleng; return ':'; }
","                 {printLexema(yytext); yylloc.last_column += yyleng; return ','; }
"+"                 {printLexema(yytext); yylloc.last_column += yyleng; return '+'; }
"-"                 {printLexema(yytext); yylloc.last_column += yyleng; return '-'; }
"*"                 {printLexema(yytext); yylloc.last_column += yyleng; return '*'; }
"/"                 {printLexema(yytext); yylloc.last_column += yyleng; return '/'; }
"^"                 {printLexema(yytext); yylloc.last_column += yyleng; return '^'; }
"="                 {printLexema(yytext); yylloc.last_column += yyleng; return '='; }
"sizeof"            {printLexema(yytext); yylloc.last_column += yyleng; return SIZE_OF; }
"return"            {printLexema(yytext); yylloc.last_column += yyleng; return RETURN; }
"break"             {printLexema(yytext); yylloc.last_column += yyleng; return BREAK; }
"continue"          {printLexema(yytext); yylloc.last_column += yyleng; return CONTINUE; }
"if"                {printLexema(yytext); yylloc.last_column += yyleng;  return IF; }
"else"              {printLexema(yytext); yylloc.last_column += yyleng;  return ELSE; }
"while"             {printLexema(yytext); yylloc.last_column += yyleng;  return WHILE; }
"do"                {printLexema(yytext); yylloc.last_column += yyleng;  return DO; }
"for"               {printLexema(yytext); yylloc.last_column += yyleng;  return FOR; }
"switch"            {printLexema(yytext); yylloc.last_column += yyleng;  return SWITCH; }
"case"              {printLexema(yytext); yylloc.last_column += yyleng;  return CASE; }
"default"           {printLexema(yytext); yylloc.last_column += yyleng;  return DEFAULT; }

{ERidentificador}   {printLexema(yytext); yylloc.last_column += yyleng; setTextToken(yytext); setTipoToken("id"); return IDENTIFICADOR;}



[ \t]+ { yylloc.first_column = yylloc.last_column += yyleng; }

\n {
        yylloc.first_line = yylloc.last_line += yyleng;
        yylloc.first_column = yylloc.last_column = INICIO_CONTEO_COLUMNA;
        // Quito este return para que no envie el salto de linea a bison
        // return '\n';
    }

[^ \t\n] { yylloc.last_column += yyleng; fprintf(stderr, "Scanner: %d:%d: Error lexico: token no reconocido: %s", yylloc.first_line, yylloc.first_column, yytext); BEGIN(tokenNoReconocido); }
<tokenNoReconocido>{
    " "|\t|\n {
        yyless(0);
        fprintf(stderr, "\n");
        BEGIN(INITIAL);
    }
    [^ \t\n]+ {
        yylloc.last_column += yyleng;
        fprintf(stderr, "%s\n", yytext);
        BEGIN(INITIAL);
    }
}
%%
