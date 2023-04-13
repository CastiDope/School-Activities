//Declare the Student , bus , sports car classes as classes that implement the Printable interface and run the application. The output of this application should be the details of each one of the objects that were instantiated. 

import javax.swing.JOptionPane;

public class Student implements Printable {
    String name;
    int age;
    int id;
    
    public String toString() {
        return "Name: " + name + " Age: " + age + " ID: " + id;
    }
    
    public void print() {
        JOptionPane.showMessageDialog(null, toString());
    }
}

public class Bus implements Printable {
    String name;
    int age;
    int id;
    
    public String toString() {
        return "Name: " + name + " Age: " + age + " ID: " + id;
    }
    
    public void print() {
        JOptionPane.showMessageDialog(null, toString());
    }
}

public class SportsCar implements Printable {
    String name;
    int age;
    int id;
    
    public String toString() {
        return "Name: " + name + " Age: " + age + " ID: " + id;
    }
    
    public void print() {
        JOptionPane.showMessageDialog(null, toString());
    }
}

public class PrintableTest {
    public static void main(String[] args) {
        Student student = new Student();
        student.name = JOptionPane.showInputDialog("Enter name");
        student.age = Integer.parseInt(JOptionPane.showInputDialog("Enter age"));
        student.id = Integer.parseInt(JOptionPane.showInputDialog("Enter id"));
        student.print();
        
        Bus bus = new Bus();
        bus.name = JOptionPane.showInputDialog("Enter name");
        bus.age = Integer.parseInt(JOptionPane.showInputDialog("Enter age"));
        bus.id = Integer.parseInt(JOptionPane.showInputDialog("Enter id"));
        bus.print();
        
        SportsCar sportsCar = new SportsCar();
        sportsCar.name = JOptionPane.showInputDialog("Enter name");
        sportsCar.age = Integer.parseInt(JOptionPane.showInputDialog("Enter age"));
        sportsCar.id = Integer.parseInt(JOptionPane.showInputDialog("Enter id"));
        sportsCar.print();
    }
}