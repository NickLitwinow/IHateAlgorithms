#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int len, pref, suff, best;
};

vector<int> a;
vector<Node> st;

Node merge(const Node &L, const Node &R) {
    Node res;
    res.len  = L.len + R.len;
    res.pref = (L.pref == L.len ? L.len + R.pref : L.pref);
    res.suff = (R.suff == R.len ? R.len + L.suff : R.suff);
    res.best = max(max(L.best, R.best), L.suff + R.pref);
    return res;
}

Node emptyNode() {
    Node res;
    res.len = res.pref = res.suff = res.best = 0;
    return res;
}

void build(int v, int l, int r) {
    if (l == r) {
        int z = (a[l] == 0 ? 1 : 0);
        st[v].len  = 1;
        st[v].pref = z;
        st[v].suff = z;
        st[v].best = z;
    } else {
        int m = (l + r) >> 1;
        build(v<<1,     l,   m);
        build(v<<1|1, m+1,   r);
        st[v] = merge(st[v<<1], st[v<<1|1]);
    }
}

void update(int v, int l, int r, int pos, int val) {
    if (l == r) {
        int z = (val == 0 ? 1 : 0);
        st[v].pref = z;
        st[v].suff = z;
        st[v].best = z;
    } else {
        int m = (l + r) >> 1;
        if (pos <= m)
            update(v<<1,     l,   m, pos, val);
        else
            update(v<<1|1, m+1,   r, pos, val);
        st[v] = merge(st[v<<1], st[v<<1|1]);
    }
}

Node query(int v, int l, int r, int ql, int qr) {
    if (ql > qr)
        return emptyNode();
    if (ql == l && qr == r)
        return st[v];
    int m = (l + r) >> 1;
    if (qr <= m)
        return query(v<<1,     l,   m, ql, qr);
    if (ql > m)
        return query(v<<1|1, m+1,   r, ql, qr);
    return merge(
        query(v<<1,     l,   m, ql,   m),
        query(v<<1|1, m+1,   r, m+1, qr)
    );
}

int main(){
    int N, M;
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    st.resize(4 * N);
    build(1, 0, N - 1);

    cin >> M;
    while (M--) {
        string op;
        int x, y;
        cin >> op >> x >> y;
        if (op[0] == 'U') {
            update(1, 0, N - 1, x - 1, y);
        } else {
            Node res = query(1, 0, N - 1, x - 1, y - 1);
            cout << res.best << "\n";
        }
    }

    return 0;
}