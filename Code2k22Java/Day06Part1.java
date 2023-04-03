import java.util.*;
import java.io.*;

import static java.lang.System.exit;


public class Main {

    public static void main(String[] args){

            Character c1;
            Character c2;
            Character c3;
            Character c4;
            Set<Character> set = new HashSet<Character> ();

            String s = /* String to analyze here */;
            c1 = s.charAt(0);
            c2 = s.charAt(1);
            c3 = s.charAt(2);
            for(int i = 3; i < s.length(); ++i){
                c4 = s.charAt(i);
                set.add(c1);
                set.add(c2);
                set.add(c3);
                set.add(c4);
                if(set.size() == 4) {
                    System.out.println(i+1);
                    exit(0);
                }
                set.clear();
                c1 = c2;
                c2 = c3;
                c3 = c4;
            }
        }


    }


