/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 68 "sintactico.y" /* yacc.c:1909  */

  char string[1000];
  struct Logica *logica;

#line 131 "sintactico.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */
