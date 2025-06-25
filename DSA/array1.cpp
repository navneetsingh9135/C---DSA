#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    
    deque<int> dq;  // Deque to store indices
    vector<int> ans; // To store results
    
    for (int i = 0; i < n; i++)
    {
        // Remove elements out of the current window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        
        // Remove elements smaller than the current element from the back
        while (!dq.empty() && a[dq.back()] < a[i])
            dq.pop_back();
        
        // Add the current element's index at the back of deque
        dq.push_back(i);
        
        // The front element is the largest in the window, so add it to the result
        if (i >= k - 1)
            ans.push_back(a[dq.front()]);
    }
    
    // Output the result
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
