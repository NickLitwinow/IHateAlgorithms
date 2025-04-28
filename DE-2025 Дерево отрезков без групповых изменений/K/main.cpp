#include <iostream>
#include <vector>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> f;
    Fenwick(int _n): n(_n), f(n+1, 0) {}
    void update(int i, long long v) {
        for (; i <= n; i += i & -i)
            f[i] += v;
    }
    long long query(int i) const {
        long long s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }
    long long query(int l, int r) const {
        return query(r) - query(l-1);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    Fenwick fw(n);
    for (int i = 1; i <= n; ++i) {
        long long Bi = (i % 2 ? a[i] : -a[i]);
        fw.update(i, Bi);
    }

    int m;
    cin >> m;
    while (m--) {
        int type;
        cin >> type;
        if (type == 0) {
            int i, j;
            cin >> i >> j;
            long long oldB = (i % 2 ? a[i] : -a[i]);
            long long newB = (i % 2 ? j : -j);
            fw.update(i, newB - oldB);
            a[i] = j;
        } else {
            int l, r;
            cin >> l >> r;
            long long sum = fw.query(l, r);
            if (l % 2 == 0) sum = -sum;
            cout << sum << '\n';
        }
    }

    return 0;
}