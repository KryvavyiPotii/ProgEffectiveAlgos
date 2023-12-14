#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    bool found = false;
    int num, i, a, b;

    cin >> a >> b;
    
    num = a;
    if (a == 1)
        num++;
    while (num <= b) {
        i = 2;
        found = false;
        while (i < sqrt(num) + 1) {
            if (num != 2 && num % i == 0) {
                found = true;
                break;
            }
            i++;
        }
        if (!found) {
            cout << num << " ";
        }
        num++;
    }

    return 0;
}
