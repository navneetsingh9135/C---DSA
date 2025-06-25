#include <iostream>
using namespace std;

int fact(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}
int main()
{
    int n, r;
    cout << "\nEnter the value of n";
    cin >> n;
    cout << "\nEnter the value of r";
    cin >> r;
    int ans = fact(n) / (fact(r) * fact(n - r));
    cout << ans << endl;
    return 0;
}