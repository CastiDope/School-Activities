import javax.swing.*;

public class num3test
{
    public static void main(String[] args) {
        String asknum1, asknum2, asknum3;
        int num1, num2, num3;
        //Ask for num 1
        asknum1=JOptionPane.showInputDialog(null, 
                "Enter three numbers","1st number", 
                JOptionPane.QUESTION_MESSAGE);
        num1=Integer.parseInt(asknum1);
        //Ask for num 2
        asknum2=JOptionPane.showInputDialog(null, 
                "Enter three numbers","2nd number", 
                JOptionPane.QUESTION_MESSAGE);
        num2=Integer.parseInt(asknum2);
        //Ask for num 3
        asknum3=JOptionPane.showInputDialog(null, 
                "Enter three numbers?","3rd number", 
                JOptionPane.QUESTION_MESSAGE);
        num3=Integer.parseInt(asknum3);
        //Calling of diplays
        displaySum(num1, num2, num3);
        displayAverage(num1, num2, num3);
        displayProduct(num1, num2, num3);
        displaySmallest(num1, num2, num3);
        displayLargest(num1, num2, num3);
    }
    public static void displaySum(int num1, int num2, int num3){
        int sum = num1 + num2 + num3;
        //show sum 
        JOptionPane.showMessageDialog(null,"The sum is " + sum);

    }
    public static void displayAverage(int num1, int num2, int num3){
        int average = (num1 + num2 + num3)/3;
        //show average 
        JOptionPane.showMessageDialog(null,"The average is " + average);
    }
    public static void displayProduct(int num1, int num2, int num3){
        int product = num1 * num2 * num3;
        //show product 
        JOptionPane.showMessageDialog(null,"The product is " + product);
    }
    public static void displaySmallest(int num1, int num2, int num3){
        int smallest = num1;
        if(num2 < smallest){
            smallest = num2;
        }
        if(num3 < smallest){
            smallest = num3;
        }
        //show smallest 
        JOptionPane.showMessageDialog(null,"The smallest is " + smallest);
    }
    public static void displayLargest(int num1, int num2, int num3){
        int largest = num1;
        if(num2 > largest){
            largest = num2;
        }
        if(num3 > largest){
            largest = num3;
        }
        //show largest 
        JOptionPane.showMessageDialog(null,"The largest is " + largest);
    }
}
