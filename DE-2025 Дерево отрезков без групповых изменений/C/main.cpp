#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int MAXN = 100000;
int n;
int t[4 * MAXN];
vector<int> a;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2,     tl,  tm);
        build(v*2 + 1, tm+1, tr);
        t[v] = gcd(t[v*2], t[v*2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    int leftG  = query(v*2,     tl,  tm, l,           min(r, tm));
    int rightG = query(v*2 + 1, tm+1, tr, max(l, tm+1), r);
    return gcd(leftG, rightG);
}

int main() {
    cin >> n;
    a.resize(n);
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
        int ans = query(1, 0, n - 1, l - 1, r - 1);
        if (!first)
            cout << ' ';
        first = false;
        cout << ans;
    }
    cout << '\n';
    return 0;
}