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
        int minR = 0;
        int minB = 0;
        int minG = 0;
        int curR = 0;
        int curB = 0;
        int curG = 0;
        ArrayList<Integer> results = new ArrayList<Integer>();
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
                while(imNotDone && sc.hasNext()) {

                        aux = Integer.parseInt(sc.next());
                        throwaway = sc.next();
                        char auxC = throwaway.charAt(0);
                        if(auxC == 'g') curG += aux;
                        else if(auxC == 'b') curB += aux;
                        else curR += aux;
                        /*System.out.println("añado " + aux + " a " + auxC);
                        System.out.println("Veo RGB:"+curR+"/"+curB+"/"+curG);*/
                        if(throwaway.charAt(throwaway.length()-1) == ';'){

                                if (curG > minG) {
                                    minG = curG;
                                    //System.out.println("ming = " + curG);
                                }
                                if (curR > minR) {
                                    minR = curR;
                                    //System.out.println("minr = " + curR);
                                }
                                if (curB > minB) {
                                    minB = curB;
                                    //System.out.println("minb = " + curB);
                                }
                                curG = curR = curB = 0;
                        }


                        else if(throwaway.charAt(throwaway.length()-1) == ','){

                        }
                        else{
                            if (curG > minG) minG = curG;
                            if (curR > minR) minR = curR;
                            if (curB > minB) minB = curB;
                            imNotDone = false;


                        }

                }


                System.out.println("En game " + idGame + " veo RGB:"+minR+"/"+minB+"/"+minG);
                int add = minR*minG*minB;
                results.add(add);
                curG = curR = curB = minG = minR = minB = 0;
                if(sc.hasNextLine())sc.nextLine();
                imNotDone = true;

            }
            //System.out.println(results.size());
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
