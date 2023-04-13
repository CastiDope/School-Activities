//   Declare the Person class that describes a human and the Student class that extends Person. The attributes in each instance of type Person should include: name, age and id. The attributes in each instance of type Student should include, in addition to those that inherited from class Person, the attribute average. Each of the two classes should have declared the toString() method. You should check these two classes by instantiating them and invoking the toString method on each one of them. Don’t declare any constructors in the classes Person and Student. 

public class Person {
    String name;
    int age;
    int id;
    
    public String toString() {
        return "Name: " + name + " Age: " + age + " ID: " + id;
    }
}

public class Student extends Person {
    double average;
    
    public String toString() {
        return super.toString() + " Average: " + average;
    }
}

public class Main {
    public static void main(String[] args) {
        Person person = new Person();
        person.name = "John";
        person.age = 20;
        person.id = 123;
        System.out.println(person);
        
        Student student = new Student();
        student.name = "Mary";
        student.age = 19;
        student.id = 456;
        student.average = 9.5;
        System.out.println(student);
    }
}

