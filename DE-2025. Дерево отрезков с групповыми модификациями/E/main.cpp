#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct SegTree {
    struct Node {
        int cnt[26];
        int lazy;
    };
    int n;
    vector<Node> t;

    SegTree(int _n): n(_n), t(4*_n) {
        build(1, 1, n);
    }

    void build(int v, int l, int r) {
        t[v].lazy = -1;
        for (int c = 0; c < 26; c++) t[v].cnt[c] = 0;
        if (l == r) {
        } else {
            int m = (l + r) >> 1;
            build(v<<1, l, m);
            build(v<<1|1, m+1, r);
        }
    }

    void applyAssign(int v, int len, int c) {
        for (int i = 0; i < 26; ++i) t[v].cnt[i] = 0;
        t[v].cnt[c] = len;
        t[v].lazy = c;
    }

    void push(int v, int l, int r) {
        if (t[v].lazy != -1 && l != r) {
            int c = t[v].lazy;
            int m = (l + r) >> 1;
            applyAssign(v<<1, m - l + 1, c);
            applyAssign(v<<1|1, r - m,       c);
            t[v].lazy = -1;
        }
    }

    void pull(int v) {
        for (int c = 0; c < 26; ++c) {
            t[v].cnt[c] = t[v<<1].cnt[c] + t[v<<1|1].cnt[c];
        }
    }

    void initLeaf(int v, int l, int r, int pos, int c) {
        if (l == r) {
            for (int i = 0; i < 26; ++i) t[v].cnt[i] = 0;
            t[v].cnt[c] = 1;
        } else {
            push(v, l, r);
            int m = (l + r) >> 1;
            if (pos <= m) initLeaf(v<<1, l, m, pos, c);
            else initLeaf(v<<1|1, m+1, r, pos, c);
            pull(v);
        }
    }

    void updateRange(int v, int l, int r, int L, int R, int c) {
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            applyAssign(v, r - l + 1, c);
        } else {
            push(v, l, r);
            int m = (l + r) >> 1;
            updateRange(v<<1, l, m, L, R, c);
            updateRange(v<<1|1, m+1, r, L, R, c);
            pull(v);
        }
    }

    void queryCounts(int v, int l, int r, int L, int R, int res[26]) {
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            for (int c = 0; c < 26; ++c) res[c] += t[v].cnt[c];
        } else {
            push(v, l, r);
            int m = (l + r) >> 1;
            queryCounts(v<<1, l, m, L, R, res);
            queryCounts(v<<1|1, m+1, r, L, R, res);
        }
    }

    void collect(int v, int l, int r, string &s) {
        if (t[v].lazy != -1) {
            char ch = char('a' + t[v].lazy);
            for (int i = l; i <= r; ++i) s[i] = ch;
        } else if (l == r) {
            for (int c = 0; c < 26; ++c) {
                if (t[v].cnt[c]) {
                    s[l] = char('a' + c);
                    break;
                }
            }
        } else {
            int m = (l + r) >> 1;
            collect(v<<1, l, m, s);
            collect(v<<1|1, m+1, r, s);
        }
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    string S;
    S.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> S[i];
    }

    SegTree st(n);
    for (int i = 1; i <= n; ++i) {
        st.initLeaf(1, 1, n, i, S[i] - 'a');
    }

    int i, j, k;
    int counts[26];
    for (int qi = 0; qi < q; ++qi) {
        cin >> i >> j >> k;
        for (int c = 0; c < 26; ++c) counts[c] = 0;
        st.queryCounts(1, 1, n, i, j, counts);
        int pos = i;
        if (k == 1) {
            for (int c = 0; c < 26; ++c) {
                if (counts[c] > 0) {
                    st.updateRange(1, 1, n, pos, pos + counts[c] - 1, c);
                    pos += counts[c];
                }
            }
        } else {
            for (int c = 25; c >= 0; --c) {
                if (counts[c] > 0) {
                    st.updateRange(1, 1, n, pos, pos + counts[c] - 1, c);
                    pos += counts[c];
                }
            }
        }
    }

    string result;
    result.resize(n+1);
    st.collect(1, 1, n, result);

    for (int idx = 1; idx <= n; ++idx) {
        cout << result[idx];
    }
    cout << "\n";
    return 0;
}