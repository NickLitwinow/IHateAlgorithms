#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Rect {
    int x1, y1, x2, y2;
};

struct SegTree {
    struct Node {
        int maxv, pos;
        int add;
    };
    int n;
    vector<Node> t;
    vector<int> ys;

    SegTree(int _n, const vector<int>& _ys) : n(_n), ys(_ys) {
        t.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int v, int l, int r) {
        t[v].add = 0;
        if (l == r) {
            t[v].maxv = 0;
            t[v].pos = l;
        } else {
            int m = (l + r) >> 1;
            build(v << 1, l, m);
            build(v << 1 | 1, m+1, r);
            if (t[v<<1].maxv >= t[v<<1|1].maxv) {
                t[v].maxv = t[v<<1].maxv;
                t[v].pos = t[v<<1].pos;
            } else {
                t[v].maxv = t[v<<1|1].maxv;
                t[v].pos = t[v<<1|1].pos;
            }
        }
    }

    void apply(int v, int delta) {
        t[v].maxv += delta;
        t[v].add += delta;
    }

    void push(int v) {
        if (t[v].add != 0) {
            apply(v<<1, t[v].add);
            apply(v<<1|1, t[v].add);
            t[v].add = 0;
        }
    }

    void pull(int v) {
        if (t[v<<1].maxv >= t[v<<1|1].maxv) {
            t[v].maxv = t[v<<1].maxv;
            t[v].pos = t[v<<1].pos;
        } else {
            t[v].maxv = t[v<<1|1].maxv;
            t[v].pos = t[v<<1|1].pos;
        }
    }

    void update(int v, int l, int r, int L, int R, int delta) {
        if (R < l || r < L) {
            return;
        }
        if (L <= l && r <= R) {
            apply(v, delta);
        } else {
            push(v);
            int m = (l + r) >> 1;
            update(v<<1, l, m, L, R, delta);
            update(v<<1|1, m+1, r, L, R, delta);
            pull(v);
        }
    }

    pair<int,int> get_max() const {
        return make_pair(t[1].maxv, t[1].pos);
    }
};

int main() {
    int n;
    cin >> n;
    vector<Rect> rects(n);
    vector<int> allY;
    allY.reserve(2 * n);

    for (int i = 0; i < n; ++i) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rects[i].x1 = x1;
        rects[i].y1 = y1;
        rects[i].x2 = x2;
        rects[i].y2 = y2;
        allY.push_back(y1);
        allY.push_back(y2);
    }

    sort(allY.begin(), allY.end());
    allY.erase(unique(allY.begin(), allY.end()), allY.end());
    int m = allY.size();

    map<int, vector< pair<int,int> > > addEv, remEv;

    for (int i = 0; i < n; ++i) {
        int x1 = rects[i].x1;
        int y1 = rects[i].y1;
        int x2 = rects[i].x2;
        int y2 = rects[i].y2;
        int cy1 = int(lower_bound(allY.begin(), allY.end(), y1) - allY.begin());
        int cy2 = int(lower_bound(allY.begin(), allY.end(), y2) - allY.begin());
        addEv[x1].push_back(make_pair(cy1, cy2));
        remEv[x2].push_back(make_pair(cy1, cy2));
    }

    vector<int> xs;
    xs.reserve(addEv.size() + remEv.size());
    {
        map<int, vector< pair<int,int> > >::iterator it;
        for (it = addEv.begin(); it != addEv.end(); ++it) {
            xs.push_back(it->first);
        }
        for (it = remEv.begin(); it != remEv.end(); ++it) {
            xs.push_back(it->first);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    SegTree st(m, allY);

    int bestCnt = 0;
    int bestX = 0;
    int bestY = 0;

    for (size_t ix = 0; ix < xs.size(); ++ix) {
        int x = xs[ix];
        if (addEv.count(x)) {
            vector< pair<int,int> >& vadd = addEv[x];
            for (size_t j = 0; j < vadd.size(); ++j) {
                int l = vadd[j].first;
                int r = vadd[j].second;
                st.update(1, 0, m-1, l, r, +1);
            }
        }
        pair<int,int> cur = st.get_max();
        if (cur.first > bestCnt) {
            bestCnt = cur.first;
            bestX = x;
            bestY = allY[cur.second];
        }
        if (remEv.count(x)) {
            vector< pair<int,int> >& vrem = remEv[x];
            for (size_t j = 0; j < vrem.size(); ++j) {
                int l = vrem[j].first;
                int r = vrem[j].second;
                st.update(1, 0, m-1, l, r, -1);
            }
        }
    }

    cout << bestCnt << "\n";
    cout << bestX << " " << bestY << "\n";

    return 0;
}