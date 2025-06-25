#include <stdio.h>

int fact(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    int n;
    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", fact(i) / (fact(j) * fact(i - j)));
        }
        printf("\n");
    }

    return 0;
}
