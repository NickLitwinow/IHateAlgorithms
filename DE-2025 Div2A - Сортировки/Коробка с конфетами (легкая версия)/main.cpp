#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  int q;
  cin >> q;
  for (int t = 0; t < q; t++) {
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    vector<int> f;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] > 0)
        f.push_back(cnt[i]);
    }
    sort(f.begin(), f.end(), cmp);

    int last = 1000000000;
    int ans = 0;
    for (int i = 0; i < (int)f.size(); i++) {
      int use = f[i];
      if (use > last - 1)
        use = last - 1;
      if (use < 0)
        use = 0;
      if (use == 0)
        break;
      ans += use;
      last = use;
    }
    cout << ans << "\n";
  }
  return 0;
}