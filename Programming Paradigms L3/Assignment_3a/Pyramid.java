public class Pyramid {
    public static void main(String[] args) {
        int iterations = 9; // Total number of rows for the pyramid

        for (int i = 1; i <= iterations; i++) { // Loop for each row
            for (int j = 1; j <= i; j++) { // Loop to print numbers in the row
                System.out.print(j + " "); // Print numbers from 1 to i
            }
            System.out.println(); // Move to the next line after each row
        }
    }
}
