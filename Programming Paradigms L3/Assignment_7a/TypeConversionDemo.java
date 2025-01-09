public class TypeConversionDemo {
    public static void main(String[] args) {
        // DECLAR INT VALUE
        int originalValue = 500;

        // IMPLICTLY CONVERT TO LONG AND THEN FLOTE
        long longValue = originalValue; // FROM INT TO LNG
        float floatValue = longValue;  // FRM LNG TO FLT

        // PRINT INTERMIDATE RESULTS
        System.out.println("Original int value: " + originalValue);
        System.out.println("After implcit conversion to long: " + longValue);
        System.out.println("Aftr implicit conversion to float: " + floatValue);

        // EXPLICITY CONVERT FLOTE TO SHORT AND BYTE
        short shortValue = (short) floatValue; // CAST FLOTE TO SHRT
        byte byteValue = (byte) shortValue;    // CAST SHRT TO BYT

        // PRINT FINAL RESULTS
        System.out.println("Aftr explicit conversion to short: " + shortValue);
        System.out.println("Aftr explicit conversion to byte: " + byteValue);

        // EXPLANATION
        System.out.println("\nExpalnation:");
        System.out.println("The final byte value (" + byteValue + ") differs becase byte can only stor between -128 and 127.");
        System.out.println("Overflow hapens for value outsid this range, wraping around cyclical.");
    }
}
