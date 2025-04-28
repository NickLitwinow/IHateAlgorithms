#include <iostream>
#include <set>
#include <string>
using namespace std;

const int MAXN = 300000;
const int MAXA = 1000000;

int n, m;
int a[MAXN + 5];
int Dcnt[MAXA + 5];
long long bit[MAXN + 5];

inline void bit_update(int idx, long long delta) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += delta;
}

inline long long bit_query(int idx) {
    long long s = 0;
    for (; idx > 0; idx -= idx & -idx)
        s += bit[idx];
    return s;
}

int main() {
    cin >> n >> m;
    int maxA = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > maxA) maxA = a[i];
    }
    for (int i = 1; i <= maxA; ++i) {
        for (int j = i; j <= maxA; j += i) {
            ++Dcnt[j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        bit_update(i, a[i]);
    }

    set<int> active;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 2) active.insert(i);
    }

    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            auto it = active.lower_bound(l);
            while (it != active.end() && *it <= r) {
                int pos = *it;
                int old = a[pos];
                int nw  = Dcnt[old];
                bit_update(pos, nw - old);
                a[pos] = nw;
                auto it2 = it;
                ++it2;
                if (nw <= 2) active.erase(it);
                it = it2;
            }
        } else {
            long long ans = bit_query(r) - bit_query(l - 1);
            cout << ans << '\n';
        }
    }

    return 0;
}