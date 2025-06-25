#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char *ptr = "Raj";
    int count = 0;
    while (*ptr != '\0')
    {
        ptr++;
        count++;
    }
    for (int i = 0; i <= count; i++)
    {
        ptr--;
        cout << *ptr;
    }
    return 0;
}