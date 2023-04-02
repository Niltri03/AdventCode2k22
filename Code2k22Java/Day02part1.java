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
                if (j.equals("X")) {//you chose Rock
                    puntuacion += 1;
                    puntuacion += 3;

                }
                if (j.equals("Y")) {//you chose Paper
                    puntuacion += 2;
                    puntuacion += 6;
                }
                if (j.equals("Z")) {//you chose Scissors
                    puntuacion += 3;
                    puntuacion += 0;
                }
            }
            else if(i.equals("B")){//opponent chooses Paper
                String j = sc.next();
                if (j.equals("X")) {//you chose Rock
                    puntuacion += 1;
                    puntuacion += 0;
                }
                if (j.equals("Y")) {//you chose Paper
                    puntuacion += 2;
                    puntuacion += 3;
                }
                if (j.equals("Z")) {//you chose Scissors
                    puntuacion += 3;
                    puntuacion += 6;
                }
            }
            else if(i.equals("C")){//opponent chooses scissors
                String j = sc.next();
                if (j.equals("X")) {//you chose Rock
                    puntuacion += 1;
                    puntuacion += 6;
                }
                if (j.equals("Y")) {//you chose Paper
                    puntuacion += 2;
                    puntuacion += 0;
                }
                if (j.equals("Z")) {//you chose Scissors
                    puntuacion += 3;
                    puntuacion += 3;
                }
            }

        }

    }
    public static void main(String[] args) throws FileNotFoundException {


        try{
            Scanner sc = new Scanner(new File(" /* path */ data.txt"));
            ejecuta(sc);
        }
        catch(FileNotFoundException ex)
        {
            exit(0);
        }



    }
}

