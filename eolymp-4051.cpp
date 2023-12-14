#include <bits/stdc++.h>
#define MAX_LEN 30
using namespace std;

int main()
{
    int n, k, ind;
    long long dp[MAX_LEN] = {0};
    // Set base.
    dp[0] = 1;
    dp[1] = 1;

    cin >> n >> k;

    // DEBUG
    //for (int i = 0; i < n; i++) cout << dp[i] << ' '; cout << '\n';

    // Count number of ways of getting from ith cell to (i-1)th. (i < k) 
    for (int i = 2; i < k; i++)
        dp[i] = dp[i - 1] * 2;

    // Count number of ways of getting from ith cell to (i-1)th.
    for (int i = k; i < n; i++)
        // Recursive formula: F[i] += F[i-1] + ... + F[i-k]
        for (int j = 1; j <= k; j++)
            dp[i] += dp[i-j];
    
    cout << dp[n-1];
}
