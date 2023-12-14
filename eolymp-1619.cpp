#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    unsigned long long *b = new unsigned long long[n];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    // Corner cases.
    if (n == 1)
    {
        cout << b[0];
        return 0;
    }
    if (n == 2)
    {
        cout << max(b[0], b[1]);
        return 0;
    }

    // Allocating memory for total price array.
    unsigned long long *price = new unsigned long long[n];
    // Set base.
    price[0] = b[0];
    price[1] = max(b[0], b[1]);
    // Use recursive formula and find max price.
    for (int i = 2; i < n; i++)
        price[i] = max(price[i-2] + b[i], price[i-1]);

    cout << price[n-1];

    delete [] b;
    delete [] price;

    return 0;
}
