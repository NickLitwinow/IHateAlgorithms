#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m = n * (n - 1) / 2;
        vector<long long> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());

        vector<long long> a;
        int current_b_idx = 0;
        for (int i = 0; i < n - 1; i++) {
            a.push_back(b[current_b_idx]);
            current_b_idx += (n - 1 - i);
        }
        a.push_back(a.back());

        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i + 1 < n) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
