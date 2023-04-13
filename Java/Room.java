//Num 2
import javax.swing.JOptionPane;

class Room {
    //Instance variables
    int roomno;
    String roomtype;
    double roomarea;
    String ACmachine;
    //Method to set the room information
    public void setdata(){
        roomno=Integer.parseInt(JOptionPane.showInputDialog("Enter room no"));
        roomtype=JOptionPane.showInputDialog("Enter room type");
        roomarea=Double.parseDouble(JOptionPane.showInputDialog("Enter room area"));
        ACmachine=JOptionPane.showInputDialog("Enter AC machine");
    }
    //Method to display the room information
    public void displaydata(){
        JOptionPane.showMessageDialog(null,"Room no is "+roomno);
        JOptionPane.showMessageDialog(null,"Room type is "+roomtype);
        JOptionPane.showMessageDialog(null,"Room area is "+roomarea);
        JOptionPane.showMessageDial8og(null,"AC machine is "+ACmachine);
    }
    //Main method to create the object and call the methods
    public static void main(String[] args) {
        //Creating instance of the class to access the instance methods
        Room r=new Room();
        r.setdata();
        r.displaydata();
    }
}