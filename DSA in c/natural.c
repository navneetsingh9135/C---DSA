#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter the number of natural numbers: ");
    scanf("%d", &n);

    printf("Number\tSquare\tCube\n");
    printf("-----------------------\n");

   
    for (i = 1; i <= n; i++)
    {
        int square = i * i;
        int cube = i * i * i;
        printf("%d\t%d\t%d\n", i, square, cube);
    }

    return 0;
}