
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "sintactico.tab.h"
  int linea=0;
%}

DIGITO [0-9]
NUMERO {DIGITO}+("."{DIGITO}+)?
id [a-z][a-z0-9]*

%%

{NUMERO} {strcpy(yylval.string,yytext); return(NUMERO);}

"class" {return(CLASS);}

"program" {return(PROGRAM);}
"var" {return(VAR);}
"uses" {return(USES);}
"link" {return(LINK);}
"begin" {return(BEGINN);}
"end" {return(END);}
"$$" {return(DODO);}
"new" {return(NEW);}
":=" {return(DPI);}
"." {return(PUNTO);}
"char" {return(Tchar);}
"bool" {return(Tbool);}
"procedure" {return(PROCEDURE);}
"function" {return(FUNCTION);}
"return" {return(RETURN);}
"if" {return(IF);}
"then" {return(THEN);}
"else" {return(ELSE);}
"elseif" {return(ELSEIF);}
"case" {return(CASE);}
"select" {return(SELECT);}
"of" {return(OF);}
"break" {return(BREAK);}
"continue" {return(CONTINUE);}
"while" {return(WHILE);}
"do" {return(DO);}
"repeat" {return(REPEAT);}
"until" {return(UNTIL);}
"for" {return(FOR);}
"to" {return(TO);}
"loop" {return(LOOP);}


"="         {return(IGUAL);}
"int"		{return (Tint);}
"double"		{return (Tdouble);}
"string"		{return (Tstring);}
"!--"[^}\n]*
"(*"[^}\n]*"*)"

"&&"          {return(AND);}
"||"          {return(OR);}
"??"          {return(XOR);}
"!!"          {return(NOT);}
"true"          {return(TTRUE);}
"false"			{return (TFALSE);}


"+"         {return(MAS);}
"-"          {return(MENOS);}
";"          {return(PTOCOMA);}
","          {return(COMA);}
":"          {return(DOSPUNTOS);}
"*"         {return(POR);}
"/"          {return(DIV);}
"("          {return(PAA);}
")"          {return(PAC);}



"<"          {return(MENOR);}
"<="          {return(MENORIGUAL);}
">"          {return(MAYOR);}
">="          {return(MAYORIGUAL);}
"!="          {return(DIF);}
"=="          {return(IGUALIGUAL);}




"\n"       {linea++;}
{id} { strcpy( yylval.string , yytext);return id;}
 
[\t\r\f] {}
" "                          {}

.    {printf("Error lexico en linea %d \n",linea);}

%%

