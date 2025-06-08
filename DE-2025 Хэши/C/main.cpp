#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long u64;
const ll mod1 = 1000000007LL;
const ll mod2 = 1000000009LL;
const ll base = 91138233LL;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> stored(n);
    vector<string> queries(m);
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        cin >> stored[i];
        if ((int)stored[i].size() > maxLen) maxLen = stored[i].size();
    }
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
        if ((int)queries[i].size() > maxLen) maxLen = queries[i].size();
    }

    vector<ll> pow1(maxLen);
    vector<ll> pow2(maxLen);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < maxLen; ++i) {
        pow1[i] = (pow1[i - 1] * base) % mod1;
        pow2[i] = (pow2[i - 1] * base) % mod2;
    }

    unordered_set<u64> fullSet;
    fullSet.reserve(n * 2);
    unordered_map<u64,int> patternCount;
    patternCount.reserve( (size_t)maxLen * 2 );

    for (int i = 0; i < n; ++i) {
        const string &s = stored[i];
        int L = s.size();
        ll h1 = 0, h2 = 0;
        for (int j = 0; j < L; ++j) {
            ll v = s[j] - 'a' + 1;
            h1 = (h1 * base + v) % mod1;
            h2 = (h2 * base + v) % mod2;
        }
        u64 fullKey = (u64)h1 << 32 | (u64)h2;
        if (fullSet.count(fullKey)) continue;
        fullSet.insert(fullKey);
        for (int j = 0; j < L; ++j) {
            ll v = s[j] - 'a' + 1;
            ll m1 = (h1 - v * pow1[j] % mod1 + mod1) % mod1;
            ll m2 = (h2 - v * pow2[j] % mod2 + mod2) % mod2;
            u64 key = (u64)m1 << 32 | (u64)m2;
            ++patternCount[key];
        }
    }

    for (int i = 0; i < m; ++i) {
        const string &s = queries[i];
        int L = s.size();
        ll h1 = 0, h2 = 0;
        for (int j = 0; j < L; ++j) {
            ll v = s[j] - 'a' + 1;
            h1 = (h1 * base + v) % mod1;
            h2 = (h2 * base + v) % mod2;
        }
        u64 fullKey = (u64)h1 << 32 | (u64)h2;
        bool self = fullSet.count(fullKey) > 0;
        bool ok = false;
        for (int j = 0; j < L; ++j) {
            ll v = s[j] - 'a' + 1;
            ll m1 = (h1 - v * pow1[j] % mod1 + mod1) % mod1;
            ll m2 = (h2 - v * pow2[j] % mod2 + mod2) % mod2;
            u64 key = (u64)m1 << 32 | (u64)m2;
            auto it = patternCount.find(key);
            if (it == patternCount.end()) continue;
            int cnt = it->second;
            if (cnt - (self ? 1 : 0) > 0) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
