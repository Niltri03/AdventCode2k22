import java.util.*;
import java.io.*;

//For this to work, all empty lines have to be replaced with a dash (-). 

import static java.lang.System.exit;


public class Main {

    public static void ejecuta(Scanner sc){
        Integer suma = 0;
        Integer topval1 = 0;
        Integer topval2 = 0;
        Integer topval3 = 0;
        while (sc.hasNext()) {
            String i = sc.next();
            if (i.equals("-")) {
                if (suma > topval1) {
                topval3 = topval2;
                topval2 = topval1;
                topval1 = suma;
            }
                else if (suma > topval2) {
                topval3 = topval2;
                topval2 = suma;
            }

               else if (suma > topval3) {
                    topval3 = suma;
                }

                suma = 0;
            }
            else {

               Integer x = Integer.parseInt(i);

                suma += x;
                System.out.println(i);
                System.out.println("Suma: " + suma);
                System.out.println("Maxval1: " + topval1);
                System.out.println("Maxval2: " + topval2);
                System.out.println("Maxval3: " + topval3);
                Integer sumaTotal = topval1 +topval2+topval3;
                System.out.println("Suma: " + sumaTotal);

            }

        }
    }
    public static void main(String[] args) throws FileNotFoundException {


        try{
            Scanner sc = new Scanner(new File("C:\\Users\\Nacho\\Documents\\programas\\Java\\helloWorld\\src\\data.txt"));
            ejecuta(sc);
        }
        catch(FileNotFoundException ex)
        {
            exit(0);
        }



    }
}

