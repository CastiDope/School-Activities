//Create a Square class, which declares a side instance variable of type int. Then create a public method called perimeter() that returns the perimeter of the square, and a public area() method that returns the area of the square.create a constructor in the Square class of the Exercise 1, which takes the value of the variable side as input.

public class Square {
    int side;
    public Square(int side){
        this.side=side;
    }
    public int perimeter(){
        return 4*side;
    }
    public int area(){
        return side*side;
    }
    public static void main(String[] args) {
        Square s=new Square(5);
        System.out.println(s.perimeter());
        System.out.println(s.area());
    }
}