#include <bits/stdc++.h>
#define MAX_CUST 5000
#define MAX_TIME 3600
// Offset for the first 2 zeroes in dp array.
#define OFFSET 2
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long dp[MAX_CUST], a[MAX_CUST], b[MAX_CUST], c[MAX_CUST];

    cin >> n;
    for (int i = n - 1; i >= 0; i--)
        cin >> a[i] >> b[i] >> c[i];
    
    // Forbid buying extra tickets.
    if (n < 3)
        for (int i = n; i <= 4 - n; i++)
        {
            a[i] = MAX_TIME;
            b[i] = MAX_TIME;
            c[i] = MAX_TIME;
        }

    // Set base.
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = min(a[0], min(b[1], c[2]));
    // Find minimal time.
    for (int i = 3; i < n + OFFSET; i++)
        // Recursive formula.
        dp[i] = min(a[i-OFFSET] + dp[i-1],
            min(b[i-OFFSET] + dp[i-2], c[i-OFFSET] + dp[i-3]));
    
    cout << dp[n-1+OFFSET];
}
