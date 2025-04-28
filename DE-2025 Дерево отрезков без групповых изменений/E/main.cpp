#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int matched;
    int open;
    int close;
};

string s;
vector<Node> st;

Node merge_nodes(const Node &L, const Node &R) {
    Node res;
    int match = min(L.open, R.close);
    res.matched = L.matched + R.matched + match;
    res.open    = L.open + R.open - match;
    res.close   = L.close + R.close - match;
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (s[tl] == '(') {
            st[v].matched = 0;
            st[v].open    = 1;
            st[v].close   = 0;
        } else {
            st[v].matched = 0;
            st[v].open    = 0;
            st[v].close   = 1;
        }
    } else {
        int tm = (tl + tr) >> 1;
        build(v<<1,     tl,  tm);
        build(v<<1|1, tm+1, tr);
        st[v] = merge_nodes(st[v<<1], st[v<<1|1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        Node empty;
        empty.matched = empty.open = empty.close = 0;
        return empty;
    }
    if (l == tl && r == tr) {
        return st[v];
    }
    int tm = (tl + tr) >> 1;
    if (r <= tm) {
        return query(v<<1, tl, tm, l, r);
    }
    if (l > tm) {
        return query(v<<1|1, tm+1, tr, l, r);
    }
    Node left  = query(v<<1, tl, tm, l, tm);
    Node right = query(v<<1|1, tm+1, tr, tm+1, r);
    return merge_nodes(left, right);
}

int main(){
    cin >> s;
    int n = s.size();

    st.resize(4 * n);
    build(1, 0, n - 1);

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        Node res = query(1, 0, n - 1, l - 1, r - 1);
        cout << (res.matched * 2) << "\n";
    }
    return 0;
}