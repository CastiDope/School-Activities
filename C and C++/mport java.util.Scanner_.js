mport java.util.Scanner;

public class Snek 
{

    public static void main(String[] args) {



        Scanner scan = new Scanner(System.in);

        System.out.println("Enter the number of males");
        int x = scan.nextInt();
                System.out.println("Enter the number of females");
        int y = scan.nextInt();
                int totalvalue = x + y;
                float percentagex = (x * 100) / totalvalue;
                float percentagey = (y * 100) / totalvalue;

        System.out.println("The number of students is " + totalvalue);
                System.out.println("The percentage of males is " + percentagex + "%";
                System.out.println("The percentage of males is " + percentagey + "%";
    }

}