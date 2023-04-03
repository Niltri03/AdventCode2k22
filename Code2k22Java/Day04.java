import java.util.*;
import java.io.*;

import static java.lang.System.exit;


public class Main {

    public static void ejecuta(Scanner sc) {
        Integer sumatorioOverlapsTotales = 0;
        Integer sumatorioOverlapsParciales = 0;

        while (sc.hasNext()) {
            
            //Works if the input is an int / line. 
            Integer x1 = sc.nextInt();
            Integer x2 = sc.nextInt();
            Integer y1 = sc.nextInt();
            Integer y2 = sc.nextInt();






           if ((y1 >= x1 && y2 <= x2) || (x1 >= y1 && x2 <= y2)){
                sumatorioOverlapsTotales++;
            }
            if(!(x1 >y2 || y1 > x2)){
                sumatorioOverlapsParciales++;
            }
        }
        System.out.println("Suma overlaps totales: " + sumatorioOverlapsTotales);
        System.out.println("Suma overlaps parciales: " + sumatorioOverlapsParciales);


        }
    public static void main(String[] args) throws FileNotFoundException {


        try{
            Scanner sc = new Scanner(new File(/*path to data*/));
            ejecuta(sc);
        }
        catch(FileNotFoundException ex)
        {
            exit(0);
        }



    }
}

