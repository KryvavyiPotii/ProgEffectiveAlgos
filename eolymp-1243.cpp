#include <bits/stdc++.h>
#define MAX_M 100
using namespace std;

unsigned long gcd(unsigned long a, unsigned long b) {
    unsigned long r;

    if (a < b) {
        swap(a, b);
    }
    r = a % b;
    while (a % b != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    string line;
    unsigned long n, m, num, i, j, lcm;

    // Read number of tests.
    cin >> n;
    i = 0;
    while (i < n) {
        // Read quantity of numbers.
        cin >> m;
        j = 0;
        lcm = 1;
        // Calculate lcm.
        while (j < m) {
            cin >> num;
            lcm *= num / gcd(num, lcm);
            j++;
        }
        cout << lcm << "\n";
        i++;
    }

    return 0;
}
