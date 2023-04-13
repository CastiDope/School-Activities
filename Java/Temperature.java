//Number 1
public class Temperature {
    //Instance variable
    double temperature;
    //Constructor 
    public Temperature(double temperature){
        this.temperature=temperature;
    }
    //Methods to convert temperature
    public double getFahrenheit(){
        return temperature;
    }
    public double getCelsius(){
        return (temperature-32)*5/9;
    }
    //Main method to display the results
    public static void main(String[] args) {
        //Creating instance of the class to access the instance methods and to set the temperature value
        Temperature t=new Temperature(100);
        System.out.println(t.getFahrenheit());
        System.out.println(t.getCelsius());
    }
}