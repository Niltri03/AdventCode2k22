import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

import static java.lang.Math.pow;



public class Main {

    public static void main(String[] args) {

        String throwaway;

        ArrayList<Integer> times = new ArrayList<Integer>();//saves the time

        try {
            Scanner sc = new Scanner(new File("(...)\\input.txt"));
            sc.next();//ignore "Time:"
            while(sc.hasNextInt()){
                times.add(sc.nextInt());//we keep track of all the times
            }
            sc.next();
            byte curRace = 0;
            int sol = 1;
            while(sc.hasNextInt()){//since the races are in order we don't need to keep all of the highscores
                int bestScore = sc.nextInt();//Distance to beat
                int ways = 0;//Counter
                int time = times.get(curRace);//Time we have to hold down the button
                for(int i = 0; i <= time; ++i){//for each possible amount of time we have the button held
                    if(i*(time-i) > bestScore) {
                        ways++;
                        //System.out.println("el game " + curRace + " gana aguantando el boton "+i+"ms."); //Debug
                    } //if our velocity(i) multiplied by the time we have (time-i) is greater than bestScore, we just found a way we can win.
                }
                curRace++;//add to the tracker
                sol *= ways; //we multiply the number we found by the solution we had previously
            }
            System.out.println("Formas distintas: " + sol);//Return the solution
        }
        catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }

    }
}
