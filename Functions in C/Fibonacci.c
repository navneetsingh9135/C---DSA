#include <stdio.h>

void fib(int n) {
    int t1 = 0;
    int t2 = 1;
    int nextTerm;
    
    for (int i = 1; i <= n; i++) {
        printf("%d\n", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;  // Fixed the typo from `t2 == nextTerm;` to `t2 = nextTerm;`
    }
}

int main() {
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    fib(n);
    return 0;
}
