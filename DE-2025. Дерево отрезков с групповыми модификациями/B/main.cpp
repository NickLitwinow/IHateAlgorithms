#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree;
    vector<long long> lazyVal;
    vector<bool> lazyFlag;

    SegmentTree(int _n): n(_n) {
        tree.assign(4*n, 0);
        lazyVal.assign(4*n, 0);
        lazyFlag.assign(4*n, false);
    }

    void applyAssign(int v, int len, long long value) {
        tree[v] = value * len;
        lazyVal[v] = value;
        lazyFlag[v] = true;
    }

    void push(int v, int l, int r) {
        if (!lazyFlag[v]) return;
        int m = (l + r) >> 1;
        int leftLen  = m - l + 1;
        int rightLen = r - m;
        applyAssign(v<<1, leftLen, lazyVal[v]);
        applyAssign(v<<1|1, rightLen, lazyVal[v]);
        lazyFlag[v] = false;
    }

    void update(int v, int l, int r, int L, int R, long long value) {
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            applyAssign(v, r - l + 1, value);
        } else {
            push(v, l, r);
            int m = (l + r) >> 1;
            update(v<<1, l, m, L, R, value);
            update(v<<1|1, m+1, r, L, R, value);
            tree[v] = tree[v<<1] + tree[v<<1|1];
        }
    }

    long long query(int v, int l, int r, int L, int R) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) {
            return tree[v];
        }
        push(v, l, r);
        int m = (l + r) >> 1;
        return query(v<<1,     l,   m, L, R)
             + query(v<<1|1, m+1,   r, L, R);
    }
};

int main(){
    int N, K;
    cin >> N >> K;
    SegmentTree st(N);

    for(int i = 0; i < K; i++){
        char type;
        cin >> type;
        if(type == 'A'){
            int l, r;
            long long x;
            cin >> l >> r >> x;
            st.update(1, 1, N, l, r, x);
        }
        else if(type == 'Q'){
            int l, r;
            cin >> l >> r;
            long long ans = st.query(1, 1, N, l, r);
            cout << ans << "\n";
        }
    }

    return 0;
}