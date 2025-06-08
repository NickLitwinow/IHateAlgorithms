#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>

using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 1000000009LL;
const ll base = 31LL;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<ll> h1a(n+1), h2a(n+1), h1b(n+1), h2b(n+1), p1(n+1), p2(n+1);
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p1[i] = (p1[i-1] * base) % mod1;
        p2[i] = (p2[i-1] * base) % mod2;
        h1a[i] = (h1a[i-1] * base + (a[i-1] - 'A' + 1)) % mod1;
        h2a[i] = (h2a[i-1] * base + (a[i-1] - 'A' + 1)) % mod2;
        h1b[i] = (h1b[i-1] * base + (b[i-1] - 'A' + 1)) % mod1;
        h2b[i] = (h2b[i-1] * base + (b[i-1] - 'A' + 1)) % mod2;
    }

    unordered_map<uint64_t,int> mp;
    mp.max_load_factor(0.25f);
    mp.reserve(n);

    int bestLen = 0, bestPos = 0;
    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) >> 1;
        mp.clear();
        for (int i = 1; i + mid - 1 <= n; ++i) {
            ll x1 = (h1a[i+mid-1] - h1a[i-1]*p1[mid] % mod1 + mod1) % mod1;
            ll x2 = (h2a[i+mid-1] - h2a[i-1]*p2[mid] % mod2 + mod2) % mod2;
            uint64_t key = (uint64_t(x1) << 32) | uint64_t(x2);
            if (mp.find(key) == mp.end()) mp[key] = i-1;
        }
        int pos = -1;
        for (int j = 1; j + mid - 1 <= n; ++j) {
            ll y1 = (h1b[j+mid-1] - h1b[j-1]*p1[mid] % mod1 + mod1) % mod1;
            ll y2 = (h2b[j+mid-1] - h2b[j-1]*p2[mid] % mod2 + mod2) % mod2;
            uint64_t key = (uint64_t(y1) << 32) | uint64_t(y2);
            auto it = mp.find(key);
            if (it != mp.end()) {
                pos = it->second;
                break;
            }
        }
        if (pos != -1) {
            bestLen = mid;
            bestPos = pos;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << a.substr(bestPos, bestLen);
    return 0;
}