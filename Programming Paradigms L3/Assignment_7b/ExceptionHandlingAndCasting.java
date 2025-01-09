public class ExceptionHandlingAndCasting {
    public static void main(String[] args) {
        // TASK 1: CONVERT STRING "45.67" TO INT
        String numericString = "45.67";
        try {
            int intValue = Integer.parseInt(numericString); // ATTEMPT PARSING STRING TO INT
            System.out.println("Converted string to int: " + intValue);
        } catch (NumberFormatException e) {
            // HANDLE EXCEPTION IF STRING CANNOT BE PARSED TO INT
            System.out.println("EXCEPTION: CANNOT CONVERT \"" + numericString + "\" TO INT.");
            System.out.println("REASON: STRING CONTAINS A DECIMAL POINT, WHICH IS INVALID FOR INT PARSING.");
        }

        // TASK 2: CONVERT STRING "abc" TO DOUBLE
        String nonNumericString = "abc";
        try {
            double doubleValue = Double.parseDouble(nonNumericString); // ATTEMPT PARSING STRING TO DOUBLE
            System.out.println("Converted string to double: " + doubleValue);
        } catch (NumberFormatException e) {
            // HANDLE EXCEPTION IF STRING CANNOT BE PARSED TO DOUBLE
            System.out.println("EXCEPTION: CANNOT CONVERT \"" + nonNumericString + "\" TO DOUBLE.");
            System.out.println("REASON: STRING DOES NOT CONTAIN A VALID NUMERIC FORMAT.");
        }

        // TASK 3: CONVERT FLOAT 128.45 TO INT
        float floatValue = 128.45f;
        int intFromFloat = (int) floatValue; // EXPLICIT CASTING FROM FLOAT TO INT
        System.out.println("ORIGINAL FLOAT VALUE: " + floatValue);
        System.out.println("AFTER CASTING FLOAT TO INT: " + intFromFloat);
        System.out.println("EXPLANATION: CASTING FLOAT TO INT TRUNCATES THE DECIMAL PART, CAUSING DATA LOSS.");
    }
}
