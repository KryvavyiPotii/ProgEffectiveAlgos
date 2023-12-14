#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const long double eps = 1e-7;

long double polynom(short int *koef, long double x) {
    long double result = 0, x_pow = 1;
    for (int i = 3; i >= 0; i--) {
        result += koef[i] * x_pow;
        x_pow *= x;
    }
    return result;
}

long double subModule(long double a, long double b) {
    if (a >= b) {
        return a - b;
    }
    else {
        return b - a;
    }
}

int main() {
    cout.precision(11);

    long double l = -1500.0, r = 1501.0, mid;
    short int *koef = new short int[4];

    for (int i = 0; i < 4; i++) {
        cin >> koef[i];
    }

    // Check if function is decreasing monotonically.
    // If so, swap values of left and right borders, because
    // otherwise polynom value won't approach 0 value.
    if (koef[0] < 0) {
        swap(l, r);
    }

    while (subModule(r, l) > eps) {
        mid = l + (r - l) / 2;
        if (polynom(koef, mid) < 0.0) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l + (r - l) / 2;

    delete[] koef;
    return 0;
}
