import java.util.*;

public class PermutationGenerator {

    // Function to generate permutations of the string
    public static void generatePermutations(String str, int left, int right) {
        if (left == right) {
            System.out.println(str);  // Print the permutation when left equals right
        } else {
            for (int i = left; i <= right; i++) {
                // Swap the characters at indices left and i
                str = swap(str, left, i);
                // Recurse for the next index
                generatePermutations(str, left + 1, right);
                // Backtrack and swap the characters back to the original state
                str = swap(str, left, i);
            }
        }
    }

    // Function to swap characters at indices i and j in the string
    public static String swap(String str, int i, int j) {
        char[] arr = str.toCharArray();
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        return new String(arr);
    }

    public static void main(String[] args) {
        String str = "abc";  // You can change this string to test with other strings
        int n = str.length();
        generatePermutations(str, 0, n - 1);
    }
}
