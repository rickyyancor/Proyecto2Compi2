
%{

/********************
  Declaraciones en C
**********************/

  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  extern int yylex(void);
  extern char *yytext;
  extern int linea;
  extern FILE *yyin;
  void yyerror(char *s);
%}

/************************
  Declaraciones de Bison
*************************/

/*  Especifica la coleccion completa de tipos de datos para poder usar
   varios tipos de datos en los terminales y no terminales*/
%union
{
  float real;
  char string[100];
}



/* Indica la produccion con la que inicia nuestra gramatica*/
%start Exp_l

/* Especificacion de termines, podemos especificar tambien su tipo  */
%token <real> NUMERO
%token MAS
%token MENOS
%token IGUAL
%token PTOCOMA
%token POR
%token DIV
%token PAA
%token PAC
%token Tint
%token Tdouble
%token Tstring


%token <string> id

/* No Terminales, que tambien podemos especificar su tipo */
%type <real> E
%type <real> Calc
%type <real> Exp_l

/*  Definimos las precedencias de menor a mayor */
%left MAS MENOS
%left POR DIV

%%
 /**********************
  Reglas Gramaticales
 ***********************/


Exp_l:                   Exp_l Calc  
                               |Calc
                               |id{printf("%s \n",$1);}
                                               ;
Calc       :  E PTOCOMA {printf ("%4.1f\n",$1);}                              
                                 ;

E :                      NUMERO {$$=$1;} 
      |E MAS E {$$=$1+$3;}
      |E MENOS E {$$=$1-$3;}
      |E POR E {$$=$1*$3;}
      |E DIV E {$$=$1/$3;}
      |PAA E PAC {$$=$2;}
      ;


%%


void yyerror(char *s)
{
  printf("Error sintactico %s",s);
}

int main(int argc,char **argv)
{
  if (argc>1)
                yyin=fopen(argv[1],"rt");
  else
                yyin=stdin;

  yyparse();
  return 0;
}

