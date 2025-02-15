#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  int median_index = n / 2;
  for (int i = median_index; i < n - 1 && k > 0; i++) {
    int next_value = a[i + 1];
    int diff = next_value - a[i];
    int steps = min(diff * (i - median_index + 1), k);
    a[i] += steps / (i - median_index + 1);
    k -= steps;
  }
  a[median_index] += k / (n - median_index);
  cout << a[median_index] << endl;
  return 0;
}