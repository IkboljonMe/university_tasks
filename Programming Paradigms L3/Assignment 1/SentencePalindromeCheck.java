import java.util.Scanner;

public class SentencePalindromeCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a sentence: ");
        String input = scanner.nextLine();
        
        if (isSentencePalindrome(input)) {
            System.out.println("The sentence is a palindrome.");
        } else {
            System.out.println("The sentence is not a palindrome.");
        }
    }
    
    public static boolean isSentencePalindrome(String sentence) {
        // Remove all non-alphabetic characters and convert to lowercase
        String cleaned = sentence.replaceAll("[^a-zA-Z]", "").toLowerCase();
        
        // Check if cleaned string is a palindrome
        int left = 0;
        int right = cleaned.length() - 1;
        
        while (left < right) {
            if (cleaned.charAt(left) != cleaned.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
