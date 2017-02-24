
%{

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
  
  struct Logica
  {
    char verdaderas[100];
    char falsas [100];
    char tmpo[25000];
  }Logica;
  struct Logica * paraxor;
%}

/************************
  Declaraciones de Bison
*************************/

/*  Especifica la coleccion completa de tipos de datos para poder usar
   varios tipos de datos en los terminales y no terminales*/
%union
{
  char string[100];
  struct Logica *logica;
}



/* Indica la produccion con la que inicia nuestra gramatica*/
%start Exp_l

/* Especificacion de termines, podemos especificar tambien su tipo  */
%token <string> NUMERO
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
%token MAYOR
%token MAYORIGUAL
%token MENOR
%token MENORIGUAL
%token IGUALIGUAL
%token DIF
%token AND
%token OR
%token XOR
%token NOT
%token TFALSE
%token TTRUE
%token PROGRAM
%token VAR
%token USES
%token LINK
%token BEGINN
%token END
%token DODO
%token NEW
%token DPI
%token PUNTO
%token Tchar
%token Tbool
%token PROCEDURE
%token FUNCTION
%token RETURN
%token IF
%token THEN
%token ELSE
%token ELSEIF
%token CASE
%token SELECT
%token OF
%token BREAK
%token CONTINUE
%token WHILE
%token DO
%token REPEAT
%token UNTIL
%token FOR
%token TO
%token LOOP
%token DOSPUNTOS
%token COMA





%token <string> id

/* No Terminales, que tambien podemos especificar su tipo */
%type <string> E
%type <string> ExpRel
%type <logica> ExpLog 
%type <string> Calc
%type <string> Exp_l
%type <string>Programa
%type <string>list_sentencia
%type <string>Bloque
%type <string>variable
%type <string>list_variable
%type <string>importacion
%type <string>list_importacion
%type <string>enlace
%type <string>list_enlace
%type <string>tipo_dato
%type <string>list_id
%type <string>asignacion
%type <string>sentencia_retorno
%type <string>parametros
%type <string>llamada
%type <string>sentencias_control
%type <string>sentencia_if
%type <string>sentencia_while
%type <string>sentencia_for
%type <string>sentencia_do_while
%type <string>sentencia_case_of
%type <string>sentencia_break
%type <string>sentencia_continue
%type <string>sentencia_repeat_until
%type <string>sentencia_loop

/*  Definimos las precedencias de menor a mayor */
%left PAA 
%left MAS MENOS
%left POR DIV
%left OR
%left XOR
%left AND
%left NOT
%%
 /**********************
  Reglas Gramaticales
 ***********************/

/*
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



Exp_l:                   Exp_l Calc  
                               |Calc
                               |id{printf("%s \n",$1);}
                                               ;
Calc       :  ExpLog PTOCOMA {escribe($1->tmpo);printf ("falsas:=   %s \n",$1->falsas);
printf ("Verdaderas:=  %s \n",$1->verdaderas);
}                              
                                 ;

E :    NUMERO { strcpy($$,$1);} 
      
      | id {strcpy ($$,$1);}
      |PAA E PAC{strcpy($$,$2);}


      |E MAS E {strcpy($$,"t");
        char str[100];
        sprintf(str, "%d", tmp);
        strcat($$,str);
        char ttt[200];
        strcpy(ttt,$$);
        escribe(ttt);
        escribe("=");escribe($1);escribe("+");escribe($3);
        escribe("\n"); tmp++;
      }
      |E MENOS E {strcpy($$,"t");
        char str[100];
        sprintf(str, "%d", tmp);
        strcat($$,str);
        char ttt[200];
        strcpy(ttt,$$);
        escribe(ttt);
        escribe("=");escribe($1);escribe("-");escribe($3);
        escribe("\n"); tmp++;
      }
      |E POR E {strcpy($$,"t");
        char str[100];
        sprintf(str, "%d", tmp);
        strcat($$,str);
        char ttt[200];
        strcpy(ttt,$$);
        escribe(ttt);
        escribe("=");escribe($1);escribe("*");escribe($3);
        escribe("\n"); tmp++;
      }
      ;
      |E DIV E {strcpy($$,"t");
        char str[100];
        sprintf(str, "%d", tmp);
        strcat($$,str);
        char ttt[200];
        strcpy(ttt,$$);
        escribe(ttt);
        escribe("=");escribe($1);escribe("/");escribe($3);
        escribe("\n"); tmp++;
      }


      ;
      

ExpRel:
        E {strcpy($$,$1);}

        |TTRUE{strcpy($$,"1");}
        |TFALSE{strcpy($$,"0");}
        |E IGUALIGUAL E
                      {
                          strcpy($$,"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat($$,str);
                          char ttt[200];
                          strcpy(ttt,$$);
                          escribe(ttt);
                          escribe("=");
                          escribe($1);escribe("==");escribe($3);
                          escribe("\n"); tmp++;

                      }
        |E DIF    E    {
                          strcpy($$,"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat($$,str);
                          char ttt[200];
                          strcpy(ttt,$$);
                          escribe(ttt);
                          escribe("=");
                          escribe($1);escribe("!=");escribe($3);
                          escribe("\n"); tmp++;

                      }
        |E MAYOR  E{
                          strcpy($$,"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat($$,str);
                          char ttt[200];
                          strcpy(ttt,$$);
                          escribe(ttt);
                          escribe("=");
                          escribe($1);escribe(">");escribe($3);
                          escribe("\n"); tmp++;

                      }
        |E MAYORIGUAL E {
                          strcpy($$,"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat($$,str);
                          char ttt[200];
                          strcpy(ttt,$$);
                          escribe(ttt);
                          escribe("=");
                          escribe($1);escribe(">=");escribe($3);
                          escribe("\n"); tmp++;

                      }
        |E MENOR   E   {
                          strcpy($$,"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat($$,str);
                          char ttt[200];
                          strcpy(ttt,$$);
                          escribe(ttt);
                          escribe("=");
                          escribe($1);escribe("<");escribe($3);
                          escribe("\n"); tmp++;

                      }
        |E MENORIGUAL E {
                          strcpy($$,"t");
                          char str[100];
                          sprintf(str, "%d", tmp);
                          strcat($$,str);
                          char ttt[200];
                          strcpy(ttt,$$);
                          escribe(ttt);
                          escribe("=");
                          escribe($1);escribe("<=");escribe($3);
                          escribe("\n"); tmp++;

                      }        
      

;

ExpLog:
      
      ExpLog  AND ExpLog{
        $$=malloc(sizeof(Logica));
        strcpy($$->tmpo,$1->tmpo);strcat($$->tmpo,"\n");
        strcat($$->tmpo,$1->verdaderas);strcat($$->tmpo,"\n");
        strcat($$->tmpo,$3->tmpo);strcat($$->tmpo,"\n");
        strcpy($$->verdaderas,$3->verdaderas);
        strcpy($$->falsas,$1->falsas);
        strcat($$->falsas,$3->falsas);
      }
      |ExpLog  OR  ExpLog{
        $$=malloc(sizeof(Logica));
        strcpy($$->tmpo,$1->tmpo);strcat($$->tmpo,"\n");
        strcat($$->tmpo,$1->falsas);strcat($$->tmpo,"\n");
        strcat($$->tmpo,$3->tmpo);strcat($$->tmpo,"\n");
        strcpy($$->verdaderas,$1->verdaderas);
        strcat($$->verdaderas,$3->verdaderas);
        strcat($$->falsas,$3->falsas);
      }
      |ExpLog  XOR {esxor=1;} ExpLog
      {

        esxor=0;
        $$=malloc(sizeof(Logica));
        strcpy($$->tmpo,$1->tmpo);strcat($$->tmpo,"\n");
        strcat($$->tmpo,$1->verdaderas);strcat($$->tmpo,"\n");
        strcat($$->tmpo,$4->tmpo);strcat($$->tmpo,"\n");
        strcat($$->tmpo,$1->falsas);strcat($$->tmpo,"\n");
        strcat($$->tmpo,paraxor->tmpo);strcat($$->tmpo,"\n");
        strcpy($$->verdaderas,$4->falsas);
        strcat($$->verdaderas,paraxor->verdaderas);
        strcpy($$->falsas,$4->verdaderas);
        strcat($$->falsas,paraxor->falsas);
        
        
      }
      |NOT ExpLog{
        $$=malloc(sizeof(Logica));
        strcpy($$->tmpo,$2->tmpo);
        strcpy($$->verdaderas,$2->falsas);
        strcpy($$->falsas,$2->verdaderas);
        


      }
      |PAA ExpLog PAC  {
        $$=malloc(sizeof(Logica));strcpy($$->tmpo,$2->tmpo);
        strcpy($$->verdaderas,$2->verdaderas);
        strcpy($$->falsas,$2->falsas);  
      }
      |ExpRel {
        $$=malloc(sizeof(Logica));
        strcpy($$->tmpo,"if(");strcat($$->tmpo,$1);strcat($$->tmpo,") goto L");
        char str[100];sprintf(str,"%d",lbl);strcat($$->tmpo,str);strcat($$->tmpo,"\n");
        lbl++;
        char str2[100];sprintf(str2,"%d",lbl);
        lbl++;
        strcat($$->tmpo,"goto L");
        strcat($$->tmpo,str2);strcat($$->tmpo,"\n");
        strcpy($$->verdaderas,"L");strcat($$->verdaderas,str);strcat($$->verdaderas,":");
        strcpy($$->falsas,"L");strcat($$->falsas,str2);strcat($$->falsas,":");
        printf("%s\n",$$->tmpo);
        if(esxor)
        {
          paraxor=malloc(sizeof(Logica));
        strcat(paraxor->tmpo,"if(");strcat(paraxor->tmpo,$1);strcat(paraxor->tmpo,") goto L");
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


;
%%


void yyerror(char *s)
{
  printf("%s   \n",s);
}
void escribe(char s[10000])
{
  char *str;
  str=malloc(sizeof(10000));
  strcpy(str,s);
  fputs(str,salida);
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
        


*/