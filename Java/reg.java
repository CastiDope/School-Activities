//Password Modification(Strings)

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class reg{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String username, password, password2;
        boolean valid = false;
        System.out.println("Welcome to the registration system!");
        System.out.println("Please enter your username: ");
        username = sc.nextLine();
        System.out.println("Please enter your password: ");
        password = sc.nextLine();
        System.out.println("Please confirm your password: ");
        password2 = sc.nextLine();
        if (password.equals(password2)) {
            System.out.println("Password confirmed!");
            valid = true;
        } else {
            System.out.println("Password does not match!");
        }
        if (valid) {
            if (password.length() == 8) {
                System.out.println("Password length is 8 characters!");
            } else {
                System.out.println("Password length does not exceed 8 characters limit.");
            }
            if (password.length() <= 4) {
                System.out.println("Password strength is weak");
            } else {
                System.out.println("Password strength is strong!");
            }
            if (password.substring(3, 5).equals("ab")) {
                System.out.println("Password substring is (3,5)!");
            } else {
                System.out.println("Password substring is not (3,5).");
            }
            Pattern p = Pattern.compile("[^a-z0-9 ]", Pattern.CASE_INSENSITIVE);
            Matcher m = p.matcher(password);
            boolean b = m.find();
            if (b) {
                System.out.println("Password has special characters!");
            } else {
                System.out.println("Password does not sucessfully contain special characters.");
            }
        }
    }
}



