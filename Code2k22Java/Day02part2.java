import java.util.*;
import java.io.*;

import static java.lang.System.exit;


public class Main {

    public static void ejecuta(Scanner sc){
        Integer puntuacion = 0;
        while (sc.hasNext()) {
            String i = sc.next();
            if (i.equals("L")) {
                System.out.println(puntuacion);
            }
            else if(i.equals("A")){//opponent chooses Rock
                String j = sc.next();
                if (j.equals("X")) {//you must lose
                    puntuacion += 0;
                    puntuacion += 3;

                }
                if (j.equals("Y")) {//you must draw
                    puntuacion += 3;
                    puntuacion += 1;
                }
                if (j.equals("Z")) {//you must win
                    puntuacion += 6;
                    puntuacion += 2;
                }
            }
            else if(i.equals("B")){//opponent chooses Paper
                String j = sc.next();
                if (j.equals("X")) {//you must lose
                    puntuacion += 0;
                    puntuacion += 1;
                }
                if (j.equals("Y")) {//you must draw
                    puntuacion += 3;
                    puntuacion += 2;
                }
                if (j.equals("Z")) {//you must win
                    puntuacion += 6;
                    puntuacion += 3;
                }
            }
            else if(i.equals("C")){//opponent chooses scissors
                String j = sc.next();
                if (j.equals("X")) {//you must lose
                    puntuacion += 0;
                    puntuacion += 2;
                }
                if (j.equals("Y")) {//you must draw
                    puntuacion += 3;
                    puntuacion += 3;
                }
                if (j.equals("Z")) {//you must win
                    puntuacion += 6;
                    puntuacion += 1;
                }
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

