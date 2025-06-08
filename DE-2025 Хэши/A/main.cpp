#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 1000000009LL;
const ll base1 = 91138233LL;
const ll base2 = 97266353LL;
const unsigned long long base3 = 1315423911ULL;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> h1(n+1), h2(n+1), p1(n+1), p2(n+1);
    vector<unsigned long long> h3(n+1), p3(n+1);
    p1[0] = p2[0] = 1;
    p3[0] = 1ULL;
    for (int i = 1; i <= n; ++i) {
        p1[i] = (p1[i-1] * base1) % mod1;
        p2[i] = (p2[i-1] * base2) % mod2;
        p3[i] = p3[i-1] * base3;
        ll v = s[i-1] - 'a' + 1;
        h1[i] = (h1[i-1] * base1 + v) % mod1;
        h2[i] = (h2[i-1] * base2 + v) % mod2;
        h3[i] = h3[i-1] * base3 + v;
    }

    int m;
    cin >> m;
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int len1 = b - a + 1;
        int len2 = d - c + 1;
        if (len1 != len2) {
            cout << "No\n";
            continue;
        }
        int len = len1;
        ll x1 = (h1[b] - h1[a-1] * p1[len] % mod1 + mod1) % mod1;
        ll y1 = (h1[d] - h1[c-1] * p1[len] % mod1 + mod1) % mod1;
        ll x2 = (h2[b] - h2[a-1] * p2[len] % mod2 + mod2) % mod2;
        ll y2 = (h2[d] - h2[c-1] * p2[len] % mod2 + mod2) % mod2;
        unsigned long long x3 = h3[b] - h3[a-1] * p3[len];
        unsigned long long y3 = h3[d] - h3[c-1] * p3[len];
        if (x1 == y1 && x2 == y2 && x3 == y3)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
