import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

import static java.lang.Math.pow;



public class Main { //SMALLEST SO FAR: 155057073
    public static ArrayList<Long> CASE1 = new ArrayList<Long>(Arrays.<Long>asList(2880930400L,17599561L));//2880930400
    public static ArrayList<Long> CASE2 = new ArrayList<Long>(Arrays.<Long>asList(549922357L, 200746426L));//OOB
    public static ArrayList<Long> CASE3 = new ArrayList<Long>(Arrays.<Long>asList(1378552684L, 43534336L));//1378552684
    public static ArrayList<Long> CASE4 = new ArrayList<Long>(Arrays.<Long>asList(155057073L, 56546377L));//155057073
    public static ArrayList<Long> CASE5 = new ArrayList<Long>(Arrays.<Long>asList(824205101L, 378503603L));//OOB
    public static ArrayList<Long> CASE6 = new ArrayList<Long>(Arrays.<Long>asList(1678376802L, 130912435L));//OOB
    public static ArrayList<Long> CASE7 = new ArrayList<Long>(Arrays.<Long>asList(2685513694L, 137778160L));
    public static ArrayList<Long> CASE8 = new ArrayList<Long>(Arrays.<Long>asList(2492361384L, 188575752L));
    public static ArrayList<Long> CASE9 = new ArrayList<Long>(Arrays.<Long>asList(3139914842L, 1092214826L));
    public static ArrayList<Long> CASEX = new ArrayList<Long>(Arrays.<Long>asList(2989476473L, 58874625L));


    public static void main(String[] args) {

        String throwaway;

        ArrayList<Long> results = new ArrayList<Long>();//iremos guardando los resultados de las conversiones

        try {
            Scanner sc = new Scanner(new File("C:\\Users\\Nacho\\Documents\\programas\\Java\\adventOfCode\\src\\input.txt"));
            sc.next();
            while(sc.hasNextLong()){
                sc.nextLong();
            }
            for(int i = 0; i < CASE8.get(1); ++i){
                results.add(CASE8.get(0)+i);
                System.out.println("hola es iteracion " + i);
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
