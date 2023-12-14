#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double m, min;

    cin >> n;
    cin >> m;
    min = m;
    for (int i = 1; i < n; i++) {
        cin >> m;
        if (m < min) min = m;
    }
    cout << fixed << setprecision(2) << min * 2;
}
