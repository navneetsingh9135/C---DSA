#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

// Function to compute (a^n) % MOD
int power(int a, int n) {
    a%=MOD;
    int ans = 1;
    while (n > 0) {
        if (n & 1) {  // Check if the current bit of n is 1
            ans = (ans * a) % MOD;  // Multiply ans by a and take modulo
        }
        a = (a * a) % MOD;  // Square the base and take modulo
        n = n >> 1;        // Right-shift n to process the next bit
    }
    return ans;
}

signed main() {
    int a, n;
    cin >> a >> n;             // Input the base (a) and exponent (n)
    cout << power(a, n) << endl;  // Output the result of (a^n) % MOD
    return 0;
}
