#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int l = 0;
        int cur_sum = 0;
        int max_len = -1;
        for (int r = 0; r < n; r++) {
            cur_sum += a[r];
            while (l <= r && cur_sum > s) {
                cur_sum -= a[l];
                l++;
            }
            if (cur_sum == s) {
                int len = r - l + 1;
                if (len > max_len) {
                    max_len = len;
                }
            }
        }

        if (max_len < 0) {
            cout << -1 << endl;
        } else {
            cout << (n - max_len) << endl;
        }
    }
    return 0;
}
