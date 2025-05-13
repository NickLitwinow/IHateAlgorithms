#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree, lazy;

    SegmentTree(int _n): n(_n) {
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void build(int v, int l, int r, const vector<int>& a) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int m = (l + r) / 2;
            build(2*v, l, m, a);
            build(2*v + 1, m+1, r, a);
            tree[v] = max(tree[2*v], tree[2*v + 1]);
        }
    }

    void push(int v) {
        if (lazy[v] != 0) {
            long long add = lazy[v];
            tree[2*v] += add;
            lazy[2*v] += add;
            tree[2*v + 1] += add;
            lazy[2*v + 1] += add;
            lazy[v] = 0;
        }
    }

    void update(int v, int l, int r, int L, int R, long long value) {
        if (L > r || R < l) {
            return;
        }
        if (L <= l && r <= R) {
            tree[v] += value;
            lazy[v] += value;
        } else {
            push(v);
            int m = (l + r) / 2;
            update(2*v, l, m, L, R, value);
            update(2*v + 1, m+1, r, L, R, value);
            tree[v] = max(tree[2*v], tree[2*v + 1]);
        }
    }

    long long query(int v, int l, int r, int L, int R) {
        if (L > r || R < l) {
            return -1e18;
        }
        if (L <= l && r <= R) {
            return tree[v];
        }
        push(v);
        int m = (l + r) / 2;
        long long leftMax  = query(2*v, l, m, L, R);
        long long rightMax = query(2*v + 1, m+1, r, L, R);
        return max(leftMax, rightMax);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    SegmentTree st(N);
    st.build(1, 1, N, a);

    int M;
    cin >> M;
    vector<long long> answers;
    for (int i = 0; i < M; i++) {
        char type;
        cin >> type;
        if (type == 'm') {
            int L, R;
            cin >> L >> R;
            answers.push_back(st.query(1, 1, N, L, R));
        } else if (type == 'a') {
            int L, R;
            long long add;
            cin >> L >> R >> add;
            st.update(1, 1, N, L, R, add);
        }
    }

    for (size_t i = 0; i < answers.size(); i++) {
        cout << answers[i] << "\n";
    }

    return 0;
}