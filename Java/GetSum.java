//No. 1
public class GetSum {
    //Class variables
    private int num1;
    private int num2;
    //Constructors
    public void setNum1(int num1) {
        this.num1 = num1;
    }
    public void setNum2(int num2) {
        this.num2 = num2;
    }
    //Method to get the sum of the numbers
    public int getSum() {
        return num1 + num2;
    }
    //Main method to prompt for 2 integers and display their sum
    public static void main(String[] args) {
        GetSum num1 = new GetSum();
        GetSum num2 = new GetSum();
        //Instantiate the class with side values
        num1.setNum1(5);
        num1.setNum2(10);
        num2.setNum1(15);
        num2.setNum2(20);
        //Display the sum of the numbers
        System.out.println("Sum of num1 is: " + num1.getSum());
        System.out.println("Sum of num2 is: " + num2.getSum());
    }
}
