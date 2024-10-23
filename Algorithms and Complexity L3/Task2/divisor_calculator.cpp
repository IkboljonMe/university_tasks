#include <iostream>
#include <chrono>
#include <fstream>

// Function to count divisors naively
long long divisors(long long n) {
    long long count = 0;
    for (long long i = 1; i <= n; ++i) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

// Optimized function to count divisors using the square root method
long long divisors2(long long n) {
    long long count = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count++;
            if (i != n / i) {
                count++;
            }
        }
    }
    return count;
}

// Further optimized function to count divisors using prime factorization
long long divisors3(long long n) {
    long long count = 1; // For the number itself
    for (long long p = 2; p * p <= n; ++p) {
        long long exp = 0;
        while (n % p == 0) {
            n /= p;
            exp++;
        }
        count *= (exp + 1);
    }
    if (n > 1) { // If n is prime
        count *= 2;
    }
    return count;
}

int main() {
    // Create and open a CSV file
    std::ofstream file("divisor_data.csv");
    file << "Value,Divisors Time (s),Divisors2 Time (s),Divisors3 Time (s)\n";

    // Test values
    long long values[] = {1000000, 10000000, 100000000, 1000000000, 10000000000};
    for (long long value : values) {
        // Measure execution time for divisors
        auto start = std::chrono::high_resolution_clock::now();
        divisors(value);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration1 = end - start;

        // Measure execution time for divisors2
        start = std::chrono::high_resolution_clock::now();
        divisors2(value);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration2 = end - start;

        // Measure execution time for divisors3
        start = std::chrono::high_resolution_clock::now();
        divisors3(value);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration3 = end - start;

        // Write results to CSV file
        file << value << "," << duration1.count() << "," 
             << duration2.count() << "," << duration3.count() << "\n";
    }
    file.close();

    std::cout << "Data has been written to divisor_data.csv" << std::endl;
    return 0;
}
