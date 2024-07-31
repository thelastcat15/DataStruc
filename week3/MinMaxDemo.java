/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package minmaxdemo;

/**
 *
 * @author studentcs
 */
public class MinMaxDemo{
    public static void main(String[] args){
        int a[] = {-128, 65, -235, 99, 0, 26};
        int minIndex = findMinIdx(a);
        System.out.println("min value is a["+minIndex+"] = " + a[minIndex]);
        int maxIndex = findMaxIdx(a);
        System.out.println("min value is a["+maxIndex+"] = " + a[maxIndex]);
        int[] new_arry = BubbleSort(a);
        for(int k=0; k<a.length-1; k++){
            System.out.println(new_arry[k]);
        }
    }
    
    public static int findMinIdx(int[] a){
        int k, minIdx=0;
        for(k=1; k<a.length; k++){
            if(a[k] < a[minIdx]){
                minIdx = k;
            }   
        }
        return minIdx;
    }
    
    public static int findMaxIdx(int[] a){
        int k, maxIdx=0;
        for(k=1; k<a.length; k++){
            if(a[k] > a[maxIdx]){
                maxIdx = k;
            }   
        }
        return maxIdx;
    }
    
    public static int[] BubbleSort(int[] a){
        for(int i=0; i<a.length-1; i++){
            for(int l=0; l<a.length-1; l++){
                if(a[i] < a[l+1]){
                    int temp = a[i];
                    a[i] = a[l];
                    a[l] = temp;
                }   
            } 
        }
        return a;
    }
}
