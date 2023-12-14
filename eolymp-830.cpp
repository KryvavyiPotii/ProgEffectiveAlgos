#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    bool notPrime = false, absent = true;
    int num, i, m, n;

    cin >> m >> n;
    
    num = m;
    while (num <= n) {
        i = 2;
        notPrime = false;
        while (i < sqrt(num) + 1) {
            if (num != 2 && num % i == 0) {
                notPrime = true;
                break;
            }
            i++;
        }
        if (!notPrime) {
            cout << num << "\n";
            absent = false;
        }
        num++;
    }
    if (absent) cout << "Absent\n";
}
