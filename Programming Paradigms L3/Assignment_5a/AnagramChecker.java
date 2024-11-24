import java.util.Arrays;

public class AnagramChecker {
    
    // Method to check if two strings are anagrams by sorting
    public static boolean areAnagramsBySorting(String str1, String str2) {
        // If lengths don't match, they can't be anagrams
        if (str1.length() != str2.length()) {
            return false;
        }
        
        // Convert strings to char arrays
        char[] charArray1 = str1.toCharArray();
        char[] charArray2 = str2.toCharArray();
        
        // Sort the character arrays
        Arrays.sort(charArray1);
        Arrays.sort(charArray2);
        
        // Check if sorted arrays are equal
        return Arrays.equals(charArray1, charArray2);
    }
    
    // Method to check if two strings are anagrams using frequency count
    public static boolean areAnagramsByCounting(String str1, String str2) {
        // If lengths don't match, they can't be anagrams
        if (str1.length() != str2.length()) {
            return false;
        }
        
        int[] charCount = new int[256]; // Assuming ASCII characters
        
        // Count frequency of characters in the first string
        for (char c : str1.toCharArray()) {
            charCount[c]++;
        }
        
        // Subtract frequency based on the second string
        for (char c : str2.toCharArray()) {
            charCount[c]--;
        }
        
        // If any character has a non-zero count, they aren't anagrams
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }

    public static void main(String[] args) {
        // Example strings
        String str1 = "coding";
        String str2 = "dincog";
        
        // Check anagrams using sorting method
        if (areAnagramsBySorting(str1, str2)) {
            System.out.println(str1 + " and " + str2 + " are anagrams (by sorting).");
        } else {
            System.out.println(str1 + " and " + str2 + " are not anagrams (by sorting).");
        }
        
        // Check anagrams using frequency count method
        if (areAnagramsByCounting(str1, str2)) {
            System.out.println(str1 + " and " + str2 + " are anagrams (by counting).");
        } else {
            System.out.println(str1 + " and " + str2 + " are not anagrams (by counting).");
        }
    }
}
