#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    int i = 0, j = 0;
    int temp = 0, res = 0;
    while (i < n) {
        if (j < n && R[j] < L[i]) {
            temp--;
            j++;
        } else {
            temp++;
            res = max(res, temp);
            i++;
        }
    }

    cout << res << endl;
    return 0;
}
