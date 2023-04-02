import java.util.*;
import java.io.*;

import static java.lang.System.exit;


public class Main {

    public static void ejecuta(Scanner sc){
        Integer puntuacion = 0;
        while (sc.hasNext()) {
            String i = sc.next();
            final int mid = i.length() / 2; //get the middle of the String
            String[] parts = {i.substring(0, mid),i.substring(mid)};
            for(int it = 0; it < parts[0].length(); ++it){
                for(int jt = 0; jt < parts[1].length(); ++jt){
                    if(parts[0].charAt(it) == parts[1].charAt(jt)){
                        Character c = parts[0].charAt(it);
                        jt = i.length();
                        it = i.length();
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
            Scanner sc = new Scanner(new File(" /*Path*/ data.txt"));
            ejecuta(sc);
        }
        catch(FileNotFoundException ex)
        {
            exit(0);
        }



    }
}

