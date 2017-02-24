/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servicio1deco;

import java.io.BufferedReader;
import java.io.File;
import java.io.StringReader;

/**
 *
 * @author ricky
 */
public class servicio1deco 
{
    

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
    String lexico_config = "/home/ricky/Escritorio/Compiladores2/Servicio1Deco/src/servicio1deco/Config.flex";
    generarCupConfig();
    generarFlex(lexico_config);
    Sintactico_Config aa= new Sintactico_Config(new Lexico_Config(new BufferedReader(new StringReader("PROGRAM JJ: PROCEDURE pp() BEGIN  END MAIN BEGIN pp(3); END"))));
    aa.parse();
    String salida=aa.action_obj.salida;
    int a=0;
    
    }
    public static void generarFlex(String path){
        File file=new File(path);
        jflex.Main.generate(file);
    }
    public static void generarCupConfig(){
        String opciones[] = new String[5];
        opciones[0]="-destdir";
        opciones[1]="src"
                +File.separator+
                "servicio1deco";
        opciones[2]="-parser";
        opciones[3]="Sintactico_Config";
        opciones[4]="src"
                +File.separator+
                "servicio1deco"
                +File.separator+
                "Config.cup";
        try {
            java_cup.Main.main(opciones);
            }
        catch (Exception e) {
            System.out.print(e);
            }
    }
    
}
