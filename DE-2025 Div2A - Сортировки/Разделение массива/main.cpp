#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if(k >= n) {
    cout << 0 << endl;
    return 0;
  }

  vector<long long> diffs;
  for (int i = 1; i < n; i++) {
    diffs.push_back(a[i] - a[i-1]);
  }

  sort(diffs.begin(), diffs.end(), greater<long long>());

  long long total = a[n-1] - a[0];
  for (int i = 0; i < k - 1; i++) {
    total -= diffs[i];
  }

  cout << total << endl;
  return 0;
}