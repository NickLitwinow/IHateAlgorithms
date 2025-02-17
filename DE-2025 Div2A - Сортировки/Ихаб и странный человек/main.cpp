#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool even = false, odd = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) even = true;
    else odd = true;
  }

  if (even && odd) {
    sort(a.begin(), a.end());
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}