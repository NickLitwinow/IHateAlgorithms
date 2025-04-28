#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> t;
int n;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, val);
        else
            update(v*2+1, tm+1, tr, pos, val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main() {
    int K;
    cin >> n >> K;
    t.assign(4 * n, 0);
    build(1, 0, n - 1);

    while (K--) {
        char op;
        cin >> op;
        if (op == 'A') {
            int i;
            ll x;
            cin >> i >> x;
            update(1, 0, n - 1, i - 1, x);
        } else if (op == 'Q') {
            int l, r;
            cin >> l >> r;
            ll ans = query(1, 0, n - 1, l - 1, r - 1);
            cout << ans << "\n";
        }
    }
    return 0;
}