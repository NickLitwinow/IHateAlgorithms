#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100000;

int n;
int a[MAXN];
int t[4 * MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = tl;
    } else {
        int tm = (tl + tr) / 2;
        build(v*2,     tl,  tm);
        build(v*2 + 1, tm+1, tr);
        int li = t[v*2], ri = t[v*2 + 1];
        t[v] = (a[li] >= a[ri] ? li : ri);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return -1;
    }
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) {
        return query(v*2, tl, tm, l, r);
    }
    if (l > tm) {
        return query(v*2+1, tm+1, tr, l, r);
    }
    int li = query(v*2,     tl,  tm, l,    tm);
    int ri = query(v*2 + 1, tm+1, tr, tm+1, r);
    if (li == -1) return ri;
    if (ri == -1) return li;
    return (a[li] >= a[ri] ? li : ri);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    build(1, 0, n - 1);

    int K;
    cin >> K;
    bool first = true;
    while (K--) {
        int l, r;
        cin >> l >> r;
        int idx = query(1, 0, n - 1, l - 1, r - 1);
        if (!first) cout << ' ';
        first = false;
        cout << (idx + 1);
    }
    cout << "\n";
    return 0;
}