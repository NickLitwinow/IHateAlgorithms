#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        vector<long long> a(n);
        long long S = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            S += a[i];
        }

        long long L = S - y;
        long long R = S - x;
        if (L > R) {
            cout << 0 << endl;
            continue;
        }

        sort(a.begin(), a.end());
        long long res = 0;

        for (int i = 0; i + 1 < n; ++i) {
            long long lo = L - a[i];
            long long hi = R - a[i];
            vector<long long>::iterator itLo =
                lower_bound(a.begin() + (i + 1), a.end(), lo);
            vector<long long>::iterator itHi =
                upper_bound(a.begin() + (i + 1), a.end(), hi);
            res += (itHi - itLo);
        }

        cout << res << endl;
    }
    return 0;
}
