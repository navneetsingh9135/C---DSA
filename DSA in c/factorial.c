#include <stdio.h>

// Function to calculate factorial
long fact(int n) {
    long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, r;
    
    // Input for n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Input for r
    printf("Enter the value of r: ");
    scanf("%d", &r);

    // Check for valid input (n >= r)
    if (r > n) {
        printf("Invalid input. r cannot be greater than n.\n");
        return 1;
    }

    // Calculating nCr correctly
    long result = fact(n) / (fact(r) * fact(n - r));

    // Output the result
    printf("nCr = %ld\n", result);

    return 0;
}
