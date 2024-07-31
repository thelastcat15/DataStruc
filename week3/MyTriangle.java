/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author studentcs
 */

import java.lang.Math; 


public class MyTriangle {
    public boolean isValid(double side1, double side2, double side3) {
        return side1 + side2 > side3;
    }

    public double area(double side1, double side2, double side3) {
        double s = (side1 + side2 + side3)/2;
        return Math.sqrt(s*(s - side1)*(s - side2)*(s - side3));
    }
    public static void main(String[] args) {
        MyTriangle Func = new MyTriangle();
        int a[] = {1,2,3};
        if (Func.isValid(a[0], a[1], a[2])) {
            System.out.println(1);
            double size = Func.area(a[0], a[1], a[2]);
            System.out.println("Size : "+size);
        } else {
            System.out.println(0);
        }
    }
}
