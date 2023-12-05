
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "tp3.y"

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





/* Line 189 of yacc.c  */
#line 143 "tp3.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIPO_DE_DATO = 258,
     OPERADOR_UNARIO = 259,
     OPER_ASIGNACION = 260,
     OPER_IGUALDAD = 261,
     OPER_OR = 262,
     OPER_AND = 263,
     OPER_RELACION = 264,
     IDENTIFICADOR = 265,
     CARACTER = 266,
     SIZE_OF = 267,
     IF = 268,
     ELSE = 269,
     RETURN = 270,
     BREAK = 271,
     CONTINUE = 272,
     FOR = 273,
     DO = 274,
     WHILE = 275,
     SWITCH = 276,
     LITERAL_CADENA = 277,
     CASE = 278,
     DEFAULT = 279,
     CONSTANTE_OCTAL = 280,
     CONSTANTE_HEXA = 281,
     CONSTANTE_REAL = 282,
     CONSTANTE_DECIMAL = 283
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 84 "tp3.y"

        long long_type;
        struct text{
                char *nombre;
                char* tipo;
        } text;



/* Line 214 of yacc.c  */
#line 217 "tp3.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 242 "tp3.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNRULES -- Number of states.  */
#define YYNSTATES  211

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,    33,    31,    29,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    41,
       2,    30,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    28,    31,    33,    36,    38,    40,
      42,    44,    46,    50,    54,    56,    58,    61,    64,    65,
      68,    69,    77,    79,    81,    82,    84,    86,    90,    93,
      95,    98,   101,   104,   110,   116,   119,   122,   125,   128,
     129,   132,   136,   139,   140,   142,   145,   150,   151,   153,
     154,   160,   166,   174,   178,   186,   189,   195,   198,   202,
     205,   207,   209,   211,   214,   218,   220,   221,   224,   226,
     228,   232,   236,   238,   244,   248,   250,   254,   256,   260,
     262,   266,   268,   272,   276,   278,   282,   286,   288,   291,
     294,   299,   301,   306,   308,   309,   311,   315,   317,   319,
     321,   323,   325,   329,   331,   333,   335,   337,   339,   341,
     343,   345,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    -1,    47,    48,    -1,    49,    -1,    51,
      -1,    55,    -1,    51,    -1,    68,    -1,    79,    -1,    83,
      -1,    67,    -1,    54,    -1,    40,    52,    -1,    53,   104,
      -1,   104,    -1,    53,    50,    -1,    50,    -1,    56,    -1,
      56,    -1,    61,    -1,     1,    -1,     3,    57,   105,    -1,
      57,    29,    58,    -1,    58,    -1,    59,    -1,     1,    41,
      -1,    10,    60,    -1,    -1,    30,    88,    -1,    -1,     3,
      10,    38,    64,   103,    62,    63,    -1,    41,    -1,    51,
      -1,    -1,    65,    -1,    66,    -1,    65,    29,    66,    -1,
       3,    10,    -1,    41,    -1,    88,   105,    -1,     1,    41,
      -1,    13,    69,    -1,    21,    38,    88,   103,    73,    -1,
      38,    88,   103,    40,    70,    -1,    50,    71,    -1,   104,
      72,    -1,   104,    72,    -1,     1,    72,    -1,    -1,    14,
      50,    -1,    75,    74,   104,    -1,    78,    76,    -1,    -1,
      40,    -1,     1,    42,    -1,    24,    43,    50,    77,    -1,
      -1,    84,    -1,    -1,    23,   107,    43,    50,    77,    -1,
      20,    38,    88,   103,    50,    -1,    19,    50,    20,    38,
      88,   103,   105,    -1,    18,    38,    80,    -1,    88,   105,
      88,   105,    88,   103,    50,    -1,   105,    81,    -1,    88,
     105,    88,   103,    50,    -1,   105,    82,    -1,    88,   103,
      50,    -1,   103,    50,    -1,    84,    -1,    85,    -1,    87,
      -1,    16,   105,    -1,    15,    86,   105,    -1,    88,    -1,
      -1,    17,   105,    -1,    89,    -1,    90,    -1,    97,     5,
      89,    -1,    97,    30,    89,    -1,    91,    -1,    91,    44,
      88,    43,    90,    -1,    91,     7,    92,    -1,    92,    -1,
      92,     8,    93,    -1,    93,    -1,    93,     6,    94,    -1,
      94,    -1,    94,     9,    95,    -1,    95,    -1,    95,    31,
      96,    -1,    95,    32,    96,    -1,    96,    -1,    96,    33,
      97,    -1,    96,    34,    97,    -1,    97,    -1,     4,    97,
      -1,    97,     4,    -1,    12,    38,   102,   103,    -1,    98,
      -1,    98,    38,    99,   103,    -1,   101,    -1,    -1,   100,
      -1,   100,    29,    88,    -1,    88,    -1,    10,    -1,   106,
      -1,    22,    -1,    11,    -1,    38,    88,   103,    -1,     3,
      -1,    39,    -1,    45,    -1,    41,    -1,     1,    -1,   107,
      -1,    27,    -1,    28,    -1,    25,    -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   140,   140,   142,   146,   150,   151,   155,   156,   157,
     158,   159,   160,   164,   168,   169,   172,   173,   177,   182,
     183,   184,   188,   193,   194,   198,   199,   203,   207,   208,
     213,   212,   220,   221,   224,   226,   230,   231,   235,   245,
     246,   247,   251,   252,   256,   260,   261,   265,   266,   270,
     271,   274,   278,   279,   283,   284,   288,   289,   293,   294,
     298,   302,   303,   304,   308,   309,   313,   314,   318,   319,
     323,   324,   325,   329,   333,   337,   338,   342,   347,   351,
     352,   353,   357,   358,   362,   363,   367,   368,   372,   373,
     377,   378,   382,   383,   384,   388,   389,   390,   394,   395,
     396,   397,   401,   402,   406,   407,   411,   412,   416,   417,
     418,   419,   420,   425,   429,   433,   437,   438,   442,   443,
     446,   447,   448
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIPO_DE_DATO", "OPERADOR_UNARIO",
  "OPER_ASIGNACION", "OPER_IGUALDAD", "OPER_OR", "OPER_AND",
  "OPER_RELACION", "IDENTIFICADOR", "CARACTER", "SIZE_OF", "IF", "ELSE",
  "RETURN", "BREAK", "CONTINUE", "FOR", "DO", "WHILE", "SWITCH",
  "LITERAL_CADENA", "CASE", "DEFAULT", "CONSTANTE_OCTAL", "CONSTANTE_HEXA",
  "CONSTANTE_REAL", "CONSTANTE_DECIMAL", "','", "'='", "'+'", "'-'", "'*'",
  "'/'", "\"sizeof\"", "\"--\"", "\"++\"", "'('", "')'", "'{'", "';'",
  "'\\n'", "':'", "'?'", "'}'", "$accept", "input", "line",
  "sentenciaInicial", "sentencia", "sentenciaCompuesta1",
  "sentenciaCompuesta2", "cuerpoSentenciaCompuesta", "declaracion",
  "declaracionConError", "declaracionSimple", "listaVariablesSimples",
  "unaVariableSimple", "lvalue", "rvalue", "declaracionFuncion", "$@1",
  "cuerpoFuncion", "tipoArgumentoDeclaracion",
  "listaArgumentosDeclaracion", "argumento", "sentExpresion",
  "sentSeleccion1", "sentSeleccion2", "sentSeleccion3", "sentSeleccion4",
  "opcionELSE", "sentenciaSwitch1", "sentenciaSwitch2", "llaveApertura",
  "sentenciaSwitchDefault1", "sentenciaSwitchBreak", "sentenciaCase",
  "sentIteracion", "sentenciaFor1", "sentenciaFor2", "sentenciaFor3",
  "sentSalto", "sentenciaBreak", "sentenciaReturn", "exprecionReturn",
  "sentenciaContinue", "expresion", "expAsignacion", "expCondicional",
  "expOr", "expAnd", "expIgualdad", "expRelacion", "expAditiva",
  "expMultiplicativa", "expUnaria", "expPostfijo",
  "tipoArgumentoInvocacion", "listaArgumentosInvocacion", "expPrimaria",
  "nombreTipo", "parentesisCierre", "llaveCierre", "puntoYComa",
  "constanteNumerica", "constanteEntera", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    44,
      61,    43,    45,    42,    47,   284,   285,   286,    40,    41,
     123,    59,    10,    58,    63,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    49,    49,    50,    50,    50,
      50,    50,    50,    51,    52,    52,    53,    53,    54,    55,
      55,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      62,    61,    63,    63,    64,    64,    65,    65,    66,    67,
      67,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    83,    84,    85,    86,    86,    87,    88,    89,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    95,    96,    96,    96,    97,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   101,   101,   102,   103,   104,   105,   105,   106,   106,
     107,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     2,     2,     0,     2,
       0,     7,     1,     1,     0,     1,     1,     3,     2,     1,
       2,     2,     2,     5,     5,     2,     2,     2,     2,     0,
       2,     3,     2,     0,     1,     2,     4,     0,     1,     0,
       5,     5,     7,     3,     7,     2,     5,     2,     3,     2,
       1,     1,     1,     2,     3,     1,     0,     2,     1,     1,
       3,     3,     1,     5,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     1,     2,     2,
       4,     1,     4,     1,     0,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    21,     0,     0,     3,     4,     5,     6,
      19,    20,     0,    28,     0,    24,    25,     0,     0,     0,
     108,   111,     0,     0,    76,     0,     0,     0,     0,     0,
       0,   110,   121,   122,   119,   120,     0,    39,   115,    17,
       7,    13,     0,    12,    18,    11,     8,     9,    10,    70,
      71,    72,     0,    78,    79,    82,    85,    87,    89,    91,
      94,    97,   101,   103,    15,   109,   118,    26,     0,    34,
      27,   117,     0,   116,    22,    41,    28,    98,     0,     0,
      42,     0,    75,    73,    77,     0,     0,     0,     0,     0,
      16,    14,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,   104,    29,     0,     0,    35,
      36,    23,   113,     0,     0,    74,    63,     0,     0,     0,
       0,     0,   114,   112,    84,    97,     0,    86,    88,    90,
      92,    93,    95,    96,    80,    81,   107,     0,   105,    38,
      30,     0,   100,     0,     0,    65,     0,     0,     0,     0,
       0,     0,   102,     0,     0,    37,     0,     0,     0,    67,
       0,     0,     0,    61,     0,    54,    43,    53,    83,   106,
      32,    33,    31,     0,    44,    49,     0,     0,     0,    69,
       0,    55,     0,     0,    57,    49,    45,    49,     0,    46,
       0,     0,    68,    62,     0,    51,     0,    52,    48,    47,
      50,     0,    66,     0,     0,    64,    59,    59,    60,    58,
      56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     6,     7,    39,    40,    41,    42,    43,     9,
      44,    14,    15,    16,    70,    11,   154,   172,   108,   109,
     110,    45,    46,    80,   174,   186,   189,   166,   183,   167,
     197,   208,   184,    47,   116,   145,   159,    48,    49,    50,
      81,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   137,   138,    63,   113,   123,    64,    74,
      65,    66
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -167
static const yytype_int16 yypact[] =
{
    -167,     7,  -167,  -167,    18,   167,  -167,  -167,  -167,  -167,
    -167,  -167,    -5,    -7,    10,  -167,  -167,    -3,    20,   251,
    -167,  -167,   -25,     5,   251,    11,    11,    15,   210,    28,
      30,  -167,  -167,  -167,  -167,  -167,   251,  -167,  -167,  -167,
    -167,  -167,   167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,    11,  -167,  -167,     2,    52,    65,    64,    13,
      22,    12,    39,  -167,  -167,  -167,  -167,  -167,   251,    83,
    -167,  -167,    20,  -167,  -167,  -167,    58,  -167,    87,   251,
    -167,    11,  -167,  -167,  -167,   242,    73,   251,   251,    59,
    -167,  -167,  -167,   251,   251,   251,   251,   251,   251,   251,
     251,   251,  -167,   251,   251,   251,  -167,    89,    59,    81,
    -167,  -167,  -167,    59,    59,  -167,  -167,    11,   242,    74,
      59,    59,  -167,  -167,    52,   107,    70,    65,    64,    13,
      22,    22,   107,   107,  -167,  -167,  -167,    59,    85,  -167,
    -167,    83,  -167,    75,   251,  -167,    11,    53,   251,   210,
      14,   251,  -167,   251,    42,  -167,   167,    11,   251,  -167,
      59,   210,    59,  -167,    76,  -167,  -167,    93,  -167,  -167,
    -167,  -167,  -167,     3,  -167,   103,   251,    59,   210,  -167,
      11,  -167,     9,    77,    96,   103,  -167,   103,   210,  -167,
      59,   210,  -167,  -167,    82,  -167,    84,  -167,  -167,  -167,
    -167,   210,  -167,   210,   210,  -167,   108,   108,  -167,  -167,
    -167
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,  -167,   -28,     0,  -167,  -167,  -167,  -167,
     130,  -167,    60,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
      -4,  -167,  -167,  -167,  -167,  -167,  -163,  -167,  -167,  -167,
    -167,   -69,  -167,  -167,  -167,  -167,  -167,  -167,  -166,  -167,
    -167,  -167,   -18,   -19,   -12,  -167,    48,    47,    49,    46,
      -2,     8,  -167,  -167,  -167,  -167,  -167,   -88,   -37,   -23,
    -167,   -38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      86,     8,    83,    84,   185,    91,    82,     2,     3,    93,
       4,    71,    71,    78,    90,   164,   102,   103,    89,    12,
     140,    12,   198,    68,   199,   142,   143,    77,    13,    92,
      76,    69,   149,   150,    32,    33,    67,    35,    75,    72,
     209,   209,   104,    79,    98,    99,    94,     5,    38,   152,
     106,    73,    73,    85,   165,   100,   101,    19,   115,   161,
      95,   114,   118,    20,    21,    22,    87,   117,    88,   120,
     121,    96,   178,    97,   180,    31,   126,   105,    32,    33,
      34,    35,     5,   170,   134,   135,   107,   136,    68,   191,
     112,    36,   122,   119,   144,   147,   130,   131,   122,   139,
     146,   125,   201,   125,   125,   125,   125,   125,   132,   133,
     141,   102,   148,   151,   153,   156,   182,   188,   181,   175,
     196,   163,    38,   158,    25,   203,   157,   204,   173,   160,
     162,    10,   111,   179,   176,   169,   187,   155,   210,   168,
     177,   124,   127,   129,   194,   128,   195,     0,     0,     0,
     192,     0,     0,     0,   171,     0,     0,   193,   190,   125,
     200,     0,     0,   202,     0,     0,     0,     0,    17,     0,
      18,    19,     0,   205,     0,   206,   207,    20,    21,    22,
      23,     0,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,     5,    37,     0,
       0,    17,    38,    18,    19,     0,     0,     0,     0,     0,
      20,    21,    22,    23,     0,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,    32,    33,    34,    35,     0,
       0,     0,     0,    71,     0,     0,    19,     0,    36,     0,
       5,    37,    20,    21,    22,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    31,     0,     0,    32,    33,    34,
      35,     0,     0,    31,     0,     0,    32,    33,    34,    35,
      36,     0,     0,    73,     0,     0,     0,     0,     0,    36
};

static const yytype_int16 yycheck[] =
{
      28,     1,    25,    26,     1,    42,    24,     0,     1,     7,
       3,     1,     1,    38,    42,     1,     4,     5,    36,     1,
     108,     1,   185,    30,   187,   113,   114,    19,    10,    52,
      10,    38,   120,   121,    25,    26,    41,    28,    41,    29,
     206,   207,    30,    38,    31,    32,    44,    40,    45,   137,
      68,    41,    41,    38,    40,    33,    34,     4,    81,   147,
       8,    79,    85,    10,    11,    12,    38,    85,    38,    87,
      88,     6,   160,     9,   162,    22,    94,    38,    25,    26,
      27,    28,    40,    41,   103,   104,     3,   105,    30,   177,
       3,    38,    39,    20,   117,   118,    98,    99,    39,    10,
     118,    93,   190,    95,    96,    97,    98,    99,   100,   101,
      29,     4,    38,    43,    29,    40,    23,    14,    42,   156,
      24,   149,    45,   146,    16,    43,   144,    43,   156,   147,
     148,     1,    72,   161,   157,   153,   173,   141,   207,   151,
     158,    93,    95,    97,   182,    96,   183,    -1,    -1,    -1,
     178,    -1,    -1,    -1,   154,    -1,    -1,   180,   176,   151,
     188,    -1,    -1,   191,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,    -1,   201,    -1,   203,   204,    10,    11,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,
      -1,     1,    45,     3,     4,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,     1,    -1,    -1,     4,    -1,    38,    -1,
      40,    41,    10,    11,    12,     4,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    22,    -1,    -1,    25,    26,    27,    28,
      38,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,     0,     1,     3,    40,    48,    49,    51,    55,
      56,    61,     1,    10,    57,    58,    59,     1,     3,     4,
      10,    11,    12,    13,    15,    16,    17,    18,    19,    20,
      21,    22,    25,    26,    27,    28,    38,    41,    45,    50,
      51,    52,    53,    54,    56,    67,    68,    79,    83,    84,
      85,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   101,   104,   106,   107,    41,    30,    38,
      60,     1,    29,    41,   105,    41,    10,    97,    38,    38,
      69,    86,    88,   105,   105,    38,    50,    38,    38,    88,
      50,   104,   105,     7,    44,     8,     6,     9,    31,    32,
      33,    34,     4,     5,    30,    38,    88,     3,    64,    65,
      66,    58,     3,   102,    88,   105,    80,    88,   105,    20,
      88,    88,    39,   103,    92,    97,    88,    93,    94,    95,
      96,    96,    97,    97,    89,    89,    88,    99,   100,    10,
     103,    29,   103,   103,   105,    81,    88,   105,    38,   103,
     103,    43,   103,    29,    62,    66,    40,    88,   105,    82,
      88,   103,    88,    50,     1,    40,    73,    75,    90,    88,
      41,    51,    63,    50,    70,   104,   105,    88,   103,    50,
     103,    42,    23,    74,    78,     1,    71,   104,    14,    72,
      88,   103,    50,   105,   107,   104,    24,    76,    72,    72,
      50,   103,    50,    43,    43,    50,    50,    50,    77,    84,
      77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 142 "tp3.y"
    {;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 146 "tp3.y"
    {;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 150 "tp3.y"
    { (yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 151 "tp3.y"
    { procesarSentencia(&listaSentencias,"Declaracion", "Declaracion",(yylsp[(1) - (1)]).first_line);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 155 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 156 "tp3.y"
    {procesarSentencia(&listaSentencias,"Seleccion", "Seleccion",(yylsp[(1) - (1)]).first_line);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 157 "tp3.y"
    {procesarSentencia(&listaSentencias,"Iteracion", "Iteracion",(yylsp[(1) - (1)]).first_line);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 158 "tp3.y"
    {procesarSentencia(&listaSentencias,"Salto", "Salto",(yylsp[(1) - (1)]).first_line);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 159 "tp3.y"
    {procesarSentencia(&listaSentencias,"Expresion", "Expresion",(yylsp[(1) - (1)]).first_line);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 160 "tp3.y"
    {procesarSentencia(&listaSentencias,"Declaracion", "Declaracion",(yylsp[(1) - (1)]).first_line);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 164 "tp3.y"
    {;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 168 "tp3.y"
    {procesarSentencia(&listaSentencias,"Compuesta", "Compuesta",(yylsp[(2) - (2)]).last_line);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 169 "tp3.y"
    {procesarSentencia(&listaSentencias,"Compuesta", "Compuesta",(yylsp[(1) - (1)]).first_line);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 172 "tp3.y"
    {;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 173 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 177 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 182 "tp3.y"
    {;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 183 "tp3.y"
    {;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 184 "tp3.y"
    {if(lineaErrorActual != (yylsp[(1) - (1)]).first_line) printError("Error: sintactico se esperaba una declaracion\n", (yylsp[(1) - (1)]).first_line,  (yylsp[(1) - (1)]).first_column); lineaErrorActual = (yylsp[(1) - (1)]).first_line;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 188 "tp3.y"
    {asignarTipo((yyvsp[(1) - (3)].text.nombre));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 193 "tp3.y"
    {procesarVariableSimple((yyvsp[(3) - (3)].text.tipo), (yyvsp[(3) - (3)].text.nombre),(yylsp[(1) - (3)]).first_line, &ts);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 194 "tp3.y"
    {procesarVariableSimple((yyvsp[(1) - (1)].text.tipo), (yyvsp[(1) - (1)].text.nombre),(yylsp[(1) - (1)]).first_line, &ts);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 198 "tp3.y"
    { (yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 199 "tp3.y"
    {printError("Error: sintactico se esperaba LValue modificable\n", (yylsp[(0) - (2)]).first_line,  (yylsp[(0) - (2)]).first_column); eliminarSimbolos(&ts, (yylsp[(0) - (2)]).first_column); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 203 "tp3.y"
    { (yyval.text) = (yyvsp[(1) - (2)].text);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 207 "tp3.y"
    {;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 208 "tp3.y"
    {;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 213 "tp3.y"
    { procesarFuncion((yyvsp[(1) - (5)].text.nombre), (yyvsp[(1) - (5)].text.nombre), (yyvsp[(2) - (5)].text.nombre), listaArgumentos, (yylsp[(1) - (5)]).first_line, &ts); 
                  limpiarListaArgumentos();
                ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 230 "tp3.y"
    {;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 231 "tp3.y"
    {;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 235 "tp3.y"
    {agregarArgumento(&listaArgumentos ,(yyvsp[(2) - (2)].text.nombre),(yyvsp[(1) - (2)].text.nombre));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 245 "tp3.y"
    {;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 246 "tp3.y"
    { (yyval.text) = (yyvsp[(1) - (2)].text);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 247 "tp3.y"
    { printError("Error sintactico: se esperaba una expresion\n", (yylsp[(1) - (2)]).first_line,  (yylsp[(1) - (2)]).first_column);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 252 "tp3.y"
    {;;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 260 "tp3.y"
    {;;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 261 "tp3.y"
    {;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 265 "tp3.y"
    {;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 266 "tp3.y"
    { printError("Error sintactico: se esperaba una }\n", (yylsp[(0) - (2)]).first_line,  (yylsp[(0) - (2)]).first_column);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 270 "tp3.y"
    {;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 271 "tp3.y"
    {;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 274 "tp3.y"
    {;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 284 "tp3.y"
    {printError("Error sintactico: se esperaba '{'\n", (yylsp[(0) - (2)]).first_line,  (yylsp[(0) - (2)]).first_column);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 347 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 351 "tp3.y"
    { (yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 352 "tp3.y"
    {;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 353 "tp3.y"
    { (yyval.text) = (yyvsp[(3) - (3)].text); validarLvalue((yyvsp[(1) - (3)].text.tipo));}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 357 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 358 "tp3.y"
    {;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 362 "tp3.y"
    {;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 363 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 367 "tp3.y"
    {;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 368 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 372 "tp3.y"
    {;;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 373 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 377 "tp3.y"
    {;;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 378 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 382 "tp3.y"
    {validarBinaria(ts, (yyvsp[(1) - (3)].text), (yyvsp[(3) - (3)].text));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 383 "tp3.y"
    {;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 384 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 388 "tp3.y"
    {;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 389 "tp3.y"
    {;;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 390 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 394 "tp3.y"
    {;;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 395 "tp3.y"
    {;;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 396 "tp3.y"
    {;;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 397 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 401 "tp3.y"
    { validarInvocacionFuncion(ts,(yyvsp[(1) - (4)].text.nombre),listaDeParametros, (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column); limpiarListaParametros();;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 402 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 406 "tp3.y"
    {;;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 407 "tp3.y"
    {;;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 411 "tp3.y"
    {agregarArgumento(&listaDeParametros,(yyvsp[(3) - (3)].text.nombre),(yyvsp[(3) - (3)].text.tipo));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 412 "tp3.y"
    {agregarArgumento(&listaDeParametros,(yyvsp[(1) - (1)].text.nombre),(yyvsp[(1) - (1)].text.tipo));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 416 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text); validarVariableNoDeclarada(ts,(yyvsp[(1) - (1)].text.nombre), (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column);;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 417 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 418 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 419 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 420 "tp3.y"
    {(yyval.text) = (yyvsp[(2) - (3)].text);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 425 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 438 "tp3.y"
    {printError("Error sintactico: se esperaba ';'\n", (yylsp[(0) - (1)]).first_line,  (yylsp[(0) - (1)]).last_column);eliminarSimbolos(&ts, (yylsp[(0) - (1)]).first_column);}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 442 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 443 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 446 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 447 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 448 "tp3.y"
    {(yyval.text) = (yyvsp[(1) - (1)].text);;}
    break;



/* Line 1455 of yacc.c  */
#line 2296 "tp3.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 452 "tp3.y"



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
