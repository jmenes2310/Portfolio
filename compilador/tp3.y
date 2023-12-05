%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/general.h"
#include "src/utils.h"
#include "src/model.h"
#include "src/validaciones.h"

#define FICHERO_ENTRADA "entrada.c"

extern int yylex(void);
extern int yylineno;
extern FILE *yyin;

void yyerror (const char*);
void printError(const char*, int, int);

int num_linea = 1;
int lineaIdentificador = 1;
bool errorManejado = false;
int lineaErrorActual = 0;

TablaSimbolos ts;

Simbolo* listaSentencias;
Simbolo* listaErrores = NULL;
Argumento* listaArgumentos = NULL;
Argumento* listaDeParametros = NULL;

void asignarTipo(char* tipo){
        Simbolo* aux = ts.variables;
        while(aux != NULL){
                if(strcmp(aux->tipo,"TIPO") == 0)
                        aux->tipo = tipo;
                aux = aux->siguiente;
        }
}

void agregarArgumento(Argumento** lista,char *nombre, char *tipo){
        Argumento* nuevo = (Argumento*)malloc(sizeof(Argumento));
        nuevo->nombre = nombre;
        nuevo->tipo = tipo;
        nuevo->siguiente = NULL;
        if(*lista == NULL){
                *lista = nuevo;
        }else{
                Argumento* aux = *lista;
                while(aux->siguiente != NULL){
                        aux = aux->siguiente;
                }
                aux->siguiente = nuevo;
        }
}

void limpiarListaArgumentos(){
        listaArgumentos = NULL;
}

void limpiarListaParametros(){
        listaDeParametros = NULL;
}



%}

/* Para requirle a Bison que describa más detalladamente los mensajes de error al invocar a yyerror */

%error-verbose
/*%define parse.error verbose*/
/*%define variable parse.error*/


	/* Nota: esta directiva (escrita de esta manera) quedó obsoleta a partir de Bison v3.0, siendo reemplazada por la directiva: %define parse.error verbose */


/* Para activar el seguimiento de las ubicaciones de los tokens (número de linea, número de columna) */
%locations

/* Para especificar la colección completa de posibles tipos de datos para los valores semánticos */
%union {
        long long_type;
        struct text{
                char *nombre;
                char* tipo;
        } text;
}

%token <text> TIPO_DE_DATO
%token <text> OPERADOR_UNARIO
%token <text> OPER_ASIGNACION
%token <text> OPER_IGUALDAD
%token <text> OPER_OR
%token <text> OPER_AND
%token <text> OPER_RELACION
%token <text> IDENTIFICADOR
%token <text> CARACTER
%token <text> SIZE_OF
%token <text> IF
%token <text> ELSE
%token <text> RETURN
%token <text> BREAK
%token <text> CONTINUE
%token <text> FOR
%token <text> DO 
%token <text> WHILE
%token <text> SWITCH
%token <text> LITERAL_CADENA
%token <text> CASE
%token <text> DEFAULT
%token <text> CONSTANTE_OCTAL
%token <text> CONSTANTE_HEXA
%token <text> CONSTANTE_REAL
%token <text> CONSTANTE_DECIMAL
	
%type <text> listaVariablesSimples
%type <text> unaVariableSimple

%left ','
%right OPER_ASIGNACION '='
%left OPER_OR
%left OPER_AND
%left OPER_IGUALDAD
%left OPER_RELACION
%left '+' '-'
%left '*' '/'
//%left '^'
%left OPERADOR_UNARIO "sizeof"
%left "--" "++"
%left '(' ')' 

%start input


%%

input
        :
        | input line {;}
        ;

line
        : sentenciaInicial {;}
        ;

sentenciaInicial
        : sentenciaCompuesta1 { $<text>$ = $<text>1;}
        | declaracionConError { procesarSentencia(&listaSentencias,"Declaracion", "Declaracion",@1.first_line);}
        ;

sentencia
        : sentenciaCompuesta1   {$<text>$ = $<text>1;}
        | sentSeleccion1        {procesarSentencia(&listaSentencias,"Seleccion", "Seleccion",@1.first_line);}
        | sentIteracion         {procesarSentencia(&listaSentencias,"Iteracion", "Iteracion",@1.first_line);}
        | sentSalto             {procesarSentencia(&listaSentencias,"Salto", "Salto",@1.first_line);}
        | sentExpresion         {procesarSentencia(&listaSentencias,"Expresion", "Expresion",@1.first_line);}
        | declaracion           {procesarSentencia(&listaSentencias,"Declaracion", "Declaracion",@1.first_line);}
        ;

sentenciaCompuesta1
        : '{' sentenciaCompuesta2  {;}
        ;

sentenciaCompuesta2
        : cuerpoSentenciaCompuesta llaveCierre  {procesarSentencia(&listaSentencias,"Compuesta", "Compuesta",@2.last_line);}
        | llaveCierre                           {procesarSentencia(&listaSentencias,"Compuesta", "Compuesta",@1.first_line);}

cuerpoSentenciaCompuesta
        : cuerpoSentenciaCompuesta sentencia {;}
        | sentencia                          {$<text>$ = $<text>1;}
        ;

declaracion
        : declaracionSimple  {$<text>$ = $<text>1;}
        /* | decFuncion  {printf("(DECLARACION FUNCION)\n");} */
        ;

declaracionConError
        : declaracionSimple   {;}
        | declaracionFuncion          {;}
        | error {if(lineaErrorActual != @1.first_line) printError("Error: sintactico se esperaba una declaracion\n", @1.first_line,  @1.first_column); lineaErrorActual = @1.first_line;}
        ;

declaracionSimple
        : TIPO_DE_DATO listaVariablesSimples puntoYComa {asignarTipo($<text.nombre>1);}
        /* | TIPO_DE_DATO listaVarSimple error {printf("Se esperaba un punto y coma \n");} */
        ;

listaVariablesSimples
        : listaVariablesSimples ',' unaVariableSimple {procesarVariableSimple($<text.tipo>3, $<text.nombre>3,@1.first_line, &ts);}
        | unaVariableSimple                           {procesarVariableSimple($<text.tipo>1, $<text.nombre>1,@1.first_line, &ts);}
        ;

unaVariableSimple
        : lvalue { $<text>$ = $<text>1;}
        | error ';' {printError("Error: sintactico se esperaba LValue modificable\n", @0.first_line,  @0.first_column); eliminarSimbolos(&ts, @0.first_column); }
        ;

lvalue
        : IDENTIFICADOR rvalue{ $<text>$ = $<text>1;}
        ;

rvalue
        : /*vacio*/    {;}
        |'=' expresion {;}
        ;

declaracionFuncion
        : TIPO_DE_DATO IDENTIFICADOR  '(' tipoArgumentoDeclaracion parentesisCierre 
                { procesarFuncion($<text.nombre>1, $<text.nombre>1, $<text.nombre>2, listaArgumentos, @1.first_line, &ts); 
                  limpiarListaArgumentos();
                }
          cuerpoFuncion 
        ;
        
cuerpoFuncion
        : ';'
        | sentenciaCompuesta1
        ;

tipoArgumentoDeclaracion
        : /*vacio*/                
        |listaArgumentosDeclaracion
        ;

listaArgumentosDeclaracion
        : argumento                                {;}
        | listaArgumentosDeclaracion ',' argumento {;}
        ;

argumento
        : TIPO_DE_DATO IDENTIFICADOR {agregarArgumento(&listaArgumentos ,$<text.nombre>2,$<text.nombre>1);}
        ;


//nombreArgumento
//        : IDENTIFICADOR {$<text>$ = $<text>1;}
//        ;


sentExpresion
        : ';'                  {;}
        | expresion puntoYComa { $<text>$ = $<text>1;}
        | error ';'            { printError("Error sintactico: se esperaba una expresion\n", @1.first_line,  @1.first_column);}
        ;

sentSeleccion1
        : IF sentSeleccion2
        | SWITCH '(' expresion parentesisCierre sentenciaSwitch1 {;}
        ;

sentSeleccion2
        : '(' expresion parentesisCierre '{' sentSeleccion3
        ;

sentSeleccion3
        :  sentencia sentSeleccion4 {;}
        | llaveCierre opcionELSE {;}
        ;

sentSeleccion4
        : llaveCierre opcionELSE {;}
        | error opcionELSE { printError("Error sintactico: se esperaba una }\n", @0.first_line,  @0.first_column);}
        ;

opcionELSE
    :         {;}
    | ELSE sentencia {;}

sentenciaSwitch1
        : llaveApertura sentenciaSwitch2 llaveCierre{;} 
        ;

sentenciaSwitch2
        : sentenciaCase sentenciaSwitchDefault1
        | /*vacio*/ 
        ;

llaveApertura
        : '{'
        | error '\n' {printError("Error sintactico: se esperaba '{'\n", @0.first_line,  @0.first_column);}
        ;

sentenciaSwitchDefault1
        : DEFAULT ':' sentencia sentenciaSwitchBreak
        | /*vacio*/
        ;

sentenciaSwitchBreak
        : sentenciaBreak
        | /*vacio*/
        ;

sentenciaCase
        : CASE constanteEntera ':' sentencia sentenciaSwitchBreak
        ;

sentIteracion
        : WHILE '(' expresion parentesisCierre sentencia
        | DO sentencia WHILE '(' expresion parentesisCierre puntoYComa
        | FOR '(' sentenciaFor1
        ;

sentenciaFor1
        : expresion puntoYComa expresion puntoYComa expresion parentesisCierre sentencia
        | puntoYComa sentenciaFor2
        ;

sentenciaFor2
        : expresion puntoYComa expresion parentesisCierre sentencia
        | puntoYComa sentenciaFor3
        ;

sentenciaFor3
        : expresion parentesisCierre sentencia
        | parentesisCierre sentencia
        ;

sentSalto
        : sentenciaBreak
        | sentenciaReturn
        | sentenciaContinue
        ;

sentenciaBreak
        : BREAK puntoYComa
        ;

sentenciaReturn
        : RETURN exprecionReturn puntoYComa
        ;

exprecionReturn
        : expresion
        | /*vacio*/
        ;

sentenciaContinue
        : CONTINUE puntoYComa
        ;


expresion
        : expAsignacion {$<text>$ = $<text>1;}
        ;

expAsignacion
        : expCondicional                          { $<text>$ = $<text>1;} 
        | expUnaria OPER_ASIGNACION expAsignacion {;}
        | expUnaria '=' expAsignacion             { $<text>$ = $<text>3; validarLvalue($<text.tipo>1)}                                  
        ;

expCondicional
        : expOr {$<text>$ = $<text>1;} 
        | expOr '?' expresion ':' expCondicional {;}
        ;

expOr
        : expOr OPER_OR expAnd {;}
        | expAnd {$<text>$ = $<text>1;}
        ;

expAnd 
        : expAnd OPER_AND expIgualdad {;}
        | expIgualdad {$<text>$ = $<text>1;}
        ;

expIgualdad 
        : expIgualdad OPER_IGUALDAD expRelacion {;}
        | expRelacion {$<text>$ = $<text>1;}
        ;

expRelacion
        : expRelacion OPER_RELACION expAditiva {;}
        | expAditiva {$<text>$ = $<text>1;}
        ;

expAditiva
        : expAditiva '+' expMultiplicativa {validarBinaria(ts, $<text>1, $<text>3);}
        | expAditiva '-' expMultiplicativa {;}
        | expMultiplicativa {$<text>$ = $<text>1;}
        ;

expMultiplicativa
        : expMultiplicativa '*' expUnaria {;}
        | expMultiplicativa '/' expUnaria {;}
        | expUnaria {$<text>$ = $<text>1;}
        ;

expUnaria
        : OPERADOR_UNARIO expUnaria               {;}
        | expUnaria OPERADOR_UNARIO               {;}
        | SIZE_OF '(' nombreTipo parentesisCierre {;}
        | expPostfijo                             {$<text>$ = $<text>1;}
        ;

expPostfijo
        : expPostfijo '(' tipoArgumentoInvocacion parentesisCierre { validarInvocacionFuncion(ts,$<text.nombre>1,listaDeParametros, @1.first_line, @1.first_column); limpiarListaParametros();}
        | expPrimaria {$<text>$ = $<text>1;}
        ;

tipoArgumentoInvocacion
        : /*vacio*/                              {;}
        | listaArgumentosInvocacion              {;}
        ;

listaArgumentosInvocacion
        : listaArgumentosInvocacion ',' expresion {agregarArgumento(&listaDeParametros,$<text.nombre>3,$<text.tipo>3);}
        | expresion                               {agregarArgumento(&listaDeParametros,$<text.nombre>1,$<text.tipo>1);}
        ;

expPrimaria
        : IDENTIFICADOR {$<text>$ = $<text>1; validarVariableNoDeclarada(ts,$<text.nombre>1, @1.first_line, @1.first_column);}
        | constanteNumerica {$<text>$ = $<text>1;}
        | LITERAL_CADENA {$<text>$ = $<text>1;}
        | CARACTER {$<text>$ = $<text>1;}
        | '(' expresion parentesisCierre {$<text>$ = $<text>2;}
        ;


nombreTipo
        : TIPO_DE_DATO {$<text>$ = $<text>1;}
        ;

parentesisCierre
        :')'
        ;

llaveCierre
        :'}'
        ;

puntoYComa
        :';'
        |error {printError("Error sintactico: se esperaba ';'\n", @0.first_line,  @0.last_column);eliminarSimbolos(&ts, @0.first_column)}
        ;

constanteNumerica
        : constanteEntera {$<text>$ = $<text>1;}
        | CONSTANTE_REAL {$<text>$ = $<text>1;}
        ;
constanteEntera
        : CONSTANTE_DECIMAL {$<text>$ = $<text>1;}
        | CONSTANTE_OCTAL {$<text>$ = $<text>1;}
        | CONSTANTE_HEXA {$<text>$ = $<text>1;}
        ;


%%


/* Inicio de la sección de epílogo (código de usuario) */

int main()
{
inicializarUbicacion();

#if YYDEBUG
         yydebug = 1;
#endif


        FILE *archivo =fopen(FICHERO_ENTRADA, "r"); 

        yyin = archivo;

        int resultado_de_analisis = yyparse(); 

        fclose(archivo);

        printf("\n\n------------------------------------\n");
        imprimirVariablesSimples(ts);
        printf("------------------------------------\n");
        imprimirFunciones(ts);
        printf("------------------------------------\n");
        imprimirSentencias(listaSentencias);
        //printf("------------------------------------\n");
        //imprimirErrores(listaErrores);

        if(resultado_de_analisis == 0) resultado_de_analisis = errorManejado ? 1 : 0;

        switch(resultado_de_analisis){
                case 0: 
                        printf("la operacion fue exitosa, yyparse =  %d \n",resultado_de_analisis);
                break;
                case 1:
                        printf("fallo en el analisis sintactico de un fallo que no se pudo recuperar, yyparse = %d \n",resultado_de_analisis);
                break;

                case 2:
                        printf("fallo en analisis debido a agotamiento de memoria, yyparse = %d \n",resultado_de_analisis);
                break;
        }

        liberarMemoriaTS(ts);
        liberarMemoriaSimbolos(listaSentencias);
        liberarMemoriaSimbolos(listaErrores);
        
return 0;
}

/* Definición de la funcion yyerror para reportar errores, necesaria para que la funcion yyparse del analizador sintáctico pueda invocarla para reportar un error */

void printError(const char* literalCadena, int linea, int columna){
        errorManejado = true;
        fprintf(stderr, "Parser: %d:%d: %s\n", linea, columna, literalCadena);
}

void yyerror(const char* literalCadena)
{
        errorManejado = true;
        fprintf(stderr, "Parser: %d:%d: %s\n", yylloc.first_line, yylloc.first_column, literalCadena); 
        /* fprintf(stderr, "Parser: %d:%d: %s\n", linea, col, literalCadena); */
}



/* Fin de la sección de epílogo (código de usuario) */