import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import static java.lang.Math.pow;

public class Main {
    static int WIN_NUMS = 10; //5 testing, 10 input
    static int BET_NUMS = 25; //8 testing, 25 input

    public static String removeLastChar(String s) {
        return (s == null || s.length() == 0)
                ? null
                : (s.substring(0, s.length() - 1));
    }


    public static void main(String[] args) {
        Integer idGame;
        String throwaway;

        ArrayList<Integer> winning = new ArrayList<Integer>();
        int timesIWon = 0;
        int ret = 0;
        

        try {
            Scanner sc = new Scanner(new File("C:\\Users\\Nacho\\Documents\\programas\\Java\\adventOfCode\\src\\input.txt"));
            while(sc.hasNextLine()){
                sc.next();
                throwaway = sc.next();
                throwaway = removeLastChar(throwaway);
                idGame = Integer.parseInt(throwaway);
                for(int i = 0 ; i < WIN_NUMS; ++i){

                    //Integer aux = new Integer(sc.nextInt());
                    winning.add(sc.nextInt());
                }
                sc.next();

                for(int i = 0; i < BET_NUMS; ++i){
                    if(winning.contains(sc.nextInt())) timesIWon++;
                }
                //System.out.println("tarjeta " + idGame + " ha ganado " + timesIWon);
                ret += pow(2,timesIWon-1);
                timesIWon = 0;
                winning.clear();
            }
            System.out.println("Result: " + ret);

        }
        catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }

        }
}
