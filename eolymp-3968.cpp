#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>

using namespace std;

const long double eps = 1e-7;

long double polynom(long double C, long double x) {
    return x * x + sqrt(x) - C;
}

int main() {
    long double C, l = 0, r = 10000000000.0, mid;

    cin >> C;

    while (r - l > eps) {
        mid = l + (r - l) / 2;
        if (polynom(C, mid) < 0.0) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << fixed << setprecision(6) << l + (r - l) / 2;

}
