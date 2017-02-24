
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

{NUMERO} {yylval.real=atof(yytext); return(NUMERO);}
"="         {return(IGUAL);}
"int"		{return (Tint);}
"double"		{return (Tdouble);}
"string"		{return (Tstring);}


"+"         {return(MAS);}
"-"          {return(MENOS);}
";"          {return(PTOCOMA);}
"*"         {return(POR);}
"/"          {return(DIV);}
"("          {return(PAA);}
")"          {return(PAC);}
"\n"       {linea++;}
{id} { strcpy( yylval.string , yytext);return id;}
"!--"[^}\n]*
"(*"[^}\n]*"*)" 
[\t\r\f] {}
" "                          {}

.    {printf("Error lexico en linea %d \n",linea);}

%%

