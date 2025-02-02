#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  vector<int> a(n), b(k);
  for (int i=0; i<n; i++) {
    cin>>a[i];
  }
  for (int i=0; i<k; i++) {
    cin>>b[i];
  }
  sort(b.rbegin(), b.rend());
  int idx = 0;
  for (int i=0; i<n; i++) {
    if (a[i] == 0) {
      a[i] = b[idx++];
    }
  }
  bool check = true;
  for (int i=1; i<n; i++) {
    if (a[i] <= a[i-1]) {
      check = false;
      break;
    }
  }
  if (check) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}