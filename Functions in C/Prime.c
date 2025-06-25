#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num < 2) return 0; // Handle edge case for numbers less than 2
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int a, b;
    printf("\nEnter the value of a: ");
    scanf("%d", &a);
    printf("\nEnter the value of b: ");
    scanf("%d", &b);
    
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
