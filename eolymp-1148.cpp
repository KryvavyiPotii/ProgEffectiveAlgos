#include <bits/stdc++.h>

using namespace std;

int findPower(int base, int powered) {
    int power = 0;
    while (powered != 1) {
        if (powered % base != 0)
            break;
        powered /= base;
        power++;
    }
    return power;
}

int main() {
    int T, G, L;

    // Read input and return output immediately.
    cin >> T;
    while (T--) {
        cin >> G >> L;
        if (L % G != 0) {
            cout << -1 << "\n";
        }
        // Check if L is a power of G.
        else if (findPower(G, L)) {
            cout << G << " " << L << "\n";
        }
        else {
            cout << G << " " << L / G << "\n"; 
        }
    }

    return 0;
}
