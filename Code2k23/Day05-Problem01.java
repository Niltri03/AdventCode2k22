import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

import static java.lang.Math.pow;

public class Main {
    static int WIN_NUMS = 10; //5 testing, 10 input
    static int BET_NUMS = 25; //8 testing, 25 input
    static int NB_GAMES = 213; //6 testing, 213 input

    public static String removeLastChar(String s) {
        return (s == null || s.length() == 0)
                ? null
                : (s.substring(0, s.length() - 1));
    }


    public static void main(String[] args) {

        String throwaway;

        ArrayList<Long> results = new ArrayList<Long>();//iremos guardando los resultados de las conversiones

        try {
            Scanner sc = new Scanner(new File("C:\\Users\\Nacho\\Documents\\programas\\Java\\adventOfCode\\src\\input.txt"));
            sc.next();
            while(sc.hasNextLong()) {
                results.add(sc.nextLong());
            }
            while(sc.hasNextLine()){
                ArrayList<Long> convertedValues = new ArrayList<>();//Guarda
                ArrayList<Long> originValues = new ArrayList<>();
                ArrayList<Long> limitOrigins = new ArrayList<>();
                //System.out.println(sc.next());
                sc.next(); 
                sc.next();
                while(sc.hasNextLong()){
                    convertedValues.add(sc.nextLong());
                    Long origin = sc.nextLong();
                    originValues.add(origin);
                    limitOrigins.add(sc.nextLong()+origin);

                }
                for(int i = 0; i < results.size(); ++i){
                    Long auxOrigin = results.get(i);
                    for(int j = 0; j < originValues.size(); ++j){
                        if(auxOrigin >= originValues.get(j) && auxOrigin <= limitOrigins.get(j)){
                            Long diff = auxOrigin - originValues.get(j);
                            results.set(i, convertedValues.get(j)+diff );
                        }
                    }
                }
            }
            Long ret = 9223372036854775807L;
            for(int i = 0; i < results.size(); ++i){
                if(results.get(i) < ret) ret = results.get(i);
            }
            System.out.println("Valor mínimo: "+ret );
        }
        catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }

        }
}
