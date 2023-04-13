//No. 2
class Square { //2.a
    int sides;
    public static final int SIDES_NUMBER = 4;   //Use this constant for number 2.d
    public int perimeter(){
        //return sides * 4;                     //old parameter
        return sides * SIDES_NUMBER;            //2.d
    }
    public int area(){
        return sides*sides;
    }
}

public class SquareTest { //2.b
    public static void main(String[] args) {
        Square square = new Square();
        square.sides=5; //Added for 2.c
        System.out.println("The square's perimeter is: " + square.perimeter());
        System.out.println("The square's area is: " + square.area());
    }
}