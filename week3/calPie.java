

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author studentcs
 */
import java.lang.Math; 

public class cal {
    public static double getM(int i) {
        double sum = 0;
        for (int k=1; k<=i; k++) {
            sum += (Math.pow(-1, k+1)) / ((2*k)-1);
        }        

        return 4*sum;
    }
    public static void main(String[] args) {
        double result = getM(1);
        System.out.println("Result : "+result);
    }
}
