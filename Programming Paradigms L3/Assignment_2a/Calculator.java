import java.util.Scanner;

public class Calculator {
    // Global variable to store the RESULT and return us
    static double result;

    public static void main(String[] args) {
        // Scanner for user input that will take input from our CLI
        Scanner scanner = new Scanner(System.in);
        // 1 Log::
        System.out.println("Enter the number of values you want to operate on:");
        int numValues = scanner.nextInt();
        double[] values = new double[numValues];
        //Filling our array with user inputs
        for (int i = 0; i < numValues; i++) {
            //1.1 Logs::
            System.out.print("Enter value " + (i + 1) + ": ");
            values[i] = scanner.nextDouble();
        }
        // 2 Logs
        System.out.println("\nChoose operation beloww: ");
        System.out.println("1. Addition+");
        System.out.println("2. Subtraction-");
        System.out.println("3. Multiplication*");
        System.out.println("4. Division/");
        System.out.println("5. Average");
        System.out.print("Enter your choice (1-5): ");
        int choice = scanner.nextInt();
        //Cases to handle::
        switch (choice) {
            case 1:
                result = add(values);
                System.out.println("Sum: " + result);
                break;
            case 2:
                result = subtract(values);
                System.out.println("Difference: " + result);
                break;
            case 3:
                result = multiply(values);
                System.out.println("Product: " + result);
                break;
            case 4:
                result = divide(values);
                System.out.println("Quotient: " + result);
                break;

            case 5:
                result = average(values);
                System.out.println("Average: " + result);
                break;

            default:
                System.out.println("Invalid choice!Select validd.");
        }
        scanner.close();
    }
    //Methods to handle
    static double add(double[] values) {
        double sum = 0; // Local variable for storing the sum
        for (double value : values) {
            sum += value; // Adding each value to sum
        }
        return sum;
    }
    static double subtract(double[] values) {
        double difference = values[0];
        for (int i = 1; i < values.length; i++) {
            difference -= values[i];
        }
        return difference;
    }
    static double multiply(double[] values) {
        double product = 1; 
        for (double value : values) {
            product *= value; 
        }
        return product;
    }

    static double divide(double[] values) {
        double quotient = values[0];
        for (int i = 1; i < values.length; i++) {
            if (values[i] != 0) {
                quotient /= values[i];
            } else {
                System.out.println("Error: Division by zero!");
                return 0;
            }
        }
        return quotient;
    }

    static double average(double[] values) {
        double sum = add(values);
        return sum / values.length;
    }
}
