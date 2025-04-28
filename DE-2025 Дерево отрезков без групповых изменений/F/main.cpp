#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000000;

struct Elem {
    int v, i;
} arr[MAXN];

int n;
int a[MAXN];
int cval[MAXN];
int bit[MAXN + 1];
long long leftG[MAXN], rightL[MAXN];

inline void bit_update(int idx) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx]++;
}

inline int bit_query(int idx) {
    int s = 0;
    for (; idx > 0; idx -= idx & -idx)
        s += bit[idx];
    return s;
}

bool cmp(const Elem &x, const Elem &y) {
    return x.v < y.v;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        arr[i].v = a[i];
        arr[i].i = i;
    }

    sort(arr, arr + n, cmp);
    for (int k = 0; k < n; ++k) {
        cval[arr[k].i] = k + 1;
    }

    memset(bit, 0, sizeof(int) * (n + 1));
    for (int j = 0; j < n; ++j) {
        int v = cval[j];
        leftG[j] = (long long)j - bit_query(v);
        bit_update(v);
    }

    memset(bit, 0, sizeof(int) * (n + 1));
    for (int j = n - 1; j >= 0; --j) {
        int v = cval[j];
        rightL[j] = bit_query(v - 1);
        bit_update(v);
    }

    long long ans = 0;
    for (int j = 0; j < n; ++j) {
        ans += leftG[j] * rightL[j];
    }

    cout << ans << "\n";
    return 0;
}