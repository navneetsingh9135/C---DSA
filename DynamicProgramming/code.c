#include <stdio.h>

void func1(int array[], int length) {
    int sum = 0;
    int product = 1;

    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    for (int i = 0; i < length; i++) {
        product *= array[i];
    }

    printf("Sum = %d\n", sum);
    printf("Product = %d\n", product);
}

int main() {
    int arr[] = {3, 5, 66};
    func1(arr, 3);
    return 0;
}
