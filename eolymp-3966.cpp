#include <bits/stdc++.h>
using namespace std;

#define MAX_BCOUNT 100000

int main() {
    bool found;
    int n, m, i, l, r, mid;
    int b[MAX_BCOUNT], f[MAX_BCOUNT];

    cin>>n;
    for (i = 0; i < n; i++)
        cin>>b[i];
    cin>>m;
    for (i = 0; i < m; i++)
        cin>>f[i];
    
    i = 0;
    while (i < m) {
        l = 0;
        r = n - 1;
        found = false;
        while (!found && l <= r) {
            mid = l + (r - l) / 2;
            if (b[mid] == f[i]) {
                found = true;
            }
            else if (b[mid] < f[i]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (found) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
        i++;
    }

    return 0;
}
