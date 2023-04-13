//No.3
import javax.swing.JOptionPane;

public class Num3 {
    public static void main(String[] args) {
        //Propmt to ask for 3 integers
        int num1 = Integer.parseInt(JOptionPane.showInputDialog("Enter 1st integer: "));
        int num2 = Integer.parseInt(JOptionPane.showInputDialog("Enter 2nd integer: "));
        int num3 = Integer.parseInt(JOptionPane.showInputDialog("Enter 3rd integer: "));
        //Variables to store the sum, average, product, smallest and largest of the numbers
        int sum = num1 + num2 + num3;
        int average = sum / 3;
        int product = num1 * num2 * num3;
        int smallest = num1;
        int largest = num1;
        //If statements to find the smallest and largest
        if (num2 < smallest) {
            smallest = num2;
        }
        if (num3 < smallest) {
            smallest = num3;
        }
        if (num2 > largest) {
            largest = num2;
        }
        if (num3 > largest) {
            largest = num3;
        }
        //Display the sum, average, product, smallest and largest of the numbers
        JOptionPane.showMessageDialog(null, "Sum is " + sum );
        JOptionPane.showMessageDialog(null," Average is " + average);
        JOptionPane.showMessageDialog(null," Product is " + product);
        JOptionPane.showMessageDialog(null," Smallest is " + smallest);
        JOptionPane.showMessageDialog(null," Largest is " + largest);
    }
}