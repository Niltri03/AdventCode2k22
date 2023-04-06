//part 2 not working, part 1 works fine 
import java.util.*;
import java.io.*;

import static java.lang.System.exit;



public class Main {
    //static int numeroMagic = 5;
    static int numeroMagic = 5;
    static int[][] matrix = new int[numeroMagic][numeroMagic]; //uncomment to solve



    public static boolean evaluate1(int x, int y){

        if(x == 0 || x == numeroMagic - 1 || y == 0 || y == numeroMagic - 1) {
            return true;
        }
        else {
            boolean[] soFar = { true, true, true, true };
            for(int i = x; i < numeroMagic; ++i){
                if(i != x) if(matrix[i][y] >= matrix[x][y]) soFar[0] = false;
            }
            for(int i = x; i >= 0; --i){
                if(i != x) if(matrix[i][y] >= matrix[x][y]) soFar[1] = false;
            }
            for(int i = y; i < numeroMagic; ++i){
                if(i != y) if(matrix[x][i] >= matrix[x][y]) soFar[2] = false;
            }
            for(int i = y; i >= 0; --i){
                if(i != y) if(matrix[x][i] >= matrix[x][y]) soFar[3] =  false;
            }
            if(soFar[0] || soFar[1] || soFar[2] || soFar[3]) return true;
            return false;
        }
    }

    public static int evaluate2(int x, int y){
        int ret = 0;
        int aux = 1;

        //Primero evaluamos mirar hacia la derecha. Si no puede, es cero.
        if(x == numeroMagic-1 || x == 0 || y == numeroMagic-1 || y == 0) return 0;
        for(int i = x; i < numeroMagic; ++i){
            if(i == x);
            else {
                if(matrix[i][y] >= matrix[x][y]) i = numeroMagic;
                else aux++;
            }
        }
        ret += aux;
        aux = 1;
        for(int i = x; i >= 0; --i){
            if(i == x);
            else {
                if(matrix[i][y] >= matrix[x][y]) i = -1;
                else aux++;
            }
        }
        ret *= aux;
        aux = 1;
        for(int i = y; i < numeroMagic; ++i){
            if(i == y);
            else {
                if(matrix[x][i] >= matrix[x][y]) i = numeroMagic;
                else aux++;
            }
        }
        ret *= aux;
        aux = 1;
        for(int i = y; i >= 0; --i){
            if(i == y);
            else {
                if(matrix[x][i] >= matrix[x][y]) i = -1;
                else aux++;
            }
        }
        ret *= aux;
        System.out.println("Evaluo la posicion: x="+x+", y="+y+", ("+matrix[x][y]+"), con una puntuacion de "+ret);
        return ret;
    }
    public static void ejecuta(Scanner sc){

        int auxi = 0;
        String s = "";
        while(sc.hasNext()){
            s = sc.next();
            for(int j = 0; j < s.length(); ++j){
                Character c = s.charAt(j);
                matrix[auxi][j] = c - '0';
            }
            auxi++;


        }
        int contador = 0;
        int prevBest = 0;
        for(int i = 0; i < numeroMagic; ++i){
            for(int j = 0; j < numeroMagic; ++j){
                if(evaluate1(i, j)) contador++;
                int a = evaluate2(i, j);
                if(a > prevBest) prevBest = a;
            }
        }
        System.out.println(contador + " high points");
        System.out.println("Highest possible score: " + prevBest);
    }

    public static void main(String[] args) throws FileNotFoundException  {



        try{
        Scanner sc = new Scanner(new File("C:\\Users\\Nacho\\Documents\\programas\\Java\\helloWorld\\src\\data.txt"));
        ejecuta(sc);
        }
        catch(FileNotFoundException ex)
        {
        exit(0);
        }
    }
}


