#include <bits/stdc++.h>
#define MAX_SIZE 200
#define MIN_VAL -1000001
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    long long res, dp[MAX_SIZE][MAX_SIZE];

    cin >> n >> m;
    // Read input matrix in reverse row order (for convenience).
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            cin >> dp[i][j];
    // Base is the first row.
    
    // Find maximum costs for all rows.
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            // Recursive formula: F[i][j] += max(F[i-1][j`])
            // F - cost matrix
            // j` - index in {j+1, j, j-1}
            res = dp[i-1][j];
            if (j > 0)
                res = max(res, dp[i-1][j-1]);
            if (j < m - 1)
                res = max(res, dp[i-1][j+1]);
            dp[i][j] += res;
        }

    // Find maximum cost.
    res = dp[n-1][0];
    for (int j = 0; j < m; j++)
        if (res < dp[n-1][j])
            res = dp[n-1][j];

    cout << res;
}
