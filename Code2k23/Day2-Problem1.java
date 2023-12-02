import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static String removeLastChar(String s) {
        return (s == null || s.length() == 0)
                ? null
                : (s.substring(0, s.length() - 1));
    }


    public static void main(String[] args) {
        Integer idGame;
        String throwaway;
        Integer aux;
        int maxR = 12;
        int maxB = 14;
        int maxG = 13;
        int curR = 0;
        int curB = 0;
        int curG = 0;
        ArrayList<Integer> results = new ArrayList<Integer>();
        boolean legalGame=true;
        boolean sameSet=false;
        try {
            Scanner sc = new Scanner(new File("C:\\Users\\Nacho\\Documents\\programas\\Java\\adventOfCode\\src\\input.txt"));
            while(sc.hasNextLine()){
                sc.next();
                throwaway = sc.next();
                throwaway = removeLastChar(throwaway);
                idGame = Integer.parseInt(throwaway);
                System.out.println("Game " + idGame);
                boolean imNotDone = true;
                while(legalGame && imNotDone) {
                        System.out.println("Veo RGB:"+curR+"/"+curB+"/"+curG);
                        aux = Integer.parseInt(sc.next());
                        throwaway = sc.next();
                        char auxC = throwaway.charAt(0);
                        if(auxC == 'g') curG += aux;
                        else if(auxC == 'b') curB += aux;
                        else curR += aux;
                        if((curR > maxR) || (curB > maxB) || (curG > maxG)) {
                            legalGame = false;
                            System.out.println("Illegal");
                        }
                        if(throwaway.charAt(throwaway.length()-1) == ';'){
                                curG = curR = curB = 0;
                        }


                        else if(throwaway.charAt(throwaway.length()-1) == ','){

                        }
                        else{
                            imNotDone = false;
                            
                        }

                }
                if(legalGame) results.add(idGame);
                legalGame = true;
                imNotDone = true;
                curG = curR = curB = 0;
                sc.nextLine();

            }
            System.out.println(results.size());
            int ret = 0;
            for(int i = 0; i < results.size(); ++i){
                ret += results.get(i);
                System.out.println(results.get(i));
            }
            System.out.println("Valor: " + ret);
        }
        catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }

        }
}
