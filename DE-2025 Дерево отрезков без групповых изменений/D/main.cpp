#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200000;
int n, m;
int a[MAXN + 1];
int t[4 * MAXN + 5];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(v<<1,     tl,  tm);
        build(v<<1|1, tm+1, tr);
        t[v] = max(t[v<<1], t[v<<1|1]);
    }
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            update(v<<1,     tl,  tm, pos, val);
        else
            update(v<<1|1, tm+1, tr, pos, val);
        t[v] = max(t[v<<1], t[v<<1|1]);
    }
}

int findFirst(int v, int tl, int tr, int l, int x) {
    if (tr < l || t[v] < x)
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        int res = findFirst(v<<1, tl, tm, l, x);
        if (res != -1)
            return res;
        return findFirst(v<<1|1, tm+1, tr, l, x);
    }
    return findFirst(v<<1|1, tm+1, tr, l, x);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);

    while (m--) {
        int type, i, x;
        cin >> type >> i >> x;
        if (type == 0) {
            update(1, 1, n, i, x);
        } else {
            int ans = findFirst(1, 1, n, i, x);
            cout << ans << "\n";
        }
    }
    return 0;
}