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
            String s = new String();
            while(sc.hasNextInt()){
                s += sc.next();//we append the values to our string
            }
            Integer time = Integer.parseInt(s);//when we have the string complete, we parse the integer value of it 

            sc.next();//ignore "Distance: "

            s = new String();//we reset the string
            while(sc.hasNext()){
                s += sc.next();//append the value to the string
            }
            Long distance = Long.parseLong(s);//We parse the long from the string
            //System.out.println(time + " " + distance);
            int ways = 0;//Counter
            for(long i = 0; i <= time; ++i){//for each possible amount of time we have the button held
                if(i*(time-i) > distance) {
                    ways++;//if our velocity(i) multiplied by the time we have (time-i) is greater than bestScore, we just found a way we can win.
                    //System.out.println("el game " + curRace + " gana aguantando el boton "+i+"ms."); //Debug
                } 
            }
            System.out.println("Formas distintas: " + ways);//Return the solution
        }
        catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }

    }
}
