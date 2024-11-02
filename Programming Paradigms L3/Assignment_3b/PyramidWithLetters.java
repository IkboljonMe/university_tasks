public class PyramidWithLetters {
    public static void main(String[] args) {
        int iterations = 9; // Total number of rows for the pyramid

        for (int i = 1; i <= iterations; i++) { // Loop for each row
            for (int j = 1; j <= i; j++) { // Loop to print numbers and letters
                if (j % 2 != 0) { // Print numbers for odd positions
                    System.out.print(j + " ");
                } else { // Print letters for even positions
                    System.out.print((char) ('A' + (j / 2 - 1)) + " "); // Convert to character
                }
            }
            System.out.println(); // Move to the next line after each row
        }
    }
}
