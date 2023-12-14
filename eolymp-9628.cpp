#include <bits/stdc++.h>
#define MAX_NUM 100000
using namespace std;

// |a - b|
long long sub(long long a, long long b)
{
    if (a >= b)
        return a - b;
    else
        return b - a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long stones[MAX_NUM], dp[MAX_NUM];

    cin >> n;
    // Read stone heights in reversed order (for convenience).
    for (int i = n - 1; i >= 0; i--)
        cin >> stones[i];

    // Set base.
    dp[0] = 0;
    dp[1] = sub(stones[0], stones[1]);
    // Calculate costs.
    for (int i = 2; i < n; i++)
        // Recursive formula.
        dp[i] = min(sub(stones[i-1], stones[i])+ dp[i-1],
            sub(stones[i-2],  stones[i]) + dp[i-2]);

    cout << dp[n-1];
}
