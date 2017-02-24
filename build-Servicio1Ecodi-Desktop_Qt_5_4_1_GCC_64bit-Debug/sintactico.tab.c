/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "sintactico.y" /* yacc.c:339  */


/********************
  Declaraciones en C
**********************/
  #include <string.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  FILE *salida;
  extern int yylex(void);
  extern char *yytext;
  extern int linea;
  extern FILE *yyin;
  int tmp=1;
  int lbl=1;
  void yyerror(char *s);
  void escribe(char s[200]);
  int esxor=0;
  int retornociclo[100];
  int salidaciclo[100];
  int retornoactual=0;
  int salidaactual=0;
  char todo[25000];
  
  struct Logica
  {
    char verdaderas[100];
    char falsas [100];
    char tmpo[25000];
  }Logica;
  struct Logica * paraxor;

  struct paracase
  {
    int cond;
    char condicion[100];
    char tmpo[500];
  }paracase;
  struct paracase ParaCase[50];
  int caso;
  struct simbolo
  {
    char id[100];
    int pos;int tam;
    char rol[100];
    char ambito[100];
    char tipo[100];
  }simbolo;
  struct simbolo Tabla_Simbolos[100];
  int sim;
  int contador;
  int pos;
  char amb[100];
  char metodoactual[100];
  int heap;
  void AddSimbolo(char a1[200],char a2[200],char a3[200]);

#line 125 "sintactico.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "sintactico.tab.h".  */
#ifndef YY_YY_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_SINTACTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMERO = 258,
    MAS = 259,
    MENOS = 260,
    IGUAL = 261,
    PTOCOMA = 262,
    POR = 263,
    DIV = 264,
    PAA = 265,
    PAC = 266,
    Tint = 267,
    Tdouble = 268,
    Tstring = 269,
    MAYOR = 270,
    MAYORIGUAL = 271,
    MENOR = 272,
    MENORIGUAL = 273,
    IGUALIGUAL = 274,
    DIF = 275,
    AND = 276,
    OR = 277,
    XOR = 278,
    NOT = 279,
    TFALSE = 280,
    TTRUE = 281,
    PROGRAM = 282,
    VAR = 283,
    USES = 284,
    LINK = 285,
    BEGINN = 286,
    END = 287,
    DODO = 288,
    NEW = 289,
    DPI = 290,
    PUNTO = 291,
    Tchar = 292,
    Tbool = 293,
    PROCEDURE = 294,
    FUNCTION = 295,
    RETURN = 296,
    IF = 297,
    THEN = 298,
    ELSE = 299,
    ELSEIF = 300,
    CASE = 301,
    SELECT = 302,
    OF = 303,
    BREAK = 304,
    CONTINUE = 305,
    WHILE = 306,
    DO = 307,
    REPEAT = 308,
    UNTIL = 309,
    FOR = 310,
    TO = 311,
    LOOP = 312,
    DOSPUNTOS = 313,
    COMA = 314,
    LLA = 315,
    LLC = 316,
    class = 317,
    father = 318,
    tvoid = 319,
    tnew = 320,
    tPrivate = 321,
    tPublic = 322,
    tProtected = 323,
    ECSE = 324,
    OTHERWISE = 325,
    id = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 68 "sintactico.y" /* yacc.c:355  */

  char string[1000];
  struct Logica *logica;

#line 242 "sintactico.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "sintactico.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  84

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   215,   215,   242,   285,   314,   325,   340,   340,   340,
     340,   340,   340,   340,   341,   341,   341,   341,   343,   352,
     363,   405,   412,   605,   606,   608,   609,   611,   614,   624,
     634,   645,   661,   662,   663,   677,   690,   703,   716,   729,
     748,   758,   768,   768,   786,   796,   803
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO", "MAS", "MENOS", "IGUAL",
  "PTOCOMA", "POR", "DIV", "PAA", "PAC", "Tint", "Tdouble", "Tstring",
  "MAYOR", "MAYORIGUAL", "MENOR", "MENORIGUAL", "IGUALIGUAL", "DIF", "AND",
  "OR", "XOR", "NOT", "TFALSE", "TTRUE", "PROGRAM", "VAR", "USES", "LINK",
  "BEGINN", "END", "DODO", "NEW", "DPI", "PUNTO", "Tchar", "Tbool",
  "PROCEDURE", "FUNCTION", "RETURN", "IF", "THEN", "ELSE", "ELSEIF",
  "CASE", "SELECT", "OF", "BREAK", "CONTINUE", "WHILE", "DO", "REPEAT",
  "UNTIL", "FOR", "TO", "LOOP", "DOSPUNTOS", "COMA", "LLA", "LLC", "class",
  "father", "tvoid", "tnew", "tPrivate", "tPublic", "tProtected", "ECSE",
  "OTHERWISE", "id", "$accept", "S0", "Definicion", "Instancia",
  "list_exp", "tipo_dato", "visibilidad", "llamada", "listobj", "Exp", "E",
  "ExpRel", "ExpLog", "$@6", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

#define YYPACT_NINF -60

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -59,   -42,    20,   -59,    -8,   -60,   -43,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,    -2,   -60,   -43,    50,   -60,   -60,
     -60,    30,   -60,   -24,   -23,   -60,   -20,    47,   -60,    47,
     -60,    -3,   -60,     0,    51,     0,   -60,   -60,   -10,    33,
     -60,    79,   -60,    70,    27,    39,   -60,    79,   -60,    60,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     0,   -60,   -60,   -60,   -60,   -60,    -1,    25,
      25,   -60,   -60,    10,    10,    10,    10,    10,    10,   -60,
      31,     0,    96,    68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,    10,    11,     9,
       8,     7,    13,    12,    17,    22,     0,     0,    16,    14,
      15,     0,     2,     0,     0,     3,     0,    20,    21,     0,
       4,     0,    25,     0,     0,     0,    33,    32,     0,    26,
       6,    23,    46,    24,     0,     0,    19,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    27,    45,    18,     5,     0,    28,
      29,    30,    31,    36,    37,    38,    39,    34,    35,    40,
      41,     0,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,    99,    87,   -60,   -60,   -60,    80,    11,    58,
      22,   -60,   -22,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    16,    38,    14,    21,    28,    39,    40,
      47,    42,    43,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    49,    32,    32,     7,     8,     9,    33,    34,    68,
      33,    45,     1,    48,    51,    52,     4,    17,    53,    54,
       5,    35,    36,    37,    35,    36,    37,    17,    15,    10,
      11,    51,    52,    53,    54,    53,    54,    25,    64,    79,
      80,    26,    55,    56,    57,    58,    59,    60,    27,    50,
      65,    29,    61,    41,    63,    44,    12,    31,    46,    83,
      61,    62,    63,    13,    18,    19,    20,    66,    15,    24,
      15,    15,    41,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    51,    52,    23,    24,    53,    54,    61,
      82,    61,    62,    63,    55,    56,    57,    58,    59,    60,
      51,    52,     6,    22,    53,    54,    30,    64,    67
};

static const yytype_uint8 yycheck[] =
{
       3,    11,     3,     3,    12,    13,    14,    10,    11,    10,
      10,    33,    71,    35,     4,     5,    58,     6,     8,     9,
       0,    24,    25,    26,    24,    25,    26,    16,    71,    37,
      38,     4,     5,     8,     9,     8,     9,     7,    11,    61,
      62,    65,    15,    16,    17,    18,    19,    20,    71,    59,
      11,    71,    21,    31,    23,    33,    64,    10,     7,    81,
      21,    22,    23,    71,    66,    67,    68,     7,    71,    36,
      71,    71,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     4,     5,    35,    36,     8,     9,    21,
      68,    21,    22,    23,    15,    16,    17,    18,    19,    20,
       4,     5,     3,    16,     8,     9,    26,    11,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    73,    74,    58,     0,    74,    12,    13,    14,
      37,    38,    64,    71,    77,    71,    75,    80,    66,    67,
      68,    78,    75,    35,    36,     7,    65,    71,    79,    71,
      79,    10,     3,    10,    11,    24,    25,    26,    76,    80,
      81,    82,    83,    84,    82,    84,     7,    82,    84,    11,
      59,     4,     5,     8,     9,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    11,    11,     7,    81,    10,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    84,
      84,    85,    82,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    84,    85,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     5,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     4,
       3,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     0,     4,     2,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 216 "sintactico.y" /* yacc.c:1646  */
    {
  //printf("%s\n",$1 );
  //printf("%s\n",$2 );
  printf("%s\n",(yyvsp[-1].string) );
  printf("%s\n",(yyvsp[0].string) );
  
}
#line 1410 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 243 "sintactico.y" /* yacc.c:1646  */
    {
              int ia;int pp;
              for(ia=0;ia<sim;ia++)
                {
                char * j=malloc(200);
                char * k=malloc(200);
                strcpy(k,(yyvsp[-2].string));
                strcpy(j,Tabla_Simbolos[ia].id);
                if(strcmp(k,j)==0)
                {
                  pp=Tabla_Simbolos[ia].tam;    
                }
                }
              AddSimbolo((yyvsp[-4].string),(yyvsp[-2].string),"variable");
              Tabla_Simbolos[sim-1].tam=pp;
            }
#line 1431 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 286 "sintactico.y" /* yacc.c:1646  */
    {

  strcpy((yyval.string),(yyvsp[-3].logica)->tmpo);
  strcat((yyval.string),(yyvsp[-3].logica)->verdaderas);
  strcat((yyval.string),"=");
  char str[100];sprintf(str, "%d", heap);
  strcat((yyval.string),str);
  int pp=0;
  int ia;
  for(ia=0;ia<sim;ia++)
  {
    char * j=malloc(200);
    char * k=malloc(200);
    strcpy(k,metodoactual);
    strcpy(j,Tabla_Simbolos[ia].id);
    if(strcmp(k,j)==0)
    {
      pp=Tabla_Simbolos[ia].tam;    
    }
  }
  heap=heap+pp;
  printf("%d\n",heap);
  strcat((yyval.string),"\n");
  strcat((yyval.string),(yyvsp[0].string));
  //printf("%s\n",$<string>$ );
}
#line 1462 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 315 "sintactico.y" /* yacc.c:1646  */
    {
  char str[100];sprintf(str, "%d", tmp);tmp++;
  contador++;char qwe[100];
  strcpy((yyval.string),"t");strcat((yyval.string),str);strcat((yyval.string),"=P+");
  char st1r[100];sprintf(st1r, "%d", contador);strcat((yyval.string),st1r);strcat((yyval.string),"\n");
  strcat((yyval.string),todo);strcpy(todo,"");
  strcat((yyval.string),"Stack[t");strcat((yyval.string),str);strcat((yyval.string),"]=");
  strcat((yyval.string),(yyvsp[0].logica)->tmpo);strcat((yyval.string),"\n");
  //printf("%s\n",$<string>$ );
}
#line 1477 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 326 "sintactico.y" /* yacc.c:1646  */
    {
  char str[100];sprintf(str, "%d", tmp);tmp++;
  contador=1;char qwe[100];
  strcpy((yyval.string),"t");strcat((yyval.string),str);strcat((yyval.string),"=P+0\n");
  strcat((yyval.string),todo);strcpy(todo,"");
  strcat((yyval.string),"Stack[t");strcat((yyval.string),str);strcat((yyval.string),"]=");
  strcat((yyval.string),(yyvsp[0].logica)->tmpo);strcat((yyval.string),"\n");
  //printf("%s\n",$<string>$ );
}
#line 1491 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 341 "sintactico.y" /* yacc.c:1646  */
    {strcpy((yyval.string),"public");}
#line 1497 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 343 "sintactico.y" /* yacc.c:1646  */
    {
  char qwe[1000];
  strcpy(qwe,(yyvsp[-2].string));
  strcat(qwe,"\nP=P+");char st1r[100];sprintf(st1r, "%d", pos);
  strcat(qwe,st1r);strcat(qwe,"\ncall ");strcat(qwe,metodoactual);
  strcat(qwe,"_");strcat(qwe,(yyvsp[-4].string));
  strcat(qwe,"();\nP=P-");strcat(qwe,st1r);strcat(qwe,"\n");  
  strcpy((yyval.string),qwe);
}
#line 1511 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 353 "sintactico.y" /* yacc.c:1646  */
    {
  char qwe[1000];
  strcpy(qwe,"P=P+");char st1r[100];sprintf(st1r, "%d", pos);
  strcat(qwe,st1r);strcat(qwe,"\ncall ");strcat(qwe,metodoactual);
  strcat(qwe,"_");strcat(qwe,(yyvsp[-3].string));
  strcat(qwe,"();\nP=P-");strcat(qwe,st1r);strcat(qwe,"\n");  
  strcpy((yyval.string),qwe);
}
#line 1524 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 364 "sintactico.y" /* yacc.c:1646  */
    {
  char str[100];
  char st1r[100];
  char str3[100];
  
  int ia;

  
  for(ia=0;ia<sim;ia++)
  {
    char * j=malloc(200);
    char * k=malloc(200);
    strcpy(k,(yyvsp[0].string));
    strcpy(j,Tabla_Simbolos[ia].id);
    if(strcmp(k,j)==0)
    {
      strcpy(metodoactual,Tabla_Simbolos[ia].tipo);    
    }
  }
  strcpy((yyval.logica)->tmpo,(yyvsp[-2].logica)->tmpo); 
  strcat((yyval.logica)->tmpo,"t");
  sprintf(str, "%d", tmp);tmp++;
  strcat((yyval.logica)->tmpo,str);
  strcat((yyval.logica)->tmpo,"=");
  strcat((yyval.logica)->tmpo,(yyvsp[-2].logica)->falsas);
  strcat((yyval.logica)->tmpo,"+");
  sprintf(st1r, "%d", PosSimbolo((yyvsp[0].string)));
  strcat((yyval.logica)->tmpo,st1r);strcat((yyval.logica)->tmpo,"\n");
  sprintf(str3, "%d", tmp);tmp++;
  strcat((yyval.logica)->tmpo,"t");strcat((yyval.logica)->tmpo,str3);
  strcat((yyval.logica)->tmpo,"= Heap[t");
  strcat((yyval.logica)->tmpo,str);
  strcat((yyval.logica)->tmpo,"]\n");
  strcpy((yyval.logica)->verdaderas,"Heap[t");
  strcat((yyval.logica)->verdaderas,str);
  strcat((yyval.logica)->verdaderas,"]");
  strcpy((yyval.logica)->falsas,"t");
  strcat((yyval.logica)->falsas,str3);

  //printf("\n\n\n\n%s\n",$<logica>$->tmpo);
}
#line 1570 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 406 "sintactico.y" /* yacc.c:1646  */
    {
  (yyval.logica)=malloc(sizeof(Logica));
  strcpy((yyval.logica)->tmpo,(yyvsp[0].string));
  printf("\n\n\n\n%s\n",(yyval.logica)->tmpo);
}
#line 1580 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 412 "sintactico.y" /* yacc.c:1646  */
    {/*
  strcpy(Tabla_Simbolos[0].id,"jsjsuu");
  Tabla_Simbolos[0].pos=3;
  strcpy(Tabla_Simbolos[0].tipo,"claseA");
  
  strcpy(Tabla_Simbolos[1].id,"meet");
  Tabla_Simbolos[1].pos=5;
  strcpy(Tabla_Simbolos[1].tipo,"claseMeet");

  strcpy(Tabla_Simbolos[2].id,"iss");
  Tabla_Simbolos[2].pos=9;
  strcpy(Tabla_Simbolos[2].tipo,"claseB");
  */
  AddSimbolo("iss","ClaseB","variable");
  int i;
  AddSimbolo("jsjsuu","claseA","variable");
  AddSimbolo("meet","claseMeet","variable");
  (yyval.logica)=malloc(sizeof(Logica));
  char str[100];
  char st1r[100];
  char str3[100];
  
  int ia;

  for(ia=0;ia<sim;ia++)
  {
    char * j=malloc(200);
    char * k=malloc(200);
    strcpy(k,(yyvsp[0].string));
    strcpy(j,Tabla_Simbolos[ia].id);
    if(strcmp(k,j)==0)
    {
      strcpy(metodoactual,Tabla_Simbolos[ia].tipo);    
    }
  }
  

  
  strcpy((yyval.logica)->tmpo,"t");
  sprintf(str, "%d", tmp);tmp++;
  strcat((yyval.logica)->tmpo,str);
  strcat((yyval.logica)->tmpo,"=P+");
  sprintf(st1r, "%d", PosSimbolo((yyvsp[0].string)));
  strcat((yyval.logica)->tmpo,st1r);strcat((yyval.logica)->tmpo,"\n");
  sprintf(str3, "%d", tmp);tmp++;
  strcat((yyval.logica)->tmpo,"t");strcat((yyval.logica)->tmpo,str3);
  strcat((yyval.logica)->tmpo,"= Stack[t");
  strcat((yyval.logica)->tmpo,str);
  strcat((yyval.logica)->tmpo,"]\n");
  strcpy((yyval.logica)->verdaderas,"Stack[t");
  strcat((yyval.logica)->verdaderas,str);
  strcat((yyval.logica)->verdaderas,"]");
  strcpy((yyval.logica)->falsas,"t");
  strcat((yyval.logica)->falsas,str3);
  
  
}
#line 1642 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 605 "sintactico.y" /* yacc.c:1646  */
    {(yyval.logica)=malloc(sizeof(Logica));strcpy((yyval.logica)->tmpo,(yyvsp[0].string));}
#line 1648 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 606 "sintactico.y" /* yacc.c:1646  */
    {(yyval.logica)=(yyvsp[0].logica);}
#line 1654 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 608 "sintactico.y" /* yacc.c:1646  */
    { strcpy((yyval.string),(yyvsp[0].string));}
#line 1660 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 611 "sintactico.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[-1].string));}
#line 1666 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 614 "sintactico.y" /* yacc.c:1646  */
    {strcpy((yyval.string),"t");
        char str[100];
        sprintf(str, "%d", tmp);
        strcat((yyval.string),str);
        char ttt[200];
        strcpy(ttt,(yyval.string));
        escribe(ttt);
        escribe("=");escribe((yyvsp[-2].string));escribe("+");escribe((yyvsp[0].string));
        escribe("\n"); tmp++;
      }
#line 1681 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 624 "sintactico.y" /* yacc.c:1646  */
    {strcpy((yyval.string),"t");
        char str[100];
        sprintf(str, "%d", tmp);
        strcat((yyval.string),str);
        char ttt[200];
        strcpy(ttt,(yyval.string));
        escribe(ttt);
        escribe("=");escribe((yyvsp[-2].string));escribe("-");escribe((yyvsp[0].string));
        escribe("\n"); tmp++;
      }
#line 1696 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 634 "sintactico.y" /* yacc.c:1646  */
    {strcpy((yyval.string),"t");
        char str[100];
        sprintf(str, "%d", tmp);
        strcat((yyval.string),str);
        char ttt[200];
        strcpy(ttt,(yyval.string));
        escribe(ttt);
        escribe("=");escribe((yyvsp[-2].string));escribe("*");escribe((yyvsp[0].string));
        escribe("\n"); tmp++;
      }
#line 1711 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 645 "sintactico.y" /* yacc.c:1646  */
    {strcpy((yyval.string),"t");
        char str[100];
        sprintf(str, "%d", tmp);
        strcat((yyval.string),str);
        char ttt[200];
        strcpy(ttt,(yyval.string));
        escribe(ttt);
        escribe("=");escribe((yyvsp[-2].string));escribe("/");escribe((yyvsp[0].string));
        escribe("\n"); tmp++;
      }
#line 1726 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 661 "sintactico.y" /* yacc.c:1646  */
    {strcpy((yyval.string),"1");}
#line 1732 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 662 "sintactico.y" /* yacc.c:1646  */
    {strcpy((yyval.string),"0");}
#line 1738 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 664 "sintactico.y" /* yacc.c:1646  */
    {
                          strcpy((yyval.string),"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat((yyval.string),str);
                          char ttt[200];
                          strcpy(ttt,(yyval.string));
                          escribe(ttt);
                          escribe("=");
                          escribe((yyvsp[-2].string));escribe("==");escribe((yyvsp[0].string));
                          escribe("\n"); tmp++;

                      }
#line 1756 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 677 "sintactico.y" /* yacc.c:1646  */
    {
                          strcpy((yyval.string),"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat((yyval.string),str);
                          char ttt[200];
                          strcpy(ttt,(yyval.string));
                          escribe(ttt);
                          escribe("=");
                          escribe((yyvsp[-2].string));escribe("!=");escribe((yyvsp[0].string));
                          escribe("\n"); tmp++;

                      }
#line 1774 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 690 "sintactico.y" /* yacc.c:1646  */
    {
                          strcpy((yyval.string),"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat((yyval.string),str);
                          char ttt[200];
                          strcpy(ttt,(yyval.string));
                          escribe(ttt);
                          escribe("=");
                          escribe((yyvsp[-2].string));escribe(">");escribe((yyvsp[0].string));
                          escribe("\n"); tmp++;

                      }
#line 1792 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 703 "sintactico.y" /* yacc.c:1646  */
    {
                          strcpy((yyval.string),"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat((yyval.string),str);
                          char ttt[200];
                          strcpy(ttt,(yyval.string));
                          escribe(ttt);
                          escribe("=");
                          escribe((yyvsp[-2].string));escribe(">=");escribe((yyvsp[0].string));
                          escribe("\n"); tmp++;

                      }
#line 1810 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 716 "sintactico.y" /* yacc.c:1646  */
    {
                          strcpy((yyval.string),"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat((yyval.string),str);
                          char ttt[200];
                          strcpy(ttt,(yyval.string));
                          escribe(ttt);
                          escribe("=");
                          escribe((yyvsp[-2].string));escribe("<");escribe((yyvsp[0].string));
                          escribe("\n"); tmp++;

                      }
#line 1828 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 729 "sintactico.y" /* yacc.c:1646  */
    {
                          strcpy((yyval.string),"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat((yyval.string),str);
                          char ttt[200];
                          strcpy(ttt,(yyval.string));
                          escribe(ttt);
                          escribe("=");
                          escribe((yyvsp[-2].string));escribe("<=");escribe((yyvsp[0].string));
                          escribe("\n"); tmp++;

                      }
#line 1846 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 748 "sintactico.y" /* yacc.c:1646  */
    {
        (yyval.logica)=malloc(sizeof(Logica));
        strcpy((yyval.logica)->tmpo,todo);strcpy(todo,"");
        strcat((yyval.logica)->tmpo,(yyvsp[-2].logica)->tmpo);strcat((yyval.logica)->tmpo,"\n");
        strcat((yyval.logica)->tmpo,(yyvsp[-2].logica)->verdaderas);strcat((yyval.logica)->tmpo,"\n");
        strcat((yyval.logica)->tmpo,(yyvsp[0].logica)->tmpo);strcat((yyval.logica)->tmpo,"\n");
        strcpy((yyval.logica)->verdaderas,(yyvsp[0].logica)->verdaderas);
        strcpy((yyval.logica)->falsas,(yyvsp[-2].logica)->falsas);
        strcat((yyval.logica)->falsas,(yyvsp[0].logica)->falsas);
      }
#line 1861 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 758 "sintactico.y" /* yacc.c:1646  */
    {
        (yyval.logica)=malloc(sizeof(Logica));
        strcpy((yyval.logica)->tmpo,todo);strcpy(todo,"");
        strcat((yyval.logica)->tmpo,(yyvsp[-2].logica)->tmpo);strcat((yyval.logica)->tmpo,"\n");
        strcat((yyval.logica)->tmpo,(yyvsp[-2].logica)->falsas);strcat((yyval.logica)->tmpo,"\n");
        strcat((yyval.logica)->tmpo,(yyvsp[0].logica)->tmpo);strcat((yyval.logica)->tmpo,"\n");
        strcpy((yyval.logica)->verdaderas,(yyvsp[-2].logica)->verdaderas);
        strcat((yyval.logica)->verdaderas,(yyvsp[0].logica)->verdaderas);
        strcat((yyval.logica)->falsas,(yyvsp[0].logica)->falsas);
      }
#line 1876 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 768 "sintactico.y" /* yacc.c:1646  */
    {esxor=1;}
#line 1882 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 769 "sintactico.y" /* yacc.c:1646  */
    {

        esxor=0;
        (yyval.logica)=malloc(sizeof(Logica));
        strcpy((yyval.logica)->tmpo,todo);strcpy(todo,"");
        strcat((yyval.logica)->tmpo,(yyvsp[-3].logica)->tmpo);strcat((yyval.logica)->tmpo,"\n");
        strcat((yyval.logica)->tmpo,(yyvsp[-3].logica)->verdaderas);strcat((yyval.logica)->tmpo,"\n");
        strcat((yyval.logica)->tmpo,(yyvsp[0].logica)->tmpo);strcat((yyval.logica)->tmpo,"\n");
        strcat((yyval.logica)->tmpo,(yyvsp[-3].logica)->falsas);strcat((yyval.logica)->tmpo,"\n");
        strcat((yyval.logica)->tmpo,paraxor->tmpo);strcat((yyval.logica)->tmpo,"\n");
        strcpy((yyval.logica)->verdaderas,(yyvsp[0].logica)->falsas);
        strcat((yyval.logica)->verdaderas,paraxor->verdaderas);
        strcpy((yyval.logica)->falsas,(yyvsp[0].logica)->verdaderas);
        strcat((yyval.logica)->falsas,paraxor->falsas);
        
        
      }
#line 1904 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 786 "sintactico.y" /* yacc.c:1646  */
    {
        (yyval.logica)=malloc(sizeof(Logica));
        strcpy((yyval.logica)->tmpo,todo);strcpy(todo,"");
        strcat((yyval.logica)->tmpo,(yyvsp[0].logica)->tmpo);
        strcpy((yyval.logica)->verdaderas,(yyvsp[0].logica)->falsas);
        strcpy((yyval.logica)->falsas,(yyvsp[0].logica)->verdaderas);
        


      }
#line 1919 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 796 "sintactico.y" /* yacc.c:1646  */
    {
        (yyval.logica)=malloc(sizeof(Logica));
        strcpy((yyval.logica)->tmpo,todo);strcpy(todo,"");
        strcat((yyval.logica)->tmpo,(yyvsp[-1].logica)->tmpo);
        strcpy((yyval.logica)->verdaderas,(yyvsp[-1].logica)->verdaderas);
        strcpy((yyval.logica)->falsas,(yyvsp[-1].logica)->falsas);  
      }
#line 1931 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 803 "sintactico.y" /* yacc.c:1646  */
    {
        (yyval.logica)=malloc(sizeof(Logica));
        strcpy((yyval.logica)->tmpo,todo);strcpy(todo,"");
        strcat((yyval.logica)->tmpo,"if(");strcat((yyval.logica)->tmpo,(yyvsp[0].string));strcat((yyval.logica)->tmpo,") goto L");
        char str[100];sprintf(str,"%d",lbl);strcat((yyval.logica)->tmpo,str);strcat((yyval.logica)->tmpo,"\n");
        lbl++;
        char str2[100];sprintf(str2,"%d",lbl);
        lbl++;
        strcat((yyval.logica)->tmpo,"goto L");
        strcat((yyval.logica)->tmpo,str2);strcat((yyval.logica)->tmpo,"\n");
        strcpy((yyval.logica)->verdaderas,"L");strcat((yyval.logica)->verdaderas,str);strcat((yyval.logica)->verdaderas,":");
        strcpy((yyval.logica)->falsas,"L");strcat((yyval.logica)->falsas,str2);strcat((yyval.logica)->falsas,":");
        printf("%s\n",(yyval.logica)->tmpo);
        if(esxor)
        {
          paraxor=malloc(sizeof(Logica));
        strcat(paraxor->tmpo,"if(");strcat(paraxor->tmpo,(yyvsp[0].string));strcat(paraxor->tmpo,") goto L");
        char str3[100];sprintf(str3,"%d",lbl);strcat(paraxor->tmpo,str3);strcat(paraxor->tmpo,"\n");
        lbl++;
        char str4[100];sprintf(str4,"%d",lbl);
        lbl++;
        strcat(paraxor->tmpo,"goto L");
        strcat(paraxor->tmpo,str4);strcat(paraxor->tmpo,"\n");
        strcat(paraxor->verdaderas,"L");strcat(paraxor->verdaderas,str3);strcat(paraxor->verdaderas,":");
        strcat(paraxor->falsas,"L");strcat(paraxor->falsas,str4);strcat(paraxor->falsas,":");
          
        }
      }
#line 1964 "sintactico.tab.c" /* yacc.c:1646  */
    break;


#line 1968 "sintactico.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
  return yyresult;
}
#line 834 "sintactico.y" /* yacc.c:1906  */



void yyerror(char *s)
{
  printf("%s   \n",s);
}
void escribe(char s[10000])
{
  char *str;
  str=malloc(sizeof(10000));
  strcpy(str,s);
  strcat(todo,str);
}
void escribearchivo(char s[10000])
{
  char *str;
  str=malloc(sizeof(10000));
  strcpy(str,s);
  fputs(str,salida);
}
void AddSimbolo(char a1[200],char a2[200],char a3[200])
{
  strcpy(Tabla_Simbolos[sim].tipo,a2);
  strcpy(Tabla_Simbolos[sim].ambito,amb);
  strcpy(Tabla_Simbolos[sim].id,a1);
  strcpy(Tabla_Simbolos[sim].rol,a3);
  Tabla_Simbolos[sim].pos=pos;
  Tabla_Simbolos[sim].tam=1;
  pos++;sim++;
}
int PosSimbolo(char nom[200])
{
  int i;
  for(i=0;i<sim;i++)
  {
    
    char * j=malloc(200);
    char * k=malloc(200);
    strcpy(k,nom);
    strcpy(j,Tabla_Simbolos[i].id);
    if(strcmp(k,j)==0)
    {
      return Tabla_Simbolos[i].pos;   
    }
      
    
  }
  printf("Devolviendo: %d\n",-1);
  return -1;
}
int main(int argc,char **argv)
{
  if (argc>1)
                yyin=fopen(argv[1],"rt");
  else
                yyin=stdin;

  salida=fopen("salida.txt","w+t");
  yyparse();
  fclose(salida);
  return 0;
}

/*
$$=malloc(sizeof(Logica));
        escribe("if(");escribe($1->tmpo);escribe(") goto L");
        char str[100];sprintf(str, "%d", lbl);escribe(str);escribe("\n");lbl++;
        char str2[100];sprintf(str2, "%d", lbl);lbl++;
        escribe("goto L");escribe(str2);escribe("\n");
        strcpy($$->falsas,"L");strcat($$->falsas,str2);strcat($$->falsas,":");
        escribe("L");escribe(str);escribe(":\n");
        escribe("if(");escribe($3->tmpo);escribe(") goto L");
        char str3[100];sprintf(str3, "%d", lbl);escribe(str3);escribe("\n");lbl++;
        escribe("goto L");char str4[100];sprintf(str4, "%d", lbl);escribe(str4);escribe("\n");lbl++;
        strcat($$->falsas,"L");strcat($$->falsas,str4);strcat($$->falsas,":");
        strcpy($$->verdaderas,"L");strcat($$->verdaderas,str3);
        

Programa: PROGRAM id PTOCOMA;
importacion: USES id PUNTO id ;
enlace: LINK id PUNTO id ;
list_enlace: list_enlace enlace|enlace;
list_importacion: list_importacion importacion |importacion;
list_id: list_id COMA id|id;
tipo_dato:Tbool|Tchar|Tstring|Tint|Tdouble;
variable: VAR tipo_dato DOSPUNTOS list_id PTOCOMA
          |VAR id DOSPUNTOS DODO id PTOCOMA;
list_variable:list_variable variable|variable; 
asignacion: id DPI ExpLog PTOCOMA;
sentencia_retorno: RETURN PTOCOMA|RETURN ExpLog PTOCOMA;
parametros:parametros COMA ExpLog |ExpLog;
llamada: id PAA parametros PAC PTOCOMA|id PAA PAC PTOCOMA;

list_sentencia:list_sentencia asignacion|asignacion
              |list_sentencia llamada|llamada
              |list_sentencia asignacion|sentencias_control|;
Bloque:BEGIN list_sentencia END



*/
