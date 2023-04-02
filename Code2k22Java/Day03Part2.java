import java.util.*;
import java.io.*;

import static java.lang.System.exit;


public class Main {

    public static void ejecuta(Scanner sc){
        Integer puntuacion = 0;
        while (sc.hasNext()) {
            String[] parts = {"","",""};
            parts[0] = sc.next();
            parts[1] = sc.next();
            parts[2] = sc.next();
            String i2 = "";
            for(int x = 0; x < parts[0].length(); ++x){
                for(int y = 0; y < parts[1].length(); ++y){
                    if(parts[0].charAt(x) == parts[1].charAt(y)){
                        i2 += parts[0].charAt(x);
                    }
                }
            }


            for(int it = 0; it < i2.length(); ++it){
                for(int jt = 0; jt < parts[2].length(); ++jt){
                    if(i2.charAt(it) == parts[2].charAt(jt)){
                        Character c = i2.charAt(it);
                        jt = parts[2].length();
                        it = i2.length();
                        System.out.println(c);
                        if(c <= 'z' && c >= 'a')puntuacion += c - 'a' + 1;
                        else puntuacion += c - 'A' + 27;
                    }
                }
            }
        }
        System.out.println(puntuacion);
    }
    public static void main(String[] args) throws FileNotFoundException {


        try{
            Scanner sc = new Scanner(new File(/* Path to the data */));
            ejecuta(sc);
        }
        catch(FileNotFoundException ex)
        {
            exit(0);
        }



    }
}

