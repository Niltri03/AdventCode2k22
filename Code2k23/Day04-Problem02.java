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

    public static String removeLastChar(String s) {//remmoves last char of a string 
        return (s == null || s.length() == 0)
                ? null
                : (s.substring(0, s.length() - 1));
    }


    public static void main(String[] args) {
        Integer idGame; //keeps track of what game we're on 
        String throwaway; //for useless pieces of input

        ArrayList<Integer> winning = new ArrayList<Integer>(); //keeps the winning numbers
        int timesIWon = 0;//how many of our numbers were winning
        int ret = 0;//return value 
        HashMap<Integer, Integer> copies =  new HashMap<Integer, Integer>();//keeps track of how many copies of each card we have earned
        for(int i = 1; i <= NB_GAMES; ++i) copies.put(i, 1);//initializes each card at 1 copy 
        try {
            Scanner sc = new Scanner(new File("(...)\\input.txt"));//opens file, replace filename with abs path of imput
            while(sc.hasNextLine()){//for each line 
                sc.next();//we ignore "Card" 
                throwaway = removeLastChar(sc.next());
                idGame = Integer.parseInt(throwaway);//saves the id of the game 
                for(int i = 0 ; i < WIN_NUMS; ++i){//iterate the winning numbers
                    winning.add(sc.nextInt()); //and save them on our arraylist
                }
                sc.next();//ignore "|"

                for(int i = 0; i < BET_NUMS; ++i){//for each of our numbers
                    if(winning.contains(sc.nextInt())) timesIWon++;//checks if it's one of the winning ones 
                }
                for(int i = 1; i <= timesIWon; ++i){
                    int repeats = copies.get(idGame);
                    if(idGame + i <= 213)copies.put(idGame+i, copies.get(idGame+i) + 1 * repeats);//for having N winning numbers, increase the copies of the N following cards by 1. 
                }
                //System.out.println("tarjeta " + idGame + " ha ganado " + timesIWon);

                //System.out.println("game " + idGame + " sin problemas ");
                timesIWon = 0;
                winning.clear();//reset local variables
            }
            for(int i = 1; i <= copies.size(); ++i){
                ret += copies.get(i);//Add up all of our copies 
            }
            System.out.println("Total scratchcards in the end:" + ret); //return solution 

        }
        catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }

        }
}
