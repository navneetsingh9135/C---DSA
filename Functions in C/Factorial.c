#include <stdio.h>

int fact(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    int n, r;
    printf("\nEnter the value of n: ");
    scanf("%d", &n);
    printf("\nEnter the value of r: ");
    scanf("%d", &r);
    
    int ans = fact(n) / (fact(r) * fact(n - r));
    printf("%d\n", ans);
    
    return 0;
}
