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
        Integer idGame;
        String throwaway;

        ArrayList<Integer> winning = new ArrayList<Integer>();
        int timesIWon = 0;
        int ret = 0;
        HashMap<Integer, Integer> copies =  new HashMap<Integer, Integer>();
        for(int i = 1; i <= NB_GAMES; ++i) copies.put(i, 1);
        try {
            Scanner sc = new Scanner(new File("(...)\\input.txt"));
            while(sc.hasNextLine()){
                sc.next();
                throwaway = removeLastChar(sc.next());
                idGame = Integer.parseInt(throwaway);
                for(int i = 0 ; i < WIN_NUMS; ++i){
                    winning.add(sc.nextInt());
                }
                sc.next();

                for(int i = 0; i < BET_NUMS; ++i){
                    if(winning.contains(sc.nextInt())) timesIWon++;
                }
                for(int i = 1; i <= timesIWon; ++i){
                    int repeats = copies.get(idGame);
                    if(idGame + i <= 213)copies.put(idGame+i, copies.get(idGame+i) + 1 * repeats) ;
                }
                //System.out.println("tarjeta " + idGame + " ha ganado " + timesIWon);

                //System.out.println("game " + idGame + " sin problemas ");
                timesIWon = 0;
                winning.clear();
            }
            for(int i = 1; i <= copies.size(); ++i){
                ret += copies.get(i);
            }
            System.out.println("Total scratchcards in the end:" + ret);

        }
        catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }

        }
}
