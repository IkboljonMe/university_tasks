import java.util.Scanner;

public class Calculator {

    // Global variable to store the result of previous operations
    static double result = 0.0;

    // Method to display MENUU
    public static void displayMenu() {
        System.out.println("Welcome to the Calculator!");
        System.out.println("1. Basic Operations");
        System.out.println("2. Complex Operations");
        System.out.println("3. Exit");
        System.out.print("Choose an option (1-3): ");
    }

    // Method to perform  BASIC OPERATIONS
    public static void basicOperations() {
        // Initialize a Scanner for USER INTUP
        Scanner scanner = new Scanner(System.in);

        // GET user input
        System.out.print("Enter first number: ");
        double num1 = scanner.nextDouble();
        System.out.print("Enter second number: ");
        double num2 = scanner.nextDouble();

        System.out.println("Choose an operation:");
        System.out.println("1. Addition");
        System.out.println("2. Subtraction");
        System.out.println("3. Multiplication");
        System.out.println("4. Division");
        System.out.print("Choose an operation (1-4): ");
        int operation = scanner.nextInt();

        // Nested if-else structure for BASIC OPERATIONS
        if (operation == 1) {
            result = num1 + num2;
            System.out.println("The result of " + num1 + " + " + num2 + " is " + result + ".");
        } else if (operation == 2) {
            result = num1 - num2;
            System.out.println("The result of " + num1 + " - " + num2 + " is " + result + ".");
        } else if (operation == 3) {
            result = num1 * num2;
            System.out.println("The result of " + num1 + " * " + num2 + " is " + result + ".");
        } else if (operation == 4) {
            if (num2 != 0) {  // Check for division by zero
                result = num1 / num2;
                System.out.println("The result of " + num1 + " / " + num2 + " is " + result + ".");
            } else {
                System.out.println("Error: Division by zero is not allowed.");
            }
        } else {
            System.out.println("Invalid operation selected.");
        }
    }

    // Method to perform COMPLEX OPERATIONS
    public static void complexOperations() {
        // Initialize a Scanner to get  USER INPUT
        Scanner scanner = new Scanner(System.in);

        // GET user input
        System.out.print("Enter the base number: ");
        double num1 = scanner.nextDouble();
        System.out.print("Enter the exponent or divisor: ");
        double num2 = scanner.nextDouble();

        System.out.println("Choose an operation:");
        System.out.println("1. Exponentiation");
        System.out.println("2. Modulus");
        System.out.print("Choose an operation (1-2): ");
        int operation = scanner.nextInt();

        // Nested if-else structure for COMPLEX OPERAATIONS
        if (operation == 1) {
            result = Math.pow(num1, num2); // Exponentiation
            System.out.println("The result of " + num1 + " raised to the power of " + num2 + " is " + result + ".");
        } else if (operation == 2) {
            if (num2 != 0) {  // Check for modulus by zero
                result = num1 % num2;
                System.out.println("The result of " + num1 + " modulus " + num2 + " is " + result + ".");
            } else {
                System.out.println("Error: Modulus by zero is not allowed.");
            }
        } else {
            System.out.println("Invalid operation selected.");
        }
    }

    // Main method to run our calculator program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            displayMenu(); // Display the menu
            int choice = scanner.nextInt(); // Dynamic initialization based on user choice
            if (choice == 1) {
                basicOperations(); // Call function for BASIC OPEARATIONS
            } else if (choice == 2) {
                complexOperations(); // Call function for COMPLEX OPEARTION
            } else if (choice == 3) {
                System.out.println("Exiting the calculator. Goodbye!");
                break; // EXIT the program
            } else {
                System.out.println("Invalid choice. Please select a valid option.");
            }
        }
        scanner.close(); // CLOSE the scanner
    }
}
