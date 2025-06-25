#include <iostream>
using namespace std;
int main()
{
    int n[10];
    cout << "\nEnter 10 numbers";
    for (int i = 0; i < 10; i++)
        cin >> n[i];
    cout << "\nDisplaying the numbers";
    for (int i = 0; i < 10; i++)
        cout << n[i] << " ";
    return 0;
}