//* ------------Sección codigo-usuario -------- */
package servicio1deco;
import java_cup.runtime.*;
%%
/*- Sección de opciones y declaraciones -*/
/*-OPCIONES --*/
/* Nombre de la clase generada para el analizador lexico */
%class Lexico_Config
/* Indicar funcionamiento autonomo*/
%standalone
%8bit
/* Acceso a la columna y fila actual de analisis CUP */
%line
%column
/* Habilitar la compatibilidad con el interfaz CUP para el generador sintactico*/
%cup
/*-- DECLARACIONES --*/
%{/*Crear un nuevo objeto java_cup.runtime.Symbol con información sobre el token actual sin valor*/
 
  private Symbol symbol(int type){
    return new Symbol(type,yyline,yycolumn);
  }
/* Crear un nuevo objeto java_cup.runtime.Symbol con información sobre el token actual con valor*/
  private Symbol symbol(int type,Object value){
    return new Symbol(type,yyline,yycolumn,value);
  }
%}
/*-- MACRO DECLARACIONES --*/
LineTerminator = \r|\n|\r\n
WhiteSpace     = {LineTerminator} | [ \t\f]
//finConversion	= [,;]
letra = [a-zA-ZñÑáéíóúÁÉÍÓÚ]
digito = [0-9]
entero = {digito}+
identi = {letra}({letra}|{digito}|"_")*



%%
/*-------- Sección de reglas lexicas ------ */
<YYINITIAL> {

"."	{ return symbol(sym.PUNTO);}
","	{ return symbol(sym.COMA);}
";"	{ return  symbol(sym.PUNTOCOMA);}
":"	{ return  symbol(sym.DOSPUNTOS); }
"["	{ return  symbol(sym.COAB); }
"]"	{ return  symbol(sym.COCI); }
"{"	{ return  symbol(sym.LLA); }
"}"	{ return  symbol(sym.LLC); }
"("	{ return  symbol(sym.PA); }
")"	{ return  symbol(sym.PC); }
":="	{ return  symbol(sym.DOSIGUAL); }


"string"	{ return  symbol(sym.tstring); }
"char"	{ return  symbol(sym.tchar); }
"double"	{ return  symbol(sym.tdouble); }
"int"	{ return  symbol(sym.tint); }
"bool"	{ return  symbol(sym.tbool); }
"return"	{ return  symbol(sym.RETURN); }
"break"	{ return  symbol(sym.BREAK); }
"continue"	{ return  symbol(sym.CONTINUE); }
"true"	{ return  symbol(sym.TTRUE); }
"false"	{ return  symbol(sym.TFALSE); }
"=="	{ return  symbol(sym.IGUALIGUAL); }
"!="	{ return  symbol(sym.DIF); }
">"	{ return  symbol(sym.MAYOR); }
"<"	{ return  symbol(sym.MENOR); }
">="	{ return  symbol(sym.MAYORIGUAL); }
"+"	{ return  symbol(sym.MAS); }
"-"	{ return  symbol(sym.MENOS); }
"*"	{ return  symbol(sym.POR); }
"/"	{ return  symbol(sym.DIV); }
"="	{ return  symbol(sym.IGUAL); }
"&&"	{ return  symbol(sym.AND); }
"||"	{ return  symbol(sym.OR); }
"??"	{ return  symbol(sym.XOR); }
"!!"	{ return  symbol(sym.NOT); }


"OF"	{ return  symbol(sym.OF); }
"IF"	{ return  symbol(sym.IF); }
"THEN"	{ return  symbol(sym.THEN); }
"ELSE"	{ return  symbol(sym.ELSE); }
"ELSEIF"	{ return  symbol(sym.ELSEIF); }
"CASE"	{ return  symbol(sym.CASE); }
"WHILE"	{ return  symbol(sym.WHILE); }
"DO"	{ return  symbol(sym.DO); }
"REPEAT"	{ return  symbol(sym.REPEAT); }
"UNTIL"	{ return  symbol(sym.UNTIL); }
"LOOP"	{ return  symbol(sym.LOOP); }
"SELECT"	{ return  symbol(sym.SELECT); }

"MAIN"  {return symbol(sym.TMAIN);}
"FUNCTION"	{ return  symbol(sym.FUNCTION); }
"PROGRAM"	{ return  symbol(sym.PROGRAM); }
"PROCEDURE"	{ return  symbol(sym.PROCEDURE); }
"VAR"	{ return  symbol(sym.VAR); }
"USES"	{ return  symbol(sym.USES); }
"BEGIN"	{ return  symbol(sym.BEGIN); }
"END"	{ return  symbol(sym.END); }
{entero} {return new Symbol(sym.NUMERO,yychar, yyline, yytext());}

{identi} {return new Symbol(sym.ID,yychar, yyline, yytext());    }

 
{WhiteSpace}	{ }
. {System.out.println("Error Lexico <" + yytext()+ ">En la linea " + (yyline+1) + " Columna " + (yycolumn+1));}
}