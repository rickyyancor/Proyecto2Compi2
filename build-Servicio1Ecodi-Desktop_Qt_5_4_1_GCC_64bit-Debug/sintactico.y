
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
%}

/************************
  Declaraciones de Bison
*************************/

/*  Especifica la coleccion completa de tipos de datos para poder usar
   varios tipos de datos en los terminales y no terminales*/
%union
{
  char string[1000];
  struct Logica *logica;
}


/* Indica la produccion con la que inicia nuestra gramatica*/
%start S0

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
%token LLA
%token LLC
%token class
%token father
%token tvoid
%token tnew
%token tPrivate
%token tPublic
%token tProtected
%token ECSE
%token OTHERWISE

%token <string> id

/* No Terminales, que tambien podemos especificar su tipo */
%type <string> E
%type <string> S0
%type <string> ExpRel
%type <logica> ExpLog 
%type <logica> Exp
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
%type <logica>sentencia_if
%type <logica>sentencia_while
%type <logica>sentencia_for
%type <logica>sentencia_do_while
%type <string>sentencia_case_of
%type <string>sentencia_break
%type <string>sentencia_continue
%type <logica>sentencia_repeat_until
%type <logica>sentencia_loop
%type <string>list_clases
%type <string>clase
%type <string>visibilidad
%type <string>cuerpo
%type <string>Declaracion
%type <string>list_parametros
%type <string>parametro
%type <logica>listobj
%type <string>Definicion
%type <string>listcuerpo
%type <ParaCase>list_case
%type <string>bloquemetodo








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

S0:Definicion Definicion Instancia Instancia
{
  //printf("%s\n",$1 );
  //printf("%s\n",$2 );
  printf("%s\n",$<string>3 );
  printf("%s\n",$<string>4 );
  
};

list_clases:list_clases clase|clase;

clase:class id visibilidad LLA listcuerpo LLC
      |class id visibilidad LLA LLC;

Declaraciones:Declaraciones Declaracion|Declaracion;

heredar:father id|;

listcuerpo:listcuerpo cuerpo|cuerpo;

cuerpo:DeclaMetodo|Definicion;


Declaracion: id DOSPUNTOS tipo_dato visibilidad DPI Instancia PTOCOMA
            |id DOSPUNTOS tipo_dato visibilidad DPI Exp PTOCOMA
            |Definicion
            ;                    
Definicion: id DOSPUNTOS tipo_dato visibilidad PTOCOMA
            {
              int ia;int pp;
              for(ia=0;ia<sim;ia++)
                {
                char * j=malloc(200);
                char * k=malloc(200);
                strcpy(k,$3);
                strcpy(j,Tabla_Simbolos[ia].id);
                if(strcmp(k,j)==0)
                {
                  pp=Tabla_Simbolos[ia].tam;    
                }
                }
              AddSimbolo($1,$3,"variable");
              Tabla_Simbolos[sim-1].tam=pp;
            };


DeclaMetodo: id PAA list_parametros PAC DOSPUNTOS tipo_dato LLA bloquemetodo LLC PTOCOMA
       |id PAA list_parametros PAC DOSPUNTOS tipo_dato DOSPUNTOS visibilidad LLA bloquemetodo LLC PTOCOMA
       |id PAA PAC DOSPUNTOS tipo_dato DOSPUNTOS visibilidad LLA bloquemetodo LLC PTOCOMA
       |id PAA PAC DOSPUNTOS tipo_dato LLA bloquemetodo LLC PTOCOMA;
 
sentencia_retorno:RETURN Exp PTOCOMA|RETURN PTOCOMA{strcpy($<string>$,"RET;");};

bloquemetodo:Declaraciones list_sentencia|list_sentencia|Declaraciones|;

list_sentencia:list_sentencia sentencia{strcpy($<string>$,$<string>1);strcat($<string>$,"\n");strcat($<string>$,$<string>2);}
|sentencia{strcpy($<string>$,$<string>1);};

sentencia:asignacion|sentencia_retorno|sentencias_control|llamada|listobj
|sentencia_break|sentencia_continue;

asignacion: listobj DPI Exp PTOCOMA
{
  strcpy($<string>$,$<logica>1->tmpo);
  strcat($<string>$,todo);strcpy(todo,"");
  strcat($<string>$,$<logica>1->verdaderas);
  strcat($<string>$,"=");
  strcat($<string>$,$<logica>3->tmpo);
  printf("\nasignacion: \n%s\n", $<string>$); 
};
Instancia: listobj DPI tnew llamada
{

  strcpy($<string>$,$<logica>1->tmpo);
  strcat($<string>$,$<logica>1->verdaderas);
  strcat($<string>$,"=");
  char str[100];sprintf(str, "%d", heap);
  strcat($<string>$,str);
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
  strcat($<string>$,"\n");
  strcat($<string>$,$<string>4);
  //printf("%s\n",$<string>$ );
};

list_exp: 
list_exp COMA Exp
{
  char str[100];sprintf(str, "%d", tmp);tmp++;
  contador++;char qwe[100];
  strcpy($<string>$,"t");strcat($<string>$,str);strcat($<string>$,"=P+");
  char st1r[100];sprintf(st1r, "%d", contador);strcat($<string>$,st1r);strcat($<string>$,"\n");
  strcat($<string>$,todo);strcpy(todo,"");
  strcat($<string>$,"Stack[t");strcat($<string>$,str);strcat($<string>$,"]=");
  strcat($<string>$,$<logica>3->tmpo);strcat($<string>$,"\n");
  //printf("%s\n",$<string>$ );
};
|Exp
{
  char str[100];sprintf(str, "%d", tmp);tmp++;
  contador=1;char qwe[100];
  strcpy($<string>$,"t");strcat($<string>$,str);strcat($<string>$,"=P+0\n");
  strcat($<string>$,todo);strcpy(todo,"");
  strcat($<string>$,"Stack[t");strcat($<string>$,str);strcat($<string>$,"]=");
  strcat($<string>$,$<logica>1->tmpo);strcat($<string>$,"\n");
  //printf("%s\n",$<string>$ );
};

list_parametros: list_parametros COMA parametro|parametro;
parametro:id DOSPUNTOS tipo_dato;


tipo_dato:Tbool|Tchar|Tstring|Tint|Tdouble|id|tvoid;
visibilidad:tPublic|tProtected|tPrivate|{strcpy($$,"public");};

llamada:id PAA list_exp PAC PTOCOMA{
  char qwe[1000];
  strcpy(qwe,$<string>3);
  strcat(qwe,"\nP=P+");char st1r[100];sprintf(st1r, "%d", pos);
  strcat(qwe,st1r);strcat(qwe,"\ncall ");strcat(qwe,metodoactual);
  strcat(qwe,"_");strcat(qwe,$<string>1);
  strcat(qwe,"();\nP=P-");strcat(qwe,st1r);strcat(qwe,"\n");  
  strcpy($$,qwe);
}
|id PAA PAC PTOCOMA
{
  char qwe[1000];
  strcpy(qwe,"P=P+");char st1r[100];sprintf(st1r, "%d", pos);
  strcat(qwe,st1r);strcat(qwe,"\ncall ");strcat(qwe,metodoactual);
  strcat(qwe,"_");strcat(qwe,$<string>1);
  strcat(qwe,"();\nP=P-");strcat(qwe,st1r);strcat(qwe,"\n");  
  strcpy($$,qwe);
};


listobj:listobj PUNTO id
{
  char str[100];
  char st1r[100];
  char str3[100];
  
  int ia;

  
  for(ia=0;ia<sim;ia++)
  {
    char * j=malloc(200);
    char * k=malloc(200);
    strcpy(k,$3);
    strcpy(j,Tabla_Simbolos[ia].id);
    if(strcmp(k,j)==0)
    {
      strcpy(metodoactual,Tabla_Simbolos[ia].tipo);    
    }
  }
  strcpy($<logica>$->tmpo,$<logica>1->tmpo); 
  strcat($<logica>$->tmpo,"t");
  sprintf(str, "%d", tmp);tmp++;
  strcat($<logica>$->tmpo,str);
  strcat($<logica>$->tmpo,"=");
  strcat($<logica>$->tmpo,$<logica>1->falsas);
  strcat($<logica>$->tmpo,"+");
  sprintf(st1r, "%d", PosSimbolo($<string>3));
  strcat($<logica>$->tmpo,st1r);strcat($<logica>$->tmpo,"\n");
  sprintf(str3, "%d", tmp);tmp++;
  strcat($<logica>$->tmpo,"t");strcat($<logica>$->tmpo,str3);
  strcat($<logica>$->tmpo,"= Heap[t");
  strcat($<logica>$->tmpo,str);
  strcat($<logica>$->tmpo,"]\n");
  strcpy($<logica>$->verdaderas,"Heap[t");
  strcat($<logica>$->verdaderas,str);
  strcat($<logica>$->verdaderas,"]");
  strcpy($<logica>$->falsas,"t");
  strcat($<logica>$->falsas,str3);

  //printf("\n\n\n\n%s\n",$<logica>$->tmpo);
}
|listobj PUNTO llamada
{
  $<logica>$=malloc(sizeof(Logica));
  strcpy($<logica>$->tmpo,$<string>3);
  printf("\n\n\n\n%s\n",$<logica>$->tmpo);
}

|id{/*
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
  $<logica>$=malloc(sizeof(Logica));
  char str[100];
  char st1r[100];
  char str3[100];
  
  int ia;

  for(ia=0;ia<sim;ia++)
  {
    char * j=malloc(200);
    char * k=malloc(200);
    strcpy(k,$1);
    strcpy(j,Tabla_Simbolos[ia].id);
    if(strcmp(k,j)==0)
    {
      strcpy(metodoactual,Tabla_Simbolos[ia].tipo);    
    }
  }
  

  
  strcpy($<logica>$->tmpo,"t");
  sprintf(str, "%d", tmp);tmp++;
  strcat($<logica>$->tmpo,str);
  strcat($<logica>$->tmpo,"=P+");
  sprintf(st1r, "%d", PosSimbolo($<string>1));
  strcat($<logica>$->tmpo,st1r);strcat($<logica>$->tmpo,"\n");
  sprintf(str3, "%d", tmp);tmp++;
  strcat($<logica>$->tmpo,"t");strcat($<logica>$->tmpo,str3);
  strcat($<logica>$->tmpo,"= Stack[t");
  strcat($<logica>$->tmpo,str);
  strcat($<logica>$->tmpo,"]\n");
  strcpy($<logica>$->verdaderas,"Stack[t");
  strcat($<logica>$->verdaderas,str);
  strcat($<logica>$->verdaderas,"]");
  strcpy($<logica>$->falsas,"t");
  strcat($<logica>$->falsas,str3);
  
  
}
;

sentencia_if: IF DOSPUNTOS PAA ExpLog PAC LLA list_sentencia LLC list_else
{

              strcat($<string>$,$4->tmpo);strcat($<string>$,"\n");
              strcat($<string>$,$4->verdaderas);strcat($<string>$,"\n");
              strcat($<string>$,$<string>7);strcat($<string>$,"\n");
              strcat($<string>$,$4->falsas);strcat($<string>$,"\n");
              strcat($<string>$,$<string>9);strcat($<string>$,"\n");
              printf("\n\n\n%s\n\n\n",$<string>$);
};

list_else: list_else ELSE LLA list_sentencia LLC{strcat($<string>$,$<string>4);strcat($<string>$,"\n");}
            |list_else ELSEIF PAA ExpLog PAC LLA list_sentencia LLC
            {
              strcat($<string>$,$4->tmpo);strcat($<string>$,"\n");
              strcat($<string>$,$4->verdaderas);strcat($<string>$,"\n");
              strcat($<string>$,$7);strcat($<string>$,"\n");
              strcat($<string>$,$4->falsas);strcat($<string>$,"\n");
            }
            |{strcpy($<string>$,"");}; 

sentencia_case_of: CASE {salidaactual++;salidaciclo[salidaactual]=lbl;lbl++;} PAA E PAC OF list_case ECSE 
{
  char qwe[1000];char zxc[1000];
  int i;
  for(i=0; i<caso;i++)
  {
    if(ParaCase[i].cond==0)
    {
      strcat(qwe,"goto L");char str[100];sprintf(str, "%d", lbl);strcat(qwe,str);strcat(qwe,"\n");  
      strcat(zxc,"L");strcat(zxc,str);strcat(zxc,":\n");strcat(zxc,ParaCase[i].tmpo);strcat(zxc,"\n");
      strcat(zxc,"goto L");sprintf(str, "%d", salidaciclo[salidaactual]);
      strcat(zxc,str);strcat(zxc,"\n");lbl++;
    }
    else 
    {
      strcat(qwe,"if (");strcat(qwe,$<string>4);strcat(qwe,"==");strcat(qwe,ParaCase[i].condicion);strcat(qwe,") goto L");
      char str[100];sprintf(str, "%d", lbl);strcat(qwe,str);strcat(qwe,"\n");
      strcat(zxc,"L");strcat(zxc,str);strcat(zxc,":\n");strcat(zxc,ParaCase[i].tmpo);strcat(zxc,"\n");
      strcat(zxc,"goto L");sprintf(str, "%d", salidaciclo[salidaactual]);
      strcat(zxc,str);strcat(zxc,"\n");lbl++;
    }
    
  }
  strcat(zxc,"L");
    char str[100];
    sprintf(str, "%d", salidaciclo[salidaactual]);
    strcat(qwe,"goto L");strcat(qwe,str);strcat(qwe,"\n");
    strcat(zxc,str);strcat(zxc,":\n");
    strcat(qwe,"\n");
    strcat(qwe,zxc);
    strcpy($<string>$,qwe);
    caso =0;
    salidaactual--;
    printf("\n\n\n\n\n\n\n\n%s\n\n\n\n\n\n\n\n",$<string>$ );

};

list_case: list_case E DOSPUNTOS list_sentencia
          {
            ParaCase[caso].cond=1;
            strcpy(ParaCase[caso].condicion,$<string>2);
            strcpy(ParaCase[caso].tmpo,$<string>4);caso++;
            printf("%d\n",caso );
          }
          |list_case OTHERWISE DOSPUNTOS list_sentencia
          {
            ParaCase[caso].cond=0;
            strcpy(ParaCase[caso].tmpo,$<string>4);caso++;
          }
          |;

sentencia_break:BREAK PTOCOMA
{
  strcpy($$,"goto L");char str[100];sprintf(str, "%d", salidaciclo[salidaactual]);
  strcat($$,str);strcat($$,"\n");
};
sentencia_continue:CONTINUE PTOCOMA{
  strcpy($$,"goto L");char str[100];sprintf(str, "%d", retornociclo[retornoactual]);
  strcat($$,str);strcat($$,"\n"); 
  
};
sentencia_while: WHILE{salidaactual++;retornoactual++;retornociclo[retornoactual]=lbl;salidaciclo[salidaactual]=lbl+1;lbl++;lbl++;} PAA ExpLog PAC LLA list_sentencia LLC
{
  $$=malloc(sizeof(Logica));
  strcpy($$->tmpo,"L");char str[100];sprintf(str, "%d", retornociclo[retornoactual]); 
  strcat($$->tmpo,str);strcat($$->tmpo,":\n");strcat($$->tmpo,$4->tmpo);strcat($$->tmpo,$4->verdaderas);strcat($$->tmpo,"\n");
  strcat($$->tmpo,$7);strcat($$->tmpo,"\ngoto L");strcat($$->tmpo,str);strcat($$->tmpo,"\n");
  strcat($$->tmpo,$4->falsas);strcat($$->tmpo,"L");sprintf(str, "%d", salidaciclo[salidaactual]);
  strcat($$->tmpo,str);strcat($$->tmpo,":\n");
  printf("----------------\n%s\n",$$->tmpo);
 salidaactual--;retornoactual--;
};

sentencia_do_while:DO {salidaactual++;retornoactual++;retornociclo[retornoactual]=lbl;salidaciclo[salidaactual]=lbl+1;lbl++;lbl++;}LLA list_sentencia LLC WHILE PAA ExpLog PAC
{
  $$=malloc(sizeof(Logica));
  strcpy($$->tmpo,"L");char str[100];sprintf(str, "%d", retornociclo[retornoactual]); 
  strcat($$->tmpo,str);strcat($$->tmpo,":\n");strcat($$->tmpo,$4);strcat($$->tmpo,"\n");strcat($$->tmpo,$8->tmpo);strcat($$->tmpo,$8->verdaderas);
  strcat($$->tmpo,"\ngoto L");strcat($$->tmpo,str);strcat($$->tmpo,"\n");
  strcat($$->tmpo,$8->falsas);strcat($$->tmpo,"L");sprintf(str, "%d", salidaciclo[salidaactual]);
  strcat($$->tmpo,str);strcat($$->tmpo,":\n");
  printf("----------------\n%s\n",$$->tmpo);
 salidaactual--;retornoactual--;
};

sentencia_repeat_until: REPEAT {salidaactual++;retornoactual++;retornociclo[retornoactual]=lbl;salidaciclo[salidaactual]=lbl+1;lbl++;lbl++;} 
LLA list_sentencia LLC UNTIL PAA ExpLog PAC{
  $$=malloc(sizeof(Logica));
  strcpy($$->tmpo,"L");char str[100];sprintf(str, "%d", retornociclo[retornoactual]); 
  strcat($$->tmpo,str);strcat($$->tmpo,":\n");strcat($$->tmpo,$4);strcat($$->tmpo,"\n");strcat($$->tmpo,$8->tmpo);strcat($$->tmpo,$8->falsas);
  strcat($$->tmpo,"\ngoto L");strcat($$->tmpo,str);strcat($$->tmpo,"\n");
  strcat($$->tmpo,$8->verdaderas);strcat($$->tmpo,"L");sprintf(str, "%d", salidaciclo[salidaactual]);
  strcat($$->tmpo,str);strcat($$->tmpo,":\n");
  printf("----------------\n%s\n",$$->tmpo);
 salidaactual--;retornoactual--;
};

sentencia_loop:LOOP {salidaactual++;retornoactual++;retornociclo[retornoactual]=lbl;salidaciclo[salidaactual]=lbl+1;lbl++;lbl++;} 
LLA list_sentencia LLC{
  $$=malloc(sizeof(Logica));
  strcpy($$->tmpo,"L");char str[100];sprintf(str, "%d", retornociclo[retornoactual]); 
  strcat($$->tmpo,str);strcat($$->tmpo,":\n");strcat($$->tmpo,$4);strcat($$->tmpo,"\n");
  strcat($$->tmpo,"\ngoto L");strcat($$->tmpo,str);strcat($$->tmpo,"\n");
  strcat($$->tmpo,"L");sprintf(str, "%d", salidaciclo[salidaactual]);
  strcat($$->tmpo,str);strcat($$->tmpo,":\n");
  printf("----------------\n%s\n",$$->tmpo);
 salidaactual--;retornoactual--;
};

sentencias_control:sentencia_if|sentencia_case_of|sentencia_do_while
|sentencia_while;


Exp: E {$$=malloc(sizeof(Logica));strcpy($$->tmpo,$1);}
      |ExpLog{$$=$1;};

E :    NUMERO { strcpy($$,$1);} 
      |listobj
      
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
        TTRUE{strcpy($$,"1");}
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
        strcpy($$->tmpo,todo);strcpy(todo,"");
        strcat($$->tmpo,$1->tmpo);strcat($$->tmpo,"\n");
        strcat($$->tmpo,$1->verdaderas);strcat($$->tmpo,"\n");
        strcat($$->tmpo,$3->tmpo);strcat($$->tmpo,"\n");
        strcpy($$->verdaderas,$3->verdaderas);
        strcpy($$->falsas,$1->falsas);
        strcat($$->falsas,$3->falsas);
      }
      |ExpLog  OR  ExpLog{
        $$=malloc(sizeof(Logica));
        strcpy($$->tmpo,todo);strcpy(todo,"");
        strcat($$->tmpo,$1->tmpo);strcat($$->tmpo,"\n");
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
        strcpy($$->tmpo,todo);strcpy(todo,"");
        strcat($$->tmpo,$1->tmpo);strcat($$->tmpo,"\n");
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
        strcpy($$->tmpo,todo);strcpy(todo,"");
        strcat($$->tmpo,$2->tmpo);
        strcpy($$->verdaderas,$2->falsas);
        strcpy($$->falsas,$2->verdaderas);
        


      }
      |PAA ExpLog PAC  {
        $$=malloc(sizeof(Logica));
        strcpy($$->tmpo,todo);strcpy(todo,"");
        strcat($$->tmpo,$2->tmpo);
        strcpy($$->verdaderas,$2->verdaderas);
        strcpy($$->falsas,$2->falsas);  
      }
      |ExpRel {
        $$=malloc(sizeof(Logica));
        strcpy($$->tmpo,todo);strcpy(todo,"");
        strcat($$->tmpo,"if(");strcat($$->tmpo,$1);strcat($$->tmpo,") goto L");
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