#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setbits(x) __builtin_popcountll(x)
const int N = 1e3 + 2, MOD = 1e9 + 7;

int val[N], wt[N];
int dp[N][N];

// Function to solve the 0/1 Knapsack problem with memoization
int KnapSack(int n, int w)
{
    if (w <= 0)
        return 0;
    if (n <= 0)
        return 0;
    if (dp[n][w] != -1) 
        return dp[n][w];
    if (wt[n - 1] > w)
        dp[n][w] = KnapSack(n - 1, w);
    else
        dp[n][w] = max(KnapSack(n - 1, w), KnapSack(n - 1, w - wt[n - 1]) + val[n - 1]);
    return dp[n][w];
}

int main()
{
    int n;
    cin >> n;

    // Input weights
    rep(i, 0, n)
    {
        cin >> wt[i];
    }

    // Input values
    rep(i, 0, n)
    {
        cin >> val[i];
    }
    int w;
    cin >> w;

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    // Compute and print the result
    cout << KnapSack(n, w) << endl;

    return 0;
}
