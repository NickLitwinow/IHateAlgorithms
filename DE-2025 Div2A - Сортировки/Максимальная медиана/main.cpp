#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  int median_index = n / 2;
  long long current = a[median_index];
  int count = 1;

  for (int i = median_index + 1; i < n && k > 0; i++) {
    long long diff = a[i] - current;
    if (diff * count <= k) {
      k -= diff * count;
      current = a[i];
      count++;
    } else {
      current += k / count;
      k = 0;
      break;
    }
  }
  if (k > 0) {
    current += k / count;
  }

  cout << current << endl;
  return 0;
}