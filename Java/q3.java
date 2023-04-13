import java.util.Scanner;

public class q3
{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num1, num2, num3;
        //Ask for num 1
        System.out.print("Enter 1st integer: ");
        num1 = input.nextInt();
        //Ask for num 2
        System.out.print("Enter 2nd integer: ");
        num2 = input.nextInt();
        //Ask for num 3
        System.out.print("Enter 3rd integer: ");
        num3 = input.nextInt();
        //Calling of display functions
        getSum(num1, num2, num3);
        getAverage(num1, num2, num3);
        getProduct(num1, num2, num3);
        getSmallest(num1, num2, num3);
        getLargest(num1, num2, num3);
    }
    public static void getSum(int num1, int num2, int num3){
        int sum = num1 + num2 + num3;
        //print sum 
        System.out.println("The sum is " + sum);
    }
    public static void getAverage(int num1, int num2, int num3){
        int average = (num1 + num2 + num3)/3;
        //print average 
        System.out.println("The average is " + average);
    }
    public static void getProduct(int num1, int num2, int num3){
        int product = num1 * num2 * num3;
        //print product 
        System.out.println("The product is " + product);
    }
    public static void getSmallest(int num1, int num2, int num3){
        int smallest = num1;
        if(num2 < smallest){
            smallest = num2;
        }
        if(num3 < smallest){
            smallest = num3;
        }
        //print smallest 
        System.out.println("The smallest is " + smallest);
    }
    public static void getLargest(int num1, int num2, int num3){
        int largest = num1;
        if(num2 > largest){
            largest = num2;
        }
        if(num3 > largest){
            largest = num3;
        }
        //print largest 
        System.out.println("The largest is " + largest);
    }
}
